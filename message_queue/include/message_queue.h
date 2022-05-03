#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include <queue>
#include <condition_variable>
#include <mutex>
#include <optional>

#include "msg.h"

class MessageQueue
{
public:
  MessageQueue();

  ~MessageQueue();

  void put(std::unique_ptr<Msg> msg);

  std::unique_ptr<Msg> get();
  std::optional<std::unique_ptr<Msg>> tryGet();

  std::queue<std::unique_ptr<Msg>> queue_;
  std::mutex queue_mutex_;
  std::condition_variable queue_cond_;
};

#endif // MESSAGE_QUEUE_H_