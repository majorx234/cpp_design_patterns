#include "msg.h"
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

Msg::~Msg(){
    
}

std::unique_ptr<Msg> Msg::move()
{
    return std::unique_ptr<Msg>(new Msg(std::move(*this)));
}
