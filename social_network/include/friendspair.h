#pragma once
#include "user.h"

class User;

class FriendsPair {
public:
  // clang-format off
  FriendsPair(User *freindA, User *freindB)
      : FreindA(freindA)
      , FreindB(freindB)
  {
  };
  ~FriendsPair() = default;
  User *getFriendA() const { return FreindA; };
  User *getFriendB() const { return FreindB; };

private:
  User *FreindA;
  User *FreindB;
};
