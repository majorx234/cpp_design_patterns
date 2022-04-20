#include "ringbuffer.h"
#include <cstring>

RingBuffer::RingBuffer(std::size_t size, bool over_write)
  : over_write_(over_write)
  , head(0)
  , tail(0)
  , count(0)
  , buf_size(size)
{
  array = new int[buf_size];
}

RingBuffer::RingBuffer(const RingBuffer& ring_buf)
  : over_write_(ring_buf.over_write_)
  , head(ring_buf.head)
  , tail(ring_buf.tail)
  , count(ring_buf.count)
  , buf_size(ring_buf.buf_size)
{
  array = new int[buf_size];
  std::memcpy(array, ring_buf.array, buf_size*sizeof(int));
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
  return (count>0) ? std::optional<int>(array[head]) : std::nullopt;
}

void RingBuffer::pop(){
  if((head==tail)&&(count==0))
    return;
  if(head < buf_size-1) 
    head++;
  else
    head = 0;
  count--;
}

void RingBuffer::push(int new_value){
  if(count <= buf_size){
    if (count == buf_size) {
      if(!over_write_) return;
      this->pop();
    }
    array[tail] = new_value;
    tail = (++tail) % buf_size;
    count++;
  }  
}