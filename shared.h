#ifndef __shared_h_
#define __shared_h_

typedef struct msg{

	char* remetente;
	char* content;
	struct msg* prox;

}msg;

typedef struct friend{
	char* uname;
	struct friend* prox;
}friend;

typedef struct mural{
    char* title;
    char* c;
    struct mural* prox;
}mural;

typedef struct user{
	
	//Ponteiro pro próximo (Lista encadeada)
	struct user* prox;

	//Informações obrigatórias (cadastro)
	char senha[10];
	char login[30];
		
	//Outras informações
	char nome[30];
	char ocupacao[30];
	char endereco[30];
	char bio[30];
	mural* myMural;
	struct friend* amigoCab;
	msg* msgCab;

}user;

char getch(void);
void waitCh();
void clearBuffer();
void hidePssW(char* senha);

#endif