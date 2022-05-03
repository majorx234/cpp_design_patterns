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
