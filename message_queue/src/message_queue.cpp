#include "message_queue.h"

MessageQueue::MessageQueue()
  : queue_()
  , queue_mutex_()
  , queue_cond_()
{

}

MessageQueue::~MessageQueue() {

}

void MessageQueue::put(std::unique_ptr<Msg> msg) {
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    queue_.push(msg->move());
  }
  queue_cond_.notify_one();
}

std::unique_ptr<Msg> MessageQueue::get() {
  std::unique_lock<std::mutex> lock(queue_mutex_);
  queue_cond_.wait(lock, [this]{return !queue_.empty();});
  auto last_msg = queue_.front()->move();
  queue_.pop(); 
  return last_msg;
}

std::optional<std::unique_ptr<Msg>> MessageQueue::tryGet() {
  std::unique_lock<std::mutex> lock(queue_mutex_);
  if (!queue_.empty()) {
    auto last_msg = queue_.front()->move();
    queue_.pop();
    return std::optional<std::unique_ptr<Msg>>{last_msg->move()};
  }
  else
    return std::nullopt;
}


std::optional<std::unique_ptr<Msg>> MessageQueue::register_request(Request::MsgID req_id,int timeout_ms){
  Request req;
  std::unique_lock<std::mutex> lock(response_map_mutex_);
  auto it = response_map_.emplace(
      std::make_pair(req_id, &req)).first;
  if (timeout_ms <= 0)
    req.cv_.wait(lock,[&req]{
      return req.response_msg_.get();}
      );
  else {
    auto timeout_occured = !req.cv_.wait_for(
        lock,
        std::chrono::milliseconds(timeout_ms),
        [&req] {
          return req.response_msg_.get();
        }
    );
    if( timeout_occured)
    {
      response_map_.erase(it);
      return std::nullopt;
    }
  }

  auto response = std::move(it->second->response_msg_);
  response_map_.erase(it);
  return response->move();
}

bool MessageQueue::respond_to_request(Request::MsgID req_id, std::unique_ptr<Msg> response_msg){
  // WIP
  std::unique_lock<std::mutex> lock(response_map_mutex_);
  auto it = response_map_.find(req_id);
  if(it == response_map_.end())
    return false;
  it->second->response_msg_ = response_msg->move();
  it->second->cv_.notify_one();
  return true;
}
