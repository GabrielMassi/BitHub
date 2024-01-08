#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <string.h>

//Função para retornar um caracter diretamente do buffer do teclado
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
 }

void waitCh(){
    printf("Pressione qualquer tecla para continuar...");
    getch();
}

void clearBuffer() {
    int c;
    printf("Pressione enter para continuar...");
    while ((c = getchar()) != '\n' && c != EOF) {
        // Descarta os caracteres até encontrar uma nova linha ou o fim do arquivo
    }
}

void hidePssW(char*senha){

    struct termios term;
    tcgetattr(fileno(stdin), &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, &term);
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';
    term.c_lflag |= ECHO;
    tcsetattr(fileno(stdin), 0, &term);

}