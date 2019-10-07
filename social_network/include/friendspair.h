#pragma once
#include "user.h"

//!< foward declaration of user class to boost compile time
class User;

class FriendsPair {
  User *FreindA;
  User *FreindB;

public:
  //!< TODO: further optimization will be to use smart pointers (unique_ptr)
  FriendsPair(User *freindA, User *freindB)
  {
    FreindA = freindA;
    FreindB = freindB;
  };
  // clang-format off
  User *getFriendA() const { return FreindA; };
  User *getFriendB() const { return FreindB; };
  ~FriendsPair(){};
};
