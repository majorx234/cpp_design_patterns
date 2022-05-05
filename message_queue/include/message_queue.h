#ifndef MESSAGE_QUEUE_H_
#define MESSAGE_QUEUE_H_

#include <queue>
#include <map>
#include <condition_variable>
#include <mutex>
#include <optional>

#include "msg.h"
#include "request.h"

class MessageQueue
{
public:
  MessageQueue();

  ~MessageQueue();

  void put(std::unique_ptr<Msg> msg);

  std::unique_ptr<Msg> get();
  std::optional<std::unique_ptr<Msg>> tryGet();
  std::optional<std::unique_ptr<Msg>> register_request(Request::MsgID,int timeoutMillis = 0);
  bool respond_to_request(Request::MsgID req_id, std::unique_ptr<Msg> responseMsg);

 private:
  std::queue<std::unique_ptr<Msg>> queue_;
  std::mutex queue_mutex_;
  std::condition_variable queue_cond_;
  std::map<Request::MsgID, Request*> response_map_;
  std::mutex response_map_mutex_;  
};

#endif // MESSAGE_QUEUE_H_
