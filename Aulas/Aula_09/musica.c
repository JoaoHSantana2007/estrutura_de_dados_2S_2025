#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musica.h"

Item * criarItem(char * Titulo, char * Autor, int Ano) {

    Item * X = (Item *) malloc(sizeof(Item));
    if (X == NULL) {
        printf("Erro: nao foi possivel alocar memoria para o Item.\n");
        return NULL;
    }

    strcpy(X->Titulo, Titulo);
    strcpy(X->Autor, Autor);
    X->Ano = Ano;
    X->Anterior = NULL;
    X->Posterior = NULL;
    
    return X;
}