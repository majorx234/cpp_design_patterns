#include "message_queue.h"

MessageQueue::MessageQueue(){

}

MessageQueue::~MessageQueue(){

}

void MessageQueue::put(Msg* msg){
  {
    std::lock_guard<std::mutex> lock(queue_mutex_);
    queue_.push(msg);
  }
  queue_cond_.notify_one();
}

Msg* MessageQueue::get(){

}

Msg* MessageQueue::tryGet(){
	
}