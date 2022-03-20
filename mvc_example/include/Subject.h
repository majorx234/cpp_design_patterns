#ifndef SUBJECT_H_
#define SUBJECT_H_

#include "Observer.h"

class Subject {
  virtual bool notify() = 0;

 public:
  virtual int attach(Observer* new_observer) = 0;
  virtual int detach(Observer* rm_observer) = 0;
};
#endif // SUBJECT_H_