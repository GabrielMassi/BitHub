#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "shared.h"

void showMsg(msg* logged){
    msg* p = logged->prox;
    msg* prox;
    while(p!=NULL){
        prox = p->prox;
        printf("\n*****\nMensagem de %s: \n\n%s\n*****\n", p->remetente, p->content);
        free(p);
        p = prox;
    }
    
    free(logged);
}

msg* sendMsg(user* target, char* username){

    msg* newMsg = (msg*)malloc(sizeof(msg));
    newMsg->remetente = username;
    printf("Digite sua mensagem: ");
    char cont[100];
    getchar();
    fgets(cont, 100, stdin);

    newMsg->content = strdup(cont);
    if(target->msgCab==NULL)
        target->msgCab = (msg*)malloc(sizeof(msg));
    newMsg->prox = target->msgCab->prox;
    target->msgCab->prox = newMsg;

    printf("Mensagem enviada.\n");
    waitCh();

}