#ifndef MSG_H_
#define MSG_H_

#include <memory>

class Msg
{
public:
  Msg();
  ~Msg();
  virtual std::unique_ptr<Msg> move();
  
  unsigned char data[26];
};
#endif // MSG_H_
