#ifndef __friend_h_
#define __friend_h_

#include "shared.h"

friend* addFriend(user* usercab, friend** amigoCab, char* uname);
void friendList(user* cab, char* uname);
char isFriend(friend* friendList, char* uname);

#endif