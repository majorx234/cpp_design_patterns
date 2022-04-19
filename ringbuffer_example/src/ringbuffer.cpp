#include "ringbuffer.h"

RingBuffer::RingBuffer(std::size_t size){
  array = new int[size];
  head = 0;
  tail = 0;
  count = 0;
  buf_size = size;
}

RingBuffer::~RingBuffer() {
  delete [] array;
}

std::size_t RingBuffer::size() const {
  return buf_size;
}

bool RingBuffer::empty(){
  if(!count)
    return true;
  return false;
}

std::optional<int> RingBuffer::top(){
  return head!=tail ? std::optional<int>(array[head]) : std::nullopt;
}

void RingBuffer::pop(){
  if(head==tail)
    return;
  if(head < buf_size-1) 
    head++;
  else
    head = 0;
  count--;
}

void RingBuffer::push(int new_value){
  if(count < buf_size-1){
    array[tail++]=new_value;
    count++;
  }
}