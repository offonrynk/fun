#pragma once

#include "user.h"
#include "friendspair.h"
#include <map>
#include <vector>
class SocialNetwork {
public:
  SocialNetwork();
  ~SocialNetwork();

  void addUser(User *user);
  void deleteUser(const std::string &id);
  User *getUserById(const std::string &id) const;
  std::vector<User *> searchUserByName(const std::string &name) const;
  std::vector<User *> searchUserByAge(int age) const;
  std::vector<User *> searchUserByHobby(const std::string &hobby) const;
  std::vector<User *> getFriendsOfUser(const std::string &id) const;
  std::vector<User *> getUsers() const;
  void addFriendPair(User *friendA, User *friendB);

private:
  std::map<std::string, User *> usersMap;
  std::vector<FriendsPair *> friendsPairList;
  FriendsPair *getFriendship(const std::string &friendAId,
                             const std::string &friendBId);
  void removeFriendship(const std::string &friendAId,
                        const std::string &friendBId);
};
