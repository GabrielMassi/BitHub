#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "menu.h"
#include "shared.h"
//#include "login.h"

int main(){

	user* usercab = (struct user*)malloc(sizeof(struct user*)); //nó cabeça da struct de usuários
	usercab->prox = NULL;
	usercab->myMural = NULL;
	usercab->msgCab = NULL;
	usercab->amigoCab = NULL;

	user *logged = (struct user *)malloc(sizeof(struct user*)); //nó que guarda o usuário logado

	system("clear");
	printf("---Bem-vindo ao BitHub!---\n\n");
	waitCh(1);
	
	int exit;

	while (1){

		exit = 0;
		while(!exit){ //Criar uma conta ou fazer login
			exit = signupin(&usercab, &logged);
		}
		if(exit == 2){ // Se o usuário seleciona 0 o programa acaba
			system("clear");
			freeUsers(usercab);
			return 0;
		}
		//*********************************************
		
		exit = 0;
		while(!exit){ //Interface do usuário logado:
			exit = loggedMenu(usercab, &logged);
		}


	}

	return 0;

}