#include "StudentView.h"
#include <stdio.h>


bool StudentView::update(StudentModelInterface* student){
  if(student){
    std::string name = student->getName();
    std::string roll_no = student->getRollNo();
    printStudentDetails(name,roll_no);
    return true;
  }
  return false;
}

void StudentView::printStudentDetails(std::string studentName, std::string studentRollNo){
  printf("Student:\n");
  printf("%s\n", studentName.c_str());
  printf("%s\n",studentRollNo.c_str());
}

