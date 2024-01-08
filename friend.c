#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "shared.h"
#include "login.h"

char isFriend(friend* friendList, char* uname){
    friend* p = friendList->prox;
    while(p!=NULL){
        if(strcmp(p->uname, uname) == 0)
            return 1; // Username encontrado -> Já é amigo, não adicionar novamente
        p = p->prox;
    }
    return 0; // Username não encontrado -> Pode adicionar.
}

friend* addFriend(user* usercab, friend** amigoCab, char uname[30]){
    if((*amigoCab)==NULL){
        (*amigoCab) = (friend*)malloc(sizeof(friend));
        (*amigoCab)->prox = NULL;
    }
	
    if(searchUser(usercab, uname) == NULL){
        printf("Usuario nao encontrado.\n");
        waitCh();
        return NULL;
    }

    if(isFriend((*amigoCab), uname)){
        printf("Você ja e amigo deste usuario.\n");
        waitCh();
        return NULL;
    }

    friend* p = (*amigoCab);
    while(p->prox != NULL){
        if(strcmp(uname, p->prox->uname) < 0)
            break;
        p = p->prox;
    }
    friend* found = (friend*)malloc(sizeof(friend));
    found->uname = strdup(uname);
    found->prox = p->prox;
    p->prox = found;

    printf("Adicionado!\n");
    waitCh();
    return found;
}

void friendList(user* cab, char* uname){
    
    user* target = searchUser(cab, uname);
    if(target == NULL || target->amigoCab == NULL){
        printf("Usuário não existe ou não possui amigos.\n");
        waitCh();
        return;
    }
    printf("Amigos de %s:\n\n", target->login);
    friend* p  = target->amigoCab->prox;
    while(p!=NULL){
        printf("--> %s\n\n", p->uname);
        p=p->prox;
    }
    waitCh();
}