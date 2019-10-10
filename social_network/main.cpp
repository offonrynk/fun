#include "social_network.h"
#include "unittests.h"
#include "user.h"
#include <iostream>

int main()
{
  std::cout << "This Program just executes some basic Unit tests to test if the"
               " functionality of the Dummy Social Network"
            << std::endl;

  // clang-format off
  User *James   = new User("James");
  User *Monica  = new User("Monica");
  User *Klaus   = new User("Klaus");
  User *Jane    = new User("Jane");
  User *Muller  = new User("Muller Thomas");
  User *Vanessa = new User("Vanessa Merkel");

  UnitTests m_unittests;
  bool success = true;
  try {
    success = success && m_unittests.testAge("James", 22);
    success = success && m_unittests.testHobbys("James", {"football", "swimming",
                                                          "basketball"});

    success = success && m_unittests.testAge("Monica", 24);
    success = success && m_unittests.testHobbys("Monica", {"dancing", "shopping"});

    success = success && m_unittests.testAge("Klaus", 24);
    success = success && m_unittests.testHobbys("Klaus", {"sleeping", "jumping"});

    success = success && m_unittests.testAddUsers({James, Klaus, Jane, Monica});
    success = success && m_unittests.testAddFriendPair(James, Monica);
    success = success && m_unittests.testAddFriendPair(Klaus, Jane);
    success = success && m_unittests.testAddFriendPair(James, Jane);
    success = success && m_unittests.testDeleteUsers({Monica});
  }
  catch (const bool msg) {
    /*
      TODO: Implement handlers
    */
  }

  if (success) {
    std::cout << "\n" << "Yes! :- Unit Tests Passed" << std::endl;
  }
  else {
    std::cout << "Unit Tests Failed" << std::endl;
  }

  delete James;
  delete Monica;
  delete Klaus;
  delete Jane;
  delete Muller;
  delete Vanessa;

  return 0;
}
