#include "StudentView.h"
#include <stdio.h>


StudentView::StudentView()
  : new_data_(false)
{
  is_alive_ = true;
  get_updates_thread_ = std::thread(&StudentView::getUpdatedThreadFct,this);
}

StudentView::~StudentView() {
  is_alive_ = false;
  get_updates_thread_.join();
}

bool StudentView::update(StudentModelInterface* student){
  if(student){
    std::lock_guard<std::mutex> lock(mtx);
    student_name_ = student->getName();
    student_roll_no_ = student->getRollNo();
    new_data_ = true;
    condvar.notify_all();
    return true;
  }
  return false;
}

void StudentView::getUpdatedThreadFct() {
  bool data_set = false;
  while (is_alive_) {
    std::string name_tmp;
    std::string roll_no_tmp;
    {
      std::unique_lock<std::mutex> lock(mtx);
      if(!new_data_){
        while(condvar.wait_for(lock,std::chrono::seconds(1)) == std::cv_status::timeout) {
          if(!is_alive_){
            return;
          }
        }
      }
      if(new_data_) {
        new_data_ = false; // no more data
        name_tmp = student_name_;
        roll_no_tmp = student_roll_no_;
        data_set = true;
      }
    }
    if(data_set){
      printStudentDetails(name_tmp,roll_no_tmp);
      data_set = false;
    } 
  }
  printf("thread end\n");
}

void StudentView::checkUpdate() {
  std::string name_tmp;
  std::string roll_no_tmp;
  {  
    std::unique_lock<std::mutex> lock(mtx);
    if(new_data_) {
      new_data_ = false;
      name_tmp = student_name_;
      roll_no_tmp = student_roll_no_;      
    }
  }
  printStudentDetails(name_tmp,roll_no_tmp); 
}

void StudentView::printStudentDetails(std::string studentName, std::string studentRollNo){
  printf("Student:\n");
  printf("%s\n", studentName.c_str());
  printf("%s\n",studentRollNo.c_str());
}

