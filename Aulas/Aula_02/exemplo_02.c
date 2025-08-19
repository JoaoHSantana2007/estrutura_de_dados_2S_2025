#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp; // fp é um ponteiro para arquivos
    fp = fopen("data\\teste.txt", "w");

    if(fp == NULL){ // caso o qrquivo nao seja gerado ele informa ou usuario
        printf("ERRO\nArquivo nao criado\n");
        exit(1);
    }

    printf("Arquivo aberto/criado!\n");

    fclose(fp);

    return 0;
}
