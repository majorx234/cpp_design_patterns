#include "StudentController.h"

StudentController::StudentController(StudentModel* student_model,StudentView* student_view)
  : student_model_(student_model)
  , student_view_(student_view)
{
    
}

void StudentController::setStudentName(std::string name){
  student_model_->setName(name);
} 
std::string StudentController::getStudentName(){
  return student_model_->getName();
}
void StudentController::setStudentRollNo(std::string rollNo){
  student_model_->setRollNo(rollNo);
}
std::string StudentController::getStudentRollNo(){
  return student_model_->getRollNo();
}
void StudentController::updateView(){
  student_view_->update(student_model_);
}