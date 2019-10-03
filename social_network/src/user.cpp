#include "user.h"

User::User(const std::string &name)
{
  Name = name;
  int timestamp = static_cast<int>(
      std::time(0)); // unix epoch time: seconds since 01-JAN-1970
  auto timestampString = std::to_string(timestamp);
  Id = Name + timestampString;
}

User::~User()
{
}

std::string User::getName() const
{
  return Name;
}

std::vector<std::string> User::getHobbies() const
{
  return Hobbies;
}

std::string User::getId() const
{
  return Id;
}

std::string User::getGender() const
{
  return Gender;
}

int User::getHeight() const
{
  return Height;
}

std::vector<FriendsPair *> User::getFriendsPairs() const
{
  return Friends;
}

std::vector<User *> User::getFriends() const
{
  std::vector<User *> usersFriends;
  for (auto &userFriend : Friends) {
    usersFriends.push_back(userFriend->getFriendB());
  }
  return usersFriends;
}

FriendsPair *User::getFriendPairRelationship(const std::string &id) const
{
  for (auto &friendAB : Friends) {
    if (friendAB->getFriendB()->getId() == id) {
      return friendAB;
    }
  }
  return nullptr;
}

int User::getAge() const
{
  return Age;
}

void User::setName(const std::string &name)
{
  Name = name;
}

void User::setHobby(const std::string &hobby)
{
  Hobbies.push_back(hobby);
}

void User::setAge(int age)
{
  Age = age;
}

void User::setGender(const std::string &gender)
{
  Gender = gender;
}

void User::setHeight(int height)
{
  Height = height;
}

void User::addFriendship(FriendsPair *friendAB)
{
  Friends.push_back(friendAB);
}

void User::removeFriendshipTo(const std::string &id)
{
  auto friendAB = getFriendPairRelationship(id);
  removeFriend(friendAB);
}

void User::removeFriend(FriendsPair *friendAB)
{
  auto Position = std::find(Friends.begin(), Friends.end(), friendAB);
  Friends.erase(Position);
}
