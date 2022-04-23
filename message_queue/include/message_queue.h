#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include "msg.h"

class MessageQueue
{
public:
  MessageQueue();

  ~MessageQueue();

  void put(Msg* msg);

  Msg get();
  Msg tryGet();
};

#endif // MESSAGE_QUEUE_H_