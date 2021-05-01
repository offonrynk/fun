#include "social_network.h"
#include "unittests.h"
#include "user.h"
#include <memory>

int main()
{
  std::cout << "This Program just executes some basic Unit tests to test if the"
               " functionality of the Dummy Social Network"
            << std::endl;

  // clang-format off
  auto James = std::make_unique<User>("James");
  auto Monica = std::make_unique<User>("Monica");
  auto Klaus = std::make_unique<User>("Klaus");
  auto Jane = std::make_unique<User>("Jane");
  auto Muller = std::make_unique<User>("Muller");
  auto Vanessa = std::make_unique<User>("Vanessa");

  UnitTests unittests;
  bool success = true;
  try {
    success = unittests.testAge("James", 22);
    success = success && unittests.testHobbys("James", {"football", "swimming",
                                                          "basketball"});

    success = success && unittests.testAge("Monica", 24);
    success = success && unittests.testHobbys("Monica", {"dancing", "shopping"});

    success = success && unittests.testAge("Klaus", 24);
    success = success && unittests.testHobbys("Klaus", {"sleeping", "jumping"});

    success = success && unittests.testAddUsers({James.get(), Klaus.get(), Jane.get(), Monica.get()});
    success = success && unittests.testAddFriendPair(James.get(), Monica.get());
    success = success && unittests.testAddFriendPair(Klaus.get(), Jane.get());
    success = success && unittests.testAddFriendPair(James.get(), Jane.get());
    success = success && unittests.testDeleteUsers({Monica.get()});
  }
  catch (const std::exception& msg) {
    std::cout << "Exception" << msg.what() << "thrown\n";
  }

  if (success) {
    std::cout << "Yes! :- Unit Tests Passed\n";
  }
  else {
    std::cout << "Unit Tests Failed\n";
  }
  return 0;
}
