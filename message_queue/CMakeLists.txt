cmake_minimum_required(VERSION 3.16)
project(message_queue
  DESCRIPTION "an example how to implement message_queue"
  VERSION 0.0.1
  LANGUAGES CXX)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(MESSAGE_QUEUE_SOURCES
  src/message_queue.cpp
  include/message_queue.h
  src/msg.cpp
  include/msg.h
	include/request.h
)

add_library(message_queue
	)
target_sources(message_queue
	PRIVATE
	${MESSAGE_QUEUE_SOURCES})
target_include_directories(message_queue PRIVATE include)
target_link_libraries(message_queue
	Threads::Threads)

add_executable(message_queue_test)
target_sources(message_queue_test
  PRIVATE
	src/message_queue_test.cpp)
target_include_directories(message_queue_test
	PRIVATE include)
target_link_libraries(message_queue_test
	message_queue)

add_executable(message_queue_request_test)
target_sources(message_queue_request_test
  PRIVATE
	src/message_queue_test.cpp)
target_include_directories(message_queue_request_test
	PRIVATE include)
target_link_libraries(message_queue_request_test
	message_queue
	Threads::Threads)
