#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include "message_queue.h"

void server_function(MessageQueue *my_queue, std::promise<Request::MsgID> *prom) {
    auto future = prom->get_future();
    Request::MsgID id = future.get();
    auto msg = std::make_unique<Msg>("test");
    my_queue->respond_to_request(id, msg->move());
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}

void client_function(MessageQueue *my_queue, std::promise<Request::MsgID> *prom) {
    prom->set_value(Request::MsgID::msg_type1);
    auto msg_opt = my_queue->register_request(Request::MsgID::msg_type1,1500);
    if (msg_opt) {
      std::cout << msg_opt.value()->data << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}

int main(){
  MessageQueue my_queue;
  std::promise<Request::MsgID> prom_msg_id;

  std::thread client_thread(client_function, &my_queue, &prom_msg_id);  
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::thread server_thread(server_function, &my_queue, &prom_msg_id);
  
  client_thread.join();
  server_thread.join();

  return 0;
}
