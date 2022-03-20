#ifndef STUDENT_VIEW_H_
#define STUDENT_VIEW_H_

#include <string>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <Observer.h>

class StudentView: public Observer
{
  typedef std::lock_guard<std::mutex> LockGuard;
 private:
  std::mutex mtx;
  std::condition_variable condvar;
  std::atomic<bool> is_alive_;
  bool new_data_;
  std::thread get_updates_thread_;

  std::string student_name_;
  std::string student_roll_no_;

 public: 
  StudentView();
  ~StudentView();
  bool update(StudentModelInterface* student) override;
  void getUpdatedThreadFct();
  void checkUpdate();
  void printStudentDetails(std::string studentName, std::string studentRollNo);
};

#endif // STUDENT_VIEW_H_