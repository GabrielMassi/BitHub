#ifndef __login_h_
#define __login_h_

#include "shared.h"

user* create(char* login, char* senha);
void insert(user** cab, user* p);
user* loginUser(user *cab, char login[30], char senha[10]);
user* searchUser(user* cab, char login[30]);
void changePass(user** logged);

#endif