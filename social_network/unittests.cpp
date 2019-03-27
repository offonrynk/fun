#include "social_network.h"
#include "user.h"
#include <iostream>

int main() {
  std::cout << "  Simple Unit Tests " << "\n";
  std::cout << "--------------------" << "\n";

  SocialNetwork network;
  User *James   = new User("James");
  User *Monica  = new User("Monica");
  User *Klaus1  = new User("Klaus");
  User *Klaus2  = new User("Klaus");
  User *Muller  = new User("Muller Thomas");
  User *Vanessa = new User("Vanessa Merkel");

  James->setAge(22);
  James->setHobby("football");
  James->setHobby("swimming");
  James->setHobby("basketball");

  Monica->setAge(18);
  Monica->setHobby("shopping");
  Monica->setHobby("dancing");

  Klaus1->setAge(24);
  Klaus1->setHobby("sleeping");
  Klaus1->setHobby("jumping");

  Klaus2->setAge(18);

  network.addUser(James);
  network.addUser(Klaus1);
  network.addUser(Klaus2);
  network.addUser(Monica);

  network.addFriendPair(James, Monica);
  network.addFriendPair(Klaus1, Klaus2);
  network.addFriendPair(James, Klaus2);

  if (22 != James->getAge()) {
    std::cout << "Wrong Age for " << James->getName() << "\n";
    return -1;
  } else {
    std::cout << James->getName() << " is " << James->getAge() << " years old" << "\n";
  }

  auto monicaHobbies   = Monica->getHobbies();
  auto monicaFindHobby = std::find(monicaHobbies.begin(), monicaHobbies.end(), "shopping");
  if (monicaFindHobby == monicaHobbies.end()) {
    std::cout << "Hobby Not found for " << Monica->getName() << "\n";
    return -1;
  } else {
    std::cout << Monica->getName() << " likes shopping" << "\n";
  }

  auto klausHobbies   = Klaus2->getHobbies();
  auto klausFindHobby = std::find(klausHobbies.begin(), klausHobbies.end(), "sleeping");
  if (klausFindHobby == klausHobbies.end()) {
    std::cout << "Hobby 'sleeping' Not found for " << Klaus2->getName() << "\n";
    return -1;
  } else {
    std::cout << Klaus2->getName() << " likes hobby" << "\n";
  }

  for (auto &rand : James->getFriends()) {
    std::cout << rand->getName() << "\n";
  }
  /*
  for (auto& user : network.getUsers()) {
    std::cout << "User Id " << user->getId() << "\n";
    std::cout << "Name " << user->getName() << "\n";
    std::cout << "Age " << user->getAge() << "\n";

    for (auto& i : user->getHobbies())
    std::cout << "Hobby " << i << "\n";
  }
  network.deleteUser(Monica->getId());

  for (auto& user : network.getUsers()) {
    std::cout << "User Id " << user->getId() << "\n";
    std::cout << "Name " << user->getName() << "\n";
    std::cout << "Age " << user->getAge() << "\n";

    for (auto& i : user->getHobbies())
      std::cout << "Hobby " << i << "\n";
  }*/
  return 0;
}
