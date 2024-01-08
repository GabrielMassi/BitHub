#ifndef __mural_h_
#define __mural_h_

#include "shared.h"

mural* addMural(char* title, char* content);
mural* insertMural (mural** cab, mural* newMural);
void showMural (user* writter);
//void freeMural(mural* cab);

#endif