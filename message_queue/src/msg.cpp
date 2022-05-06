#include "msg.h"
#include <cstring>
#include <string> 
#include <atomic>

unsigned long long generate_unique_id()
{
    static std::atomic<unsigned long long> i(0);
    return ++i;
}

Msg::Msg()
  : unique_Id_(generate_unique_id())
{

}

Msg::Msg(const char* in)
  : unique_Id_(generate_unique_id())
{
  size_t length = std::char_traits<char>::length(in);
  length = (length < 16) ? length : 15;
  memcpy(&data,in,16*sizeof(char));
}

Msg::~Msg(){
    
}

std::unique_ptr<Msg> Msg::move()
{
    return std::unique_ptr<Msg>(new Msg(std::move(*this)));
}
