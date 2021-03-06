#include "student.h"
#include <ctime>

Student::Student(const std::string &studentName)
{
  name = studentName;
  int timeStamp = static_cast<int>(std::time(0));
  auto timeStampString = std::to_string(timeStamp);
  regNum = studentName + timeStampString;
}

void Student::addName(const std::string &studentName)
{
  name = studentName;
}

void Student::addMajor(const std::string &studyProgram)
{
  major = studyProgram;
}

void Student::addCourses(const std::string &course)
{
  courses = course;
}

std::string Student::getName() const
{
  return name;
}

std::string Student::getRegNum() const
{
  return regNum;
}

std::string Student::getMajorProgram() const
{
  return major;
}

std::string Student::getCourses() const
{
  return courses;
}
