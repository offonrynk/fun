#include "records.h"
#include "student.h"
#include <algorithm>

Records::Records() {}

Records::~Records() {}

void Records::addRecord(Student *student)
{
  studentRecord.push_back(student);
}

std::vector<Student *> Records::listRecords() const
{
  return studentRecord;
}
#include <iostream>
void Records::modifyRecords(Student *student)
{
  // Student m_student();
  // Student m_student(name);
  // m_student.addName();
  // m_student.addMajor();
  // m_student.addCourses();
  auto l_record =
      std::find(std::begin(studentRecord), std::end(studentRecord), student);
  /*TODO: Implement method to modify records */
   if (l_record == studentRecord.end())
    std::cout << "Records Not Found for: " << student->getName() << '\n';
}

std::vector<Student *> searchRecords()
{
  /* TODO: Implement search method*/
  return {};
}

void Records::deleteRecords(Student *student)
{
  auto l_record =
      std::find(std::begin(studentRecord), std::end(studentRecord), student);
  studentRecord.erase(l_record);
}
