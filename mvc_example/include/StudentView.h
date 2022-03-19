#ifndef STUDENT_VIEW_H_
#define STUDENT_VIEW_H_

#include <string>
#include <Observer.h>

class StudentView: public Observer
{
 public: 
  bool update(StudentModelInterface* student) override;
  void printStudentDetails(std::string studentName, std::string studentRollNo);
};

#endif // STUDENT_VIEW_H_