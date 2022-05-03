#ifndef MSG_H_
#define MSG_H_

#include <memory>

class Msg
{
public:
  Msg();
  ~Msg();
  virtual std::unique_ptr<Msg> move();
  unsigned long long get_unique_id() const;
  
  unsigned char data[26];
 private:  
  unsigned long long unique_Id_;
};
#endif // MSG_H_
