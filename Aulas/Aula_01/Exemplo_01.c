#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[150]; // Gasta 150 + 1 ("\0") = 151 caracteres
    char telefone[14]; // 15 caracteres 
    char endereco[200]; // 201 caracteres 
} Pessoa;

int main(){

    Pessoa P;
    strcpy(P.nome, "Maria Alves");
    strcpy(P.telefone, "(61) 12345-6789");
    strcpy(P.endereco, "SHIS 12 25 13");

    printf("\n\t%s \n\t%s \n\t%s\n", P.nome, P.telefone, P.endereco);

    return 0;
}