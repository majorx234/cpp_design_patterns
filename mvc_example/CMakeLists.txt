cmake_minimum_required(VERSION 3.16)
project(students_mvc_example
  DESCRIPTION "an example how to implement mvc"
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STUDENT_MODEL_HEADERS
  include/StudentModel.h
  )

set(STUDENT_MODEL_SOURCES
  src/StudentModel.cpp
)

set(STUDENT_VIEW_HEADERS
  include/StudentView.h
  )

set(STUDENT_VIEW_SOURCES
  src/StudentView.cpp
)

set(STUDENT_CONTROLLER_HEADERS
  include/StudentController.h
  )

set(STUDENT_CONTROLLER_SOURCES
  src/StudentController.cpp
)

set(MAIN_NVC_TEST_SOURCES
  src/main_mvc_test.cpp
)

add_library(student_model
  ${STUDENT_MODEL_HEADERS}
  ${STUDENT_MODEL_SOURCES}
)

target_sources(student_model PRIVATE
  ${STUDENT_MODEL_HEADERS}
  ${STUDENT_MODEL_SOURCES}
)

target_include_directories(student_model PRIVATE include)

add_library(student_view
  ${STUDENT_VIEW_HEADERS}
  ${STUDENT_VIEW_SOURCES}
)

target_sources(student_view PRIVATE
  ${STUDENT_VIEW_HEADERS}
  ${STUDENT_VIEW_SOURCES}
)

target_include_directories(student_view PRIVATE include)

add_library(student_controller
  ${STUDENT_CONTROLLER_HEADERS}
  ${STUDENT_CONTROLLER_SOURCES}
)

target_sources(student_controller PRIVATE
  ${STUDENT_CONTROLLER_HEADERS}
  ${STUDENT_CONTROLLER_SOURCES}
)

target_include_directories(student_controller PRIVATE include)

add_executable(main_mvc_test
    ${MAIN_NVC_TEST_SOURCES}
)

target_sources(main_mvc_test PRIVATE
    ${MAIN_NVC_TEST_SOURCES}
)

target_include_directories(main_mvc_test PRIVATE include)
target_link_libraries(main_mvc_test
    student_model
    student_view
    student_controller
)