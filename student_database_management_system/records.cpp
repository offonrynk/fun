#include "records.h"
#include "student.h"
#include <algorithm>
#include <iostream>

void Records::addRecord(Student *student)
{
  studentRecord.push_back(student);
}

std::vector<Student *> Records::listRecords() const
{
  return studentRecord;
}

void Records::modifyStudentName(Student *student,
                                const std::string &currentName,
                                const std::string &newName)
{
  if (find(studentRecord.begin(), studentRecord.end(), student) !=
      studentRecord.end()) {
    const std::string l_curName = student->getName();
    if (l_curName == currentName) {
      student->addName(newName);
    }
  }
}

void Records::modifyStudentMajor(Student *student,
                                 const std::string &currentMajor,
                                 const std::string &newMajor)
{
  if (find(studentRecord.begin(), studentRecord.end(), student) !=
      studentRecord.end()) {
    const std::string l_curMajor = student->getMajorProgram();
    if (l_curMajor == currentMajor) {
      student->addMajor(newMajor);
    }
  }
}

void Records::modifyStudentCourses(Student *student,
                                   Records::EModifyCourses action,
                                   const std::string &currCourses,
                                   const std::string &newCourses)
{
  std::string l_courses;

  if (find(studentRecord.begin(), studentRecord.end(), student) !=
      studentRecord.end()) {
    l_courses = student->getCourses();
  }

  // clang-format off
  const std::size_t commaPositionBeforeCourse = l_courses.find(", " + currCourses);
  const std::size_t commaPositionAfterCourse  = l_courses.find(currCourses + ", ");
        std::string stringOfNewCourses        = ", " + newCourses;
  // clang-format on

  switch (action) {
    case EModifyCourses::ADD:
      l_courses.append(stringOfNewCourses);
      student->addCourses(l_courses);
      break;

    case EModifyCourses::REPLACE:
      if (commaPositionAfterCourse != std::string::npos) {
        // if "course + ," (eg. Mat101, .... ) found then erase it from string
        // add 2 cause of the comma and space literal(s)
        l_courses.erase(commaPositionAfterCourse, (currCourses.length() + 2));
      }
      else if (commaPositionBeforeCourse != std::string::npos) {
        // if ", + course" (eg... , Mat101) found then erase it from string
        l_courses.erase(commaPositionBeforeCourse, (currCourses.length() + 2));
      }

      else {
        stringOfNewCourses.erase();
      }

      student->addCourses(l_courses + stringOfNewCourses);
      break;

    case EModifyCourses::REMOVE:
      if (commaPositionAfterCourse != std::string::npos) {
        l_courses.erase(commaPositionAfterCourse, (currCourses.length() + 2));
      }
      else if (commaPositionBeforeCourse != std::string::npos) {
        l_courses.erase(commaPositionBeforeCourse, (currCourses.length() + 2));
      }

      student->addCourses(l_courses);
      break;

    default:
      std::cout << "No Modification Action Selected" << std::endl;
      break;
  }
}

// clang-format off
std::vector<Student *> Records::searchRecordsByCourse(const std::string &course)
{
  std::vector<Student *> l_student;
  for (const auto &it : studentRecord) {
    // get all courses and search for course given as input
    const std::string l_courses     = it->getCourses();
          std::string::size_type n  = l_courses.find(course);

    if (n != std::string::npos)
    {
      // if course is found, add student(s) taking the course to local vector
      // of Student*
      l_student.push_back(it);
    }
  }
  return l_student;
}

std::vector<Student *> Records::searchRecordsByName(const std::string &name)
{
  std::vector<Student *> l_student;
  for (auto it : studentRecord) {
    if (it->getName() == name)
    {
      l_student.push_back(it);
    }
  }
  return l_student;
}

std::vector<Student *> Records::searchRecordsByMajor(const std::string &major)
{
  std::vector<Student *> l_student;
  for (auto it : studentRecord) {
    if (it->getMajorProgram() == major)
    {
      l_student.push_back(it);
    }
  }
  return l_student;
}
// clang-format on

void Records::deleteRecords(Student *student)
{
  auto l_record =
      std::find(std::begin(studentRecord), std::end(studentRecord), student);
  studentRecord.erase(l_record);
}
