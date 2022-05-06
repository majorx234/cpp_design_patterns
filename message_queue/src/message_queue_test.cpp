#include <iostream>
#include "message_queue.h"

int main(){
  MessageQueue my_queue;
 
  auto msg1 = std::make_unique<Msg>("hello");           

  auto msg2 = std::make_unique<Msg>("send");

  auto msg3 = std::make_unique<Msg>("messages");

  auto msg4 = std::make_unique<Msg>("in order");

  auto msg5 = std::make_unique<Msg>("good bye");

  my_queue.put(msg1->move());
  my_queue.put(msg2->move());
  my_queue.put(msg3->move());
  my_queue.put(msg4->move());
  my_queue.put(msg5->move());

  while(true){
    auto msg_opt = my_queue.get();
    if(!msg_opt) break;
    std::cout << msg_opt->data << std::endl;
  }
}
