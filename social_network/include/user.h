#pragma once
#include "friendspair.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>
class User {
public:
  std::string getName() const;
  std::vector<std::string> getHobbies() const;
  std::string getId() const;
  std::string getGender() const;
  std::vector<FriendsPair *> getFriendsPairs() const;
  std::vector<User *> getFriends() const;
  FriendsPair *getFriendPairRelationship(const std::string &id) const;
  int getAge() const;
  int getHeight() const;
  void setName(const std::string &name);
  void removeFriend(FriendsPair *friendAB);
  void setHobby(const std::string &hobby);
  void setGender(const std::string &gender);
  void setAge(int age);
  void setHeight(int height);
  void addFriendship(FriendsPair *friendAB);
  void removeFriendshipTo(const std::string &id);
  User(const std::string &name);
  ~User();

private:
  std::string Name;
  std::string Id;
  int Age;
  int Height;
  std::string Gender;
  std::vector<std::string> Hobbies;
  std::vector<FriendsPair *> Friends;
};
