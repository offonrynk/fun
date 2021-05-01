#include "social_network.h"

User *SocialNetwork::getUserById(const std::string &id) const
{
  if (usersMap.find(id) == usersMap.end()) {
    std::cout << "The given user id does not exist" << std::endl;
    return nullptr;
  }

  return usersMap.find(id)->second;
}

std::vector<User *> SocialNetwork::getUsers() const
{
  std::vector<User *> users;
  for (auto &user : usersMap) {
    users.push_back(user.second);
  }
  return users;
}

FriendsPair *SocialNetwork::getFriendship(const std::string &friendAId,
                                          const std::string &friendBId)
{
  if (usersMap.find(friendAId) == usersMap.end() &&
      usersMap.find(friendBId) == usersMap.end()) {
    std::cout << "The given friendship does not exist" << std::endl;
    return nullptr;
  }

  auto friendPairA = usersMap.find(friendAId)->second;
  return (*friendPairA).getFriendPairRelationship(friendBId);
}

void SocialNetwork::removeFriendship(const std::string &friendAId,
                                     const std::string &friendBId)
{
  FriendsPair *pair = getFriendship(friendAId, friendBId);
  if (pair != nullptr) {
    auto friendPosition =
        std::find(friendsPairList.begin(), friendsPairList.end(), pair);
    friendsPairList.erase(friendPosition);

    (*pair).getFriendA()->removeFriend(pair);
    (*pair).getFriendB()->removeFriend(pair);
  }
}

void SocialNetwork::addFriendPair(User *friendA, User *friendB)
{
  auto pair = new FriendsPair(friendA, friendB);
  friendA->addFriendship(pair);
  friendB->addFriendship(pair);
  friendsPairList.push_back(pair);
}

void SocialNetwork::addUser(User *user)
{
  usersMap[(*user).getId()] = user;
  auto friends = user->getFriendsPairs();
  if (!friends.empty()) {
    for (auto &userPal : friends) {
      friendsPairList.push_back(userPal);
    }
  }
}

void SocialNetwork::deleteUser(const std::string &id)
{
  auto user = getUserById(id);
  if (user != nullptr) {
    auto friends = getUserById(id)->getFriendsPairs();

    for (auto &friendPair : friends) {
      auto friendAId = friendPair->getFriendA()->getId();
      auto friendBId = friendPair->getFriendB()->getId();
      removeFriendship(friendAId, friendBId);
    }
    usersMap.erase(id);
  }
  else {
    std::cout << "User with the given id does not exist" << std::endl;
  }
}

std::vector<User *>
SocialNetwork::searchUserByName(const std::string &name) const
{
  std::vector<User *> usersWithName;
  for (auto &user : usersMap) {
    if (user.second->getName() == name) {
      usersWithName.push_back(user.second);
    }
  }
  return usersWithName;
}

std::vector<User *> SocialNetwork::searchUserByAge(int age) const
{
  std::vector<User *> usersWithAge;
  for (auto &user : usersMap) {
    if (user.second->getAge() == age) {
      usersWithAge.push_back(user.second);
    }
  }
  return usersWithAge;
}

std::vector<User *>
SocialNetwork::searchUserByHobby(const std::string &hobby) const
{
  std::vector<User *> usersWithHobby;
  for (auto &user : usersMap) {
    auto hobbies = user.second->getHobbies();
    for (auto &hby : hobbies) {
      if (hby == hobby) {
        usersWithHobby.push_back(user.second);
      }
    }
  }
  return usersWithHobby;
}

std::vector<User *> SocialNetwork::getFriendsOfUser(const std::string &id) const
{
  auto user = getUserById(id);

  return user->getFriends();
}
