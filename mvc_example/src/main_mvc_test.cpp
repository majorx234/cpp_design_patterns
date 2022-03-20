#include "StudentModel.h"
#include "StudentView.h"
#include "StudentController.h"

int main(int argc, char const *argv[])
{
  StudentModel* my_student = new StudentModel("Heinz","123");
  StudentView* my_students_view = new StudentView();
  my_student->attach(my_students_view);
  StudentController* student_controller = new StudentController(my_student,my_students_view);

  student_controller->updateView();
  student_controller->setStudentName("Horst");
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  student_controller->setStudentName("foo");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  student_controller->setStudentName("bar");
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  student_controller->setStudentName("bla");
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  
  delete student_controller;
  delete my_students_view;
  delete my_student;
  return 0;
}