#include "msg.h"

std::unique_ptr<Msg> Msg::move()
{
    return std::unique_ptr<Msg>(new Msg(std::move(*this)));
}
