#include "message_queue.h"

MessageQueue::MessageQueue() {

}

MessageQueue::~MessageQueue() {

}

void MessageQueue::put(Msg* msg) {
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    queue_.push(msg);
  }
  queue_cond_.notify_one();
}

Msg* MessageQueue::get() {
  std::unique_lock<std::mutex> lock(queue_mutex_);
  queue_cond_.wait(lock, [this]{return !queue_.empty();});
  Msg* last_msg = queue_.front();
  queue_.pop(); 
  return last_msg;
}

std::optional<Msg*> MessageQueue::tryGet() {
  std::unique_lock<std::mutex> lock(queue_mutex_);
  if (!queue_.empty()) {
    Msg* last_msg = queue_.front();
    queue_.pop();
    return std::optional<Msg*>{last_msg};
  }
  else
    return std::nullopt;
	
}