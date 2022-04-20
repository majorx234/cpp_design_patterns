#ifndef RINGEBUFFER_H_ 
#define RINGEBUFFER_H_

#include <cstddef>
#include <optional>

class RingBuffer {
 public:
  enum { default_size = 1024};
  explicit RingBuffer(std::size_t size = default_size,bool over_write = false);
  RingBuffer(const RingBuffer& ring_buf); // copy ctor
  ~RingBuffer();
  std::size_t size() const;
  bool empty();

  std::optional<int> top();
  void pop();
  void push(int new_value);

 private:
  int* array;
  int tail;
  int head;
  unsigned int count;
  std::size_t buf_size;
  bool over_write_;
};

#endif // RINGEBUFFER_H_