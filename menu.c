#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#include "shared.h"
#include "login.h"
#include "perfil.h"
#include "mural.h"
#include "friend.h"
#include "messages.h"

int signupin(user** cab, user** logged){ //Sign up/sign in *TUDO FUNCIONANDO*
	system("clear");
	printf("-Pressione 1 para criar uma conta\n\n-Pressione 2 para fazer login\n\nPressione 0 para sair\n\n");
	char a = getch();

	if(a == '1'){ // Cadastro
		char t = 2;
		char login[30];
		char senha[10];
		while(t){ //loop para evitar logins repetidos
			if(t == 1){
				system("clear");
				printf("Username em uso, tente outro.\n\n");
				sleep(1);
			}
			printf("Login: ");
			scanf("%s", login);
			if(searchUser((*cab), login) == NULL)
				t = 0;
			else
				t = 1;
		}
		printf("\n\nSenha: ");
		getchar();
		hidePssW(senha);

		(*logged) = create(login, senha);
		insert(cab, (*logged));
		system("clear");
		printf("\n\nUsuario %s cadastrado com sucesso!\n\n", (*logged)->login);

		char a;
		printf("Deseja editar seu perfil agora?\n[s = Sim/ Qualquer tecla = Não]: ");
		a = getch();
		if(a == 's' || a == 'S'){
			editProf(logged);
		}

	}else if(a == '2'){ // Login
		char login[30];
		char senha[10];
		printf("Login: ");
		scanf("%s", login);
		printf("\n\nSenha: ");
		getchar();
		hidePssW(senha);

		user *aux = (struct user*)malloc(sizeof(struct user*));
		aux = loginUser((*cab), login, senha);
		if(aux != NULL){
			(*logged) = aux;
			printf("Você está logado!");
			return 1;
		}else{
			printf("\n\nLogin inválido!\n\n");
			waitCh();
			return 0;
		}

		
	}else if(a == '0'){
		//freeUsers(cab);
		return 2;
	}
}

int loggedMenu(user* usercab, user** logged){
    system("clear");
    printf("Suas acões: \n\n1 Ver um perfil\n2 Editar seu perfil\n3 Ver um mural\n4 Postar em seu mural\n5 Ver amigos\n6 Adicionar amigo\n7 Mensagens\n8 Mudar senha\n9 Deslogar");

	char a = getch();
	system("clear");

	switch (a)
	{
	case '1': //Ver um perfil *FUNCIONANDO*
		printf("Digite um username para encontrar o perfil deste usuário: ");
		user* found = searchProf(usercab);
		waitCh();
		break;

	case '2': //Ver e editar seu perfil *FUNCIONANDO*
		editProf(logged);
		waitCh();
		break;

	case '3': //Ver um mural *FUNCIONANDO*
		char uname[30];
		printf("Digite um username para encontrar o mural deste usuário: ");
		scanf("%s", uname);
		searchUser(usercab, uname);
		found = searchUser(usercab, uname);
		if(found!=NULL)
			showMural(found);
		break;

	case '4': //Postar em seu mural *FUNCIONANDO*
		char title[30];
		char content[100];
		printf("Novo Post:\n");
		clearBuffer();
		system("clear");
		printf("\nNovo Post:\n");
		printf("\nTitulo: ");
		fgets(title, 30, stdin);
		title[strcspn(title, "\n")] = '\0';
		printf("Post: ");
		fgets(content, 100, stdin);
		content[strcspn(content, "\n")] = '\0';
		mural* newMu = addMural(title, content);
		insertMural(&((*logged)->myMural), newMu);
		break;

	case '5': // Ver sua lista de amigos 
		printf("Digite o usuario do qual voce quer ver a lista de amigos: ");
		scanf("%s", uname);
		friendList(usercab, uname);
		break;

	case '6': // Adicionar amigo X PROBLEMAS X

		uname[30];
		printf("Digite um username para adicionar a sua lista de amigos: ");
		scanf("%s", uname);
		addFriend(usercab, &((*logged)->amigoCab), uname);
		break;
	
	case '7': //Mensagens (Ver e enviar)
		if((*logged)->msgCab != NULL){
			printf("Você tem novas mensagens!");
			showMsg((*logged)->msgCab);
			(*logged)->msgCab = NULL;
		}
		printf("Deseja mandar uma mensagem para alguém?\n[s = Sim / Qualquer tecla = Não]:");
		char c = getch();
		if(c == 's' || c == 'S'){
			printf("Digite o nome do usuário que recebera a mensagem: ");
			scanf("%s", uname);
			found = searchUser(usercab, uname);
			if(found != NULL)
				sendMsg(found, (*logged)->login);
			else
				printf("Usuário não encontrado.");
		}
		break;

	case '8':
		printf("Digite a senha antiga antes de escolher uma nova: ");
		char senha[10];
		hidePssW(senha);
		if(strcmp(senha, (*logged)->senha) == 0)
			changePass(logged);
		else{
			printf("Senha incorreta.\n");
			sleep(1);
		}
		break;

	case '9': //Deslogar 
		return 1;
		break;

	default:
		break;
	}
    
    return 0;
}

//DESALOCACAO

void freeUsers(user* cab) {
    if (cab == NULL) {
        return;
    }

    freeUsers(cab->prox);

    free(cab);
}
