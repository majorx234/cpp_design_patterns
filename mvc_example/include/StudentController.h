#ifndef STUDENT_CONTROLLER_H_
#define STUDENT_CONTROLLER_H_

#include <string>
#include "StudentView.h"
#include "StudentModel.h"

class StudentController {
 private:
  StudentModel* student_model_;
  StudentView* student_view_;

 public:
  StudentController(StudentModel* student_model,StudentView* student_view);
  void setStudentName(std::string name); 
  std::string getStudentName();
  void setStudentRollNo(std::string rollNo);
  std::string getStudentRollNo();
  void updateView();
};
#endif