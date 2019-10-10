/** @file   unittests.h
 *  @brief  Unittests to test functionality of Dummy Social Network
 *  @author Nkrumah Offonry
 */
#pragma once

#include "social_network.h"
#include <iostream>
#include <list>

class UnitTests {
public:
  /** @brief                   Tests if we can succesfully set a user's age
   *  @param name[in]          Desired user name
   *  @param inputAge[in]      Desired age
   *  @return                  true on success, false on error
   */
  bool testAge(const std::string &name, const int &inputAge);

  /** @brief                   Tests if we can succesfully set a user's hobby
   *  @param name[in]          Desired user name
   *  @param listOfHobbies[in] Desired hobbies
   *  @return                  true on success, false on error
   */
  bool testHobbys(const std::string &name,
                  const std::list<std::string> &listOfHobbies);

  /** @brief                   Tests if we can succesfully add a user
   *  @param user[in]          user
   *  @return                  true on success, false on error
   */
  bool testAddUsers(const std::list<User *> user);

  /** @brief                   Tests if we can succesfully add a friendPair
   *  @param friendA[in]       social network user
   *  @param friendB[in]       social network user
   *  @return                  true on success, false on error
   */
  bool testAddFriendPair(User *friendA, User *friendB);

  /** @brief                   Tests if we can succesfully delete a user
   *  @param user[in]          user
   *  @return                  true on success, false on error
   */
  bool testDeleteUsers(const std::list<User *> user);

private:
  SocialNetwork m_network;
};
