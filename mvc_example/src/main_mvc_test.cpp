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

  delete student_controller;
  delete my_students_view;
  delete my_student;

  return 0;
}