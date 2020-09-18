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
    std::cout << it->getName() << std::endl;
    std::cout << it->getRegNum() << std::endl;
    std::cout << it->getMajorProgram() << std::endl;
    std::cout << it->getCourses() << '\n' << '\n';
  }
}

/** local overloaded print helper function for search methods
 *  @param[in] vector of student
 */
void l_print(std::string &stringToSearchFor, std::vector<Student *> dataToPrint)
{
  std::cout << "Students associated with:- " << stringToSearchFor << std::endl;
  for (const auto &it : dataToPrint) {
    std::cout << it->getName() << std::endl;
  }
  std::cout << '\n';
}

int main()
{
  std::cout << "Basic Unit Tests " << std::endl;
  std::cout << "---------------- " << std::endl;

  Records m_records;
  std::unique_ptr<Student> James = std::make_unique<Student>("James John");
  std::unique_ptr<Student> Dave = std::make_unique<Student>("David Kidd");
  std::unique_ptr<Student> Tom = std::make_unique<Student>("Tom Heart");
  std::unique_ptr<Student> Sandra = std::make_unique<Student>("Sandra Johnny");
  std::unique_ptr<Student> Nessa = std::make_unique<Student>("Vanessa Susan");

  James->addMajor("Electrical Engineering");
  James->addCourses("Math101, Phy101, Chem101");
  m_records.addRecord(James.get());

  Dave->addMajor("Physics");
  Dave->addCourses("Math101, Phy101, Chem101");
  m_records.addRecord(Dave.get());

  Tom->addMajor("Economics");
  Tom->addCourses("Math101, Eco101, Bus101");
  m_records.addRecord(Tom.get());

  Sandra->addMajor("Computer Science");
  Sandra->addCourses("CMS101, Math101, C101");
  m_records.addRecord(Sandra.get());

  Nessa->addMajor("Computer Science");
  Nessa->addCourses("Math101, C101, CMS101, C++001, Python, Ruby, Data101");
  m_records.addRecord(Nessa.get());

  //!< print records to visualize all students are added
  l_print(m_records.listRecords());

  //!< test search methods
  // clang-format off
  std::string nameToSearchFor    = "David Kidd";
  std::string majorToSearchFor   = "Computer Science";
  std::string coursesToSearchFor = "C++001";

  std::vector<Student *> nameVector   = m_records.searchRecordsByName(nameToSearchFor);
  std::vector<Student *> majorVector  = m_records.searchRecordsByMajor(majorToSearchFor);
  std::vector<Student *> courseVector = m_records.searchRecordsByCourse(coursesToSearchFor);
  // clang-format on

  l_print(nameToSearchFor, nameVector);
  l_print(majorToSearchFor, majorVector);
  l_print(coursesToSearchFor, courseVector);

  //!< test modify methods
  m_records.modifyStudentName(James.get(), James->getName(), "Peter Pan");
  m_records.modifyStudentMajor(James.get(), James->getMajorProgram(),
                               "New Major");
  m_records.modifyStudentCourses(James.get(), Records::EModifyCourses::ADD,
                                 James->getCourses(), "Math200, BMS201");
  m_records.modifyStudentCourses(Sandra.get(), Records::EModifyCourses::REPLACE,
                                 "Math101", "Math500");
  m_records.modifyStudentCourses(Nessa.get(), Records::EModifyCourses::REMOVE,
                                 "C101", "");
  std::cout << "Test if the Records Modified as Desired " << '\n' << std::endl;
  l_print(m_records.listRecords());

  //!< test delete
  m_records.deleteRecords(James.get());
  std::cout << "Check if the Record for James is Deleted " << '\n' << std::endl;
  l_print(m_records.listRecords());

  return EXIT_SUCCESS;
}
