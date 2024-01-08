//perfil.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shared.h"
#include "login.h"

/*printf("++++++++++++++++++++++++++++++++++++++++\n\n");
	
	printf("Usuário: %s\n", target->login);

	if(strcmp(target->nome,"\0"))
		printf("Nome completo: %s\n", target->nome);

	if(strcmp(target->ocupacao,"\0"))	
		printf("Ocupacao: %s\n", target->ocupacao);

	if(strcmp(target->endereco,"\0"))
		printf("Endereco: %s\n", target->endereco);

	if(strcmp(target->bio,"\0"))
		printf("Biografia: %s\n\n", target->bio);

	printf("++++++++++++++++++++++++++++++++++++++++\n");*/

void showProf(user* target){

	printf("++++++++++++++++++++++++++++++++++++++++\n\nUsuário: %s\nNome completo: %s\nOcupacao: %s\nEndereco: %s\nBiografia: %s\n\n", target->login, target->nome, target->ocupacao, target->endereco, target->bio);

}

/*void profSweep(user *cab){

	user *p = cab->prox;
	while(p!=NULL){
		showProf(p);
		p=p->prox;
	}

}*/

user* searchProf(user* cab){
    char username[30];
    scanf("%s", username);
    user* target = searchUser(cab, username);
    if(target!=NULL){
		printf("Usuário Encontrado! ");
        showProf(target);

    }else{
        printf("Usuário não encontrado\n");
	}
    return target;
}

void editProf(user** logged){

	char c;
    char i[30];
	while(1){
        system("clear");
        //printf("Seu perfil: \n");
        showProf((*logged));
		printf("Qual informacao voce deseja editar?\n1 - Nome\n2 - Ocupacao\n3 - Endereco\n4 - Biografia\n0- Concluir\n");
		c = getch();
		switch(c){

			case '1':
				printf("Novo nome: ");
				fgets(i, 30, stdin);
				i[strcspn(i, "\n")] = '\0';
				strcpy((*logged)->nome, i);
				printf("\nAlterado!\n");
				break;
			case '2':
				printf("Nova ocupacao: ");
				fgets(i, 30, stdin);
				i[strcspn(i, "\n")] = '\0';
				strcpy((*logged)->ocupacao, i);
				printf("\nAlterado!\n");
				break;
			case '3':
				printf("Novo endereco: ");
				fgets(i, 30, stdin);
				i[strcspn(i, "\n")] = '\0';
				strcpy((*logged)->endereco, i);
				printf("\nAlterado!\n");
				break;
			case '4':
				printf("Nova biografia: ");
				fgets(i, 30, stdin);
				i[strcspn(i, "\n")] = '\0';
				strcpy((*logged)->bio, i);
				printf("\nAlterado!\n");
				break;
			case '0':
				printf("Fim da edição.\n");
				return;
            default:
                break;
		}
	}
}