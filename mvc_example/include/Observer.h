#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>
#include "StudentModelInterface.h"

class Observer
{
 public: 
  virtual bool update(StudentModelInterface* student) = 0;
};

#endif // OBSERVER_H_