#include "StudentModel.h"

#include <algorithm>
#include <vector>

StudentModel::StudentModel(){
  name_ = "";
  roll_no_ = "";
}
StudentModel::StudentModel(std::string name, std::string roll_no)
  : name_(name)
  , roll_no_(roll_no)
{
}

StudentModel::~StudentModel(){}

std::string StudentModel::getName(){
  return name_;
}

void StudentModel::setName(std::string name){
  name_ = name;
  notify();
} 

std::string StudentModel::getRollNo(){
  return roll_no_;
}

void StudentModel::setRollNo(std::string roll_no){
  roll_no_ = roll_no;
  notify();
} 

bool StudentModel::notify(){
  bool ret = false;
  for(Observer* observer : observer_list_) {
    if(observer) {
      ret = observer->update(this);
    }
  }
  return ret;
}

int StudentModel::attach(Observer* new_observer){
  observer_list_.push_back(new_observer);
  return observer_list_.size();
}
int StudentModel::detach(Observer* rm_observer){
  observer_list_.erase(std::remove_if(observer_list_.begin(), observer_list_.end(), [&](Observer* a){return a == rm_observer;}), observer_list_.end());
}
