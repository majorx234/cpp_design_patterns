#include "ringbuffer.h"
#include <cstring>

RingBuffer::RingBuffer(std::size_t size, bool over_write)
  : over_write_(over_write)
  , head(0)
  , tail(0)
  , count(0)
  , buf_size(size)
  , array(nullptr)
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

void RingBuffer::operator=(const RingBuffer& right_side) {
  if(array)
    delete [] array;
  over_write_ = right_side.over_write_;
  head = right_side.head;
  tail = right_side.tail;
  count = right_side.count;
  buf_size = right_side.buf_size;
  array = new int[buf_size];
  std::memcpy(array, right_side.array,buf_size*sizeof(int));
}

void RingBuffer::operator=(RingBuffer& right_side) {
  if(array)
    delete [] array;
  over_write_ = right_side.over_write_;
  head = right_side.head;
  tail = right_side.tail;
  count = right_side.count;
  buf_size = right_side.buf_size;
  array = new int[buf_size];
  std::memcpy(array, right_side.array,buf_size*sizeof(int));  
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

int& RingBuffer::operator[](int index) {
  if (count==0) return array[0];
  // correct modulo (b + (a%b)) % b
  int mod_index = (count + (index % count)) % count;
  size_t ring_index = (mod_index + head) % buf_size;
  return array[mod_index];
}

const int& RingBuffer::operator[](int index) const {
  if (count==0) return array[0];
  int mod_index = (count + (index % count)) % count;
  size_t ring_index = (mod_index + head) % buf_size;
  return array[mod_index];
}
