#ifndef RECORDS_H
#define RECORDS_H

#include "student.h"
#include <vector>

class Records {
public:
  enum class EModifyCourses { ADD = 0, REPLACE, REMOVE };

  Records() = default;
  ~Records() = default;

  void addRecord(Student *student);
  std::vector<Student *> listRecords() const;

  void modifyStudentName(Student *student, const std::string &currentName,
                         const std::string &newName);

  void modifyStudentMajor(Student *student, const std::string &currentMajor,
                          const std::string &newMajor);

  void modifyStudentCourses(Student *student, Records::EModifyCourses action,
                            const std::string &currCourses,
                            const std::string &newCourses);

  std::vector<Student *> searchRecordsByName(const std::string &name);
  std::vector<Student *> searchRecordsByCourse(const std::string &course);
  std::vector<Student *> searchRecordsByMajor(const std::string &major);

  void deleteRecords(Student *student);

private:
  std::vector<Student *> studentRecord;
};

#endif
