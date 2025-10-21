#include <stdio.h>
#include <stdlib.h>

// Definindo a estretura de um ITEM da lista ENCADEADA

typedef struct Item {
    
    int Chave;
    struct Item * Proximo;

} Item;

// Bloco principal 

int main() {

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

    A->Chave = 17;
    B->Chave = 29;
    C->Chave = 41;
    D->Chave = 97;

    A->Proximo = NULL;
    B->Proximo = NULL;
    C->Proximo = NULL;
    D->Proximo = NULL;

    // testes 

    printf("%x\t%d\n", A, A->Chave);
    printf("%x\t%d\n", B, B->Chave);
    printf("%x\t%d\n", C, C->Chave);
    printf("%x\t%d\n", D, D->Chave);

    // Construindo o encadeamento (LISTA) A, B, C, D

    A->Proximo = C;
    C->Proximo = B;
    B->Proximo = D;

    // Inserir o Item X, com chave 73, antes do A

    printf("Lista:\n\n");

    Item * X = A;
    printf("%x\t%d\n", X, X->Chave);

    X = X->Proximo;
    printf("%x\t%d\n", X, X->Chave);

    
    return 0;

}