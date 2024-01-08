#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shared.h"

mural* addMural(char* title, char* content){
    mural* newMural = (mural*)malloc(sizeof(mural));
    newMural->title = strdup(title);
    newMural->c = strdup(content);
    return newMural;
}

mural* insertMural (mural** cab, mural* newMural) { // Na função main, o novo mural será inserido na lista de murais do user logged
    if((*cab) == NULL){
        (*cab) = (mural*)malloc(sizeof(mural));
        (*cab)->prox = NULL;
    }
    if(newMural==NULL){
        printf("Erro ao inserir mural.");
        return NULL;
    }
    newMural->prox = (*cab)->prox;
    (*cab)->prox = newMural;
    return newMural;
}

void showMural (user* writter){

    mural* p = writter->myMural->prox; // myMural é o cabeça, por isso atribui-se "->prox", para acessar o primeiro nó com conteudo
    printf("%s's Mural \n", writter->login);

    while(p!=NULL){
        printf("*****\n\n%s: \n\n%s\n\n*****", p->title, p->c);
        p = p->prox;
    }
    waitCh();
}

/*void freeMural(mural* cab){
    mural* current = cab;
    mural* prox;
    while(current != NULL){
        prox = current->prox;
        free(current);
        current = prox;
    }
    free(cab);
}*/