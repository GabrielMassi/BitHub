#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "shared.h"
#include "perfil.h"
#include "mural.h"

user* create(char* login, char* senha) { // Cria novo usuário (sem adicionar a lista ainda)
    user* u = (user*)malloc(sizeof(user));

	u->myMural = (mural*)malloc(sizeof(mural));
	u->myMural->prox = NULL;

	u->msgCab = NULL;
	u->amigoCab = NULL;
    strcpy(u->login, login);
    strcpy(u->senha, senha);
	strcpy(u->nome, "\0");
	strcpy(u->ocupacao, "\0");
	strcpy(u->endereco, "\0");
	strcpy(u->bio, "\0");
    u->prox = NULL;
    return u;
}


void insert(user** cab, user* p){ // Insere novo usuário no fim da lista
    user* aux = (*cab);
	while (aux->prox != NULL) {
		aux = aux->prox;
	}
	aux->prox = p;
}

user* loginUser(user* cab, char login[30], char senha[10]){ // Checa username e senha para logar

	struct user* p = cab->prox;
	while(p != NULL){
		if(strcmp(p->login, login) != 0 || strcmp(p->senha, senha) != 0)
			p = p->prox;
		else{
			return p;
		}
	}

	return NULL;

}

user* searchUser(user* cab, char login[30]){ // Busca um usuário pelo username

	struct user* p = cab->prox;
	while(p != NULL){
		if(strcmp(p->login, login) != 0 )
			p = p->prox;
		else{
			return p;
		}
	}

	return NULL;

}

void changePass(user** logged){
	char senha[10];
	printf("\nNova Senha: ");
	hidePssW(senha);
	strcpy((*logged)->senha, senha);
	printf("\nSenha modificada com sucesso!\n");
	waitCh();
}