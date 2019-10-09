#include "records.h"
#include "student.h"
#include <iostream>

/*TODO: Improve UnitTests
        Implement User-friendly scenario
*/
int main()
{
  std::cout << "Basic Unit Tests " << std::endl;
  std::cout << "---------------- " << std::endl;

  Records r;
  Student *James = new Student("James John");
  Student *Dave = new Student("David Kidd");
  Student *Tom = new Student("Tom Heart");

  James->addMajor("Electrical Engineering");
  James->addCourses("Math101, Phy101, Chem101");
  r.addRecord(James);

  Dave->addMajor("Physics");
  Dave->addCourses("Math101, Phy101, Chem101");
  r.addRecord(Dave);

  Tom->addMajor("Economics");
  Tom->addCourses("Math101, Eco101, Bus101");
  r.addRecord(Tom);

  std::vector<Student *> rec = r.listRecords();
  for (const auto &it : rec) {
    std::cout << it->getName() << std::endl;
    std::cout << it->getRegNum() << std::endl;
    std::cout << it->majorProgram() << std::endl;
    std::cout << it->getCourses() << '\n' << '\n';
  }
  r.modifyRecords(James);

  r.deleteRecords(James);
  std::cout << "Check if the Record for James is Deleted " << '\n' << std::endl;

  std::vector<Student *> recEdited = r.listRecords();
  for (const auto &it : recEdited) {
    std::cout << it->getName() << std::endl;
    std::cout << it->getRegNum() << std::endl;
    std::cout << it->majorProgram() << std::endl;
    std::cout << it->getCourses() << '\n' << '\n';
  }

  r.modifyRecords(James);
  return 0;
}
