#ifndef __login_h_
#define __login_h_

#include "shared.h"

int signupin(user** cab, user** logged);
int loggedMenu(user* usercab, user** logged);
void freeUsers(user* cab);

#endif