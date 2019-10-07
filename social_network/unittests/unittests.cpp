#include "unittests.h"
#include <iostream>

bool UnitTests::testAge(const std::string &name, const int &inputAge)
{
  User m_user(name);

  m_user.setAge(inputAge);
  if (inputAge != m_user.getAge()) {
    printf("Line: %d %s: Wrong Age for : '%s' \n", __LINE__, __FILE__,
           m_user.getName().c_str());
    return false;
  }

  return true;
}

bool UnitTests::testHobbys(const std::string &name,
                           const std::list<std::string> &listOfHobbies)
{
  User m_user(name);

  for (auto const &hobby : listOfHobbies) {
    m_user.setHobby(hobby);
  }

  auto userHobbies = m_user.getHobbies();
  for (auto const &hobby : listOfHobbies) {

    if (std::find(userHobbies.begin(), userHobbies.end(), hobby) ==
        userHobbies.end()) {
      printf("Line: %d %s: Hobby Not found for : '%s' \n", __LINE__, __FILE__,
             m_user.getName().c_str());
      return false;
    }
  }

  return true;
}

bool UnitTests::testAddUsers(const std::list<User *> user)
{
  for (auto const &networkUser : user) {
    m_network.addUser(networkUser);
  }

  // check if user is successfully added to the network
  for (auto const &l_user : m_network.getUsers()) {
    std::string l_userId = l_user->getId();
    auto isUserFound = m_network.getUserById(l_userId);

    if (isUserFound->getId() != l_userId) {
      printf("Line:%d %s: User '%s' with userId '%s' not successfully added \n",
             __LINE__, __FILE__, isUserFound->getName().c_str(),
             isUserFound->getId().c_str());
      return false;
    }
  }

  return true;
}

bool UnitTests::testAddFriendPair(User *friendA, User *friendB)
{
  //!< TODO : Implement test for friend Pair
  m_network.addFriendPair(friendA, friendB);

  return true;
}

bool UnitTests::testDeleteUsers(const std::list<User *> user)
{
  std::string l_userId;
  for (auto &networkUser : user) {
    l_userId = networkUser->getId();
  }

  m_network.deleteUser(l_userId);

  // check if user was successfully deleted
  for (auto const &networkUser : m_network.getUsers()) {
    if (networkUser->getId() == l_userId) {
      printf("Line: %d %s: User '%s' not successfully deleted\n", __LINE__,
             __FILE__, l_userId.c_str());
      return false;
    }
  }
  return true;
}
