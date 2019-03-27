#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
  Student(const std::string &studentName);
  ~Student();
  void addName(const std::string &studentName);
  void addMajor(const std::string &stdudyProgram);
  void addCourses(const std::string &course);

  std::string getName() const ;
  std::string getRegNum() const;
  std::string majorProgram() const;
  std::string getCourses() const;

private:
  std::string name;
  std::string regNum;
  std::string major;
  std::string courses;
};

#endif
