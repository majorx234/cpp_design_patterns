#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <future>
#include "message_queue.h"

std::atomic<bool> alive = true;


void server_function(MessageQueue &my_queue, std::promise<Request::MsgID> &prom) {
  while (alive) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  }
}

void client_function(MessageQueue &my_queue, std::promise<Request::MsgID> &prom) {
  while (alive) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
  }  
}

int main(){
  MessageQueue my_queue;
  std::promise<Request::MsgID> prom_msg_id;
  std::thread server_thread(server_function, my_queue, prom_msg_id);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::thread client_thread(client_function, my_queue, prom_msg_id);

  std::this_thread::sleep_for(std::chrono::seconds(6));
  alive = false;
  client_thread.join();
  server_thread.join();

  return 0;
}
