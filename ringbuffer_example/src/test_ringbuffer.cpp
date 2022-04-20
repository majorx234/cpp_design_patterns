#include <iostream>
#include <memory>
#include <string>
#include "ringbuffer.h"

int main(int argc, char const *argv[])
{
  auto test_ring_buffer = std::make_shared<RingBuffer>(10);
  for (int i = 0; i < 11; ++i)
  {
    test_ring_buffer->push(i); 
  }
  
  for (int i = 0; i < 8; ++i)
  {
    if(auto value = test_ring_buffer->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer->pop(); 
  }

  for (int i = 11; i < 20; ++i)
  {
    test_ring_buffer->push(i); 
  }

  for (int i = 0; i < 8; ++i)
  {
    if(auto value = test_ring_buffer->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer->pop(); 
  }

  for (int i = 20; i < 30; ++i)
  {
    test_ring_buffer->push(i); 
  }

  for (int i = 0; i < 11; ++i)
  {
    if(auto value = test_ring_buffer->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer->pop(); 
  }

  for (int i = 30; i < 40; ++i)
  {
    test_ring_buffer->push(i); 
  }

  for (int i = 0; i < 11; ++i)
  {
    if(auto value = test_ring_buffer->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer->pop(); 
  }
  return 0;
}
