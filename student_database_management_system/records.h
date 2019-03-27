#ifndef RECORDS_H
#define RECORDS_H

#include "student.h"
#include <vector>

class Records {
public:
  Records();
  ~Records();

  void addRecord(Student* student);
  std::vector<Student *> listRecords() const;
  void modifyRecords(Student* student);
  void deleteRecords(Student* student);
  std::vector<Student *> searchRecords();

private:
  std::vector<Student *> studentRecord;
  std::string rr;

};

#endif
