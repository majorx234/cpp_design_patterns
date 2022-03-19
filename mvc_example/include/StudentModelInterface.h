#ifndef STUDENT_MODEL_INTERFACE_H_
#define STUDENT_MODEL_INTERFACE_H_

#include <string>

class StudentModelInterface
{
 public: 
  virtual std::string getName() = 0;
  virtual void setName(std::string name) = 0; 
  virtual std::string getRollNo() = 0;
  virtual void setRollNo(std::string roll_no) = 0; 
};

#endif // STUDENT_MODEL_INTERFACE_H_