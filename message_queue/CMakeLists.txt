cmake_minimum_required(VERSION 3.16)
project(message_queue
  DESCRIPTION "an example how to implement message_queue"
  VERSION 0.0.1
  LANGUAGES CXX)

set(MESSAGE_QUEUE_SOURCES
  src/message_queue.cpp
  include/message_queue.h
  include/msg.h
)

add_library(message_queue
  ${MESSAGE_QUEUE_SOURCES}
)
target_include_directories(message_queue PRIVATE include)