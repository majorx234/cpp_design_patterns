cmake_minimum_required(VERSION 3.16)
project(ringbuffer
  DESCRIPTION "an example how to implement ringbuffer"
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RINGBUFFER_HEADERS
  include/ringbuffer.h
  )

set(RINGBUFFER_SOURCES
  src/ringbuffer.cpp
)

set(TEST_RINGBUFFER_SOURCES
  src/test_ringbuffer.cpp
)

add_library(ringbuffer
  ${RINGBUFFER_HEADERS}
  ${RINGBUFFER_SOURCES}
)
target_sources(ringbuffer 
PRIVATE
  ${RINGBUFFER_SOURCES}
PUBLIC
  ${RINGBUFFER_HEADERS}  
)
target_include_directories(ringbuffer PRIVATE include)


add_executable(test_ringbuffer
  ${TEST_RINGBUFFER_SOURCES}
)
target_include_directories(test_ringbuffer PRIVATE include)
target_link_libraries(test_ringbuffer ringbuffer)