#ifndef STUDENT_MODEL_H_
#define STUDENT_MODEL_H_

#include <string>
#include "StudentModelInterface.h"
#include "Subject.h"

class StudentModel: public StudentModelInterface, public Subject
{
 public:
  StudentModel();
  StudentModel(std::string name, std::string roll_no);
  ~StudentModel();

  std::string getName() override;
  void setName(std::string name) override; 
  std::string getRollNo() override;
  void setRollNo(std::string roll_no) override; 

  int attach(Observer* new_observer) override;
  int detach(Observer* rm_observer) override;
 protected: 
  std::vector<Observer*> observer_list_;
 private:
  bool notify() override;
  std::string roll_no_;
  std::string name_;

};

#endif // STUDENT_MODEL_H_