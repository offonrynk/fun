#include "records.h"
#include "student.h"
#include <iostream>
#include <memory>

/** local helper print function
 *  @param[in] vector of student
 */
void l_print(std::vector<Student *> dataToPrint)
{
  for (const auto &it : dataToPrint) {
    std::cout << it->getName() << "\n";
    std::cout << it->getRegNum() << "\n";
    std::cout << it->getMajorProgram() << "\n";
    std::cout << it->getCourses() << "\n\n";
  }
}

/** local overloaded print helper function for search methods
 *  @param[in] vector of student
 */
void l_print(std::string &stringToSearchFor, std::vector<Student *> dataToPrint)
{
  std::cout << "Students associated with:- " << stringToSearchFor << "\n";
  for (const auto &it : dataToPrint) {
    std::cout << it->getName() << "\n";
  }
  std::cout << '\n';
}

int main()
{
  std::cout << "Basic Unit Tests\n-----------------\n";

  Records records;
  std::unique_ptr<Student> James = std::make_unique<Student>("James John");
  std::unique_ptr<Student> Dave = std::make_unique<Student>("David Kidd");
  std::unique_ptr<Student> Tom = std::make_unique<Student>("Tom Heart");
  std::unique_ptr<Student> Sandra = std::make_unique<Student>("Sandra Johnny");
  std::unique_ptr<Student> Nessa = std::make_unique<Student>("Vanessa Susan");

  James->addMajor("Electrical Engineering");
  James->addCourses("Math101, Phy101, Chem101");
  records.addRecord(James.get());

  Dave->addMajor("Physics");
  Dave->addCourses("Math101, Phy101, Chem101");
  records.addRecord(Dave.get());

  Tom->addMajor("Economics");
  Tom->addCourses("Math101, Eco101, Bus101");
  records.addRecord(Tom.get());

  Sandra->addMajor("Computer Science");
  Sandra->addCourses("CMS101, Math101, C101");
  records.addRecord(Sandra.get());

  Nessa->addMajor("Computer Science");
  Nessa->addCourses("Math101, C101, CMS101, C++001, Python, Ruby, Data101");
  records.addRecord(Nessa.get());

  //!< print records to visualize all students are added
  l_print(records.listRecords());

  //!< test search methods
  // clang-format off
  std::string nameToSearchFor    = "David Kidd";
  std::string majorToSearchFor   = "Computer Science";
  std::string coursesToSearchFor = "C++001";

  std::vector<Student *> nameVector   = records.searchRecordsByName(nameToSearchFor);
  std::vector<Student *> majorVector  = records.searchRecordsByMajor(majorToSearchFor);
  std::vector<Student *> courseVector = records.searchRecordsByCourse(coursesToSearchFor);
  // clang-format on

  l_print(nameToSearchFor, nameVector);
  l_print(majorToSearchFor, majorVector);
  l_print(coursesToSearchFor, courseVector);

  //!< test modify methods
  records.modifyStudentName(James.get(), James->getName(), "Peter Pan");
  records.modifyStudentMajor(James.get(), James->getMajorProgram(),
                             "New Major");
  records.modifyStudentCourses(James.get(), Records::EModifyCourses::ADD,
                               James->getCourses(), "Math200, BMS201");
  records.modifyStudentCourses(Sandra.get(), Records::EModifyCourses::REPLACE,
                               "Math101", "Math500");
  records.modifyStudentCourses(Nessa.get(), Records::EModifyCourses::REMOVE,
                               "C101", "");
  std::cout << "Test if the Records Modified as Desired\n";
  l_print(records.listRecords());

  //!< test delete
  records.deleteRecords(James.get());
  std::cout << "Check if the Record for James is Deleted\n";
  l_print(records.listRecords());

  return EXIT_SUCCESS;
}
