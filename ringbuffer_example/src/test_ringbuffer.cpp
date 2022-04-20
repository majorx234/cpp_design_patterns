#include <iostream>
#include <memory>
#include <string>
#include "ringbuffer.h"

int main(int argc, char const *argv[])
{
  auto test_ring_buffer = std::make_shared<RingBuffer>(10,true);
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
  
  // create for copy-ctor test a second buffer
  auto test_ring_buffer2 = std::make_shared<RingBuffer>(*test_ring_buffer);
  std::cout << "ringbuf2 created" << std::endl; 


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

  std::cout << "test copy ctor:" << std::endl;

  for (int i = 0; i < 8; ++i)
  {
    if(auto value = test_ring_buffer2->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer2->pop(); 
  }

  for (int i = 20; i < 30; ++i)
  {
    test_ring_buffer2->push(i); 
  }

  for (int i = 0; i < 11; ++i)
  {
    if(auto value = test_ring_buffer2->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer2->pop(); 
  }

  for (int i = 30; i < 40; ++i)
  {
    test_ring_buffer2->push(i); 
  }

  for (int i = 0; i < 11; ++i)
  {
    if(auto value = test_ring_buffer2->top())
      std::cout << "value: " << *value << std::endl;
    else
      std::cout << "empty" << std::endl;
    test_ring_buffer2->pop(); 
  }

  return 0;
}
