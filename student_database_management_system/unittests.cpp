#include "records.h"
#include "student.h"
#include <iostream>

int main() {
  std::cout << "Basic Unit Tests " << "\n";
  std::cout << "---------------- " << "\n";

  Records r;
  Student* James = new Student("James John");
  Student* Dave = new Student("David Kidd");
  Student* Tom = new Student("Tom Heart");

  James->addMajor("Electrical Engineering");
  James->addCourses("Math101, Phy101, Chem101");
  r.addRecord(James);

  Dave->addMajor("Physics");
  Dave->addCourses("Math101, Phy101, Chem101");
  r.addRecord(Dave);

  Tom->addMajor("Economics");
  Tom->addCourses("Math101, Eco101, Bus101");
  r.addRecord(Tom);

  std::vector<Student* > rec = r.listRecords();
  for (const auto& it : rec) {
    std::cout << it->getName() << std::endl;
    std::cout << it->getRegNum() << std::endl;
    std::cout << it->majorProgram() << std::endl;
    std::cout << it->getCourses() << '\n' << '\n';
  }
 
  r.deleteRecords(James);
  std::cout << "Check if the Record for James is Deleted " 
            << '\n' << std::endl;

  std::vector<Student* > recEdited = r.listRecords();
  for (const auto& it : recEdited) {
    std::cout << it->getName() << std::endl;
    std::cout << it->getRegNum() << std::endl;
    std::cout << it->majorProgram() << std::endl;
    std::cout << it->getCourses() << '\n' << '\n';
  }
  /*TODO: Improve UnitTests
          Implement User-friendly scenario
  */
//  system("pause");
  return 0;
}
