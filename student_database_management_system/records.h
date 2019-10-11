#ifndef RECORDS_H
#define RECORDS_H

#include "student.h"
#include <vector>

class Records {
public:
  enum class EModifyCourses { ADD = 0, REPLACE, REMOVE };

  Records();
  ~Records();

  void addRecord(Student *student);
  std::vector<Student *> listRecords() const;

  void modifyStudentName(Student *student, const std::string &currentName,
                         const std::string &newName);

  void modifyStudentMajor(Student *student, const std::string &currentMajor,
                          const std::string &newMajor);

  void modifyStudentCourses(Student *student, Records::EModifyCourses action,
                            const std::string &currCourses,
                            const std::string &newCourses);

  void deleteRecords(Student *student);
  std::vector<Student *> searchRecords();

private:
  std::vector<Student *> studentRecord;
};

#endif
