#ifndef REQUEST_H_
#define REQUEST_H_

#include <memory>
#include <condition_variable>
#include "msg.h"

struct Request{
  enum MsgID{
    unknown = 0,
    msg_type1,
    msgs_type2
  }msg_id_;

  std::unique_ptr<Msg> response_msg_;
  std::condition_variable cv_;
};

#endif REQUEST_H_
