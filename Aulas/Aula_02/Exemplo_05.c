#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp; 
    fp = fopen("data\\bd.txt", "r");

    if(fp == NULL){ 
        printf("ERRO\nArquivo nao criado\n");
        exit(1);
    }

    printf("Arquivo criado com sucesso\n");

    int conta;
    float saldo;
    char nome[50];

    for(int i = 0; i < 4; i++){
        fscanf(fp, "%d %f %[^\n]\n", &conta, &saldo, nome);
        printf("Conta:%d\nSaldo:%.2f\nNome:%s\n", conta, saldo, nome);
        printf("----------------------------------------------------------\n");
    }

    fclose(fp);

    return 0;
}
