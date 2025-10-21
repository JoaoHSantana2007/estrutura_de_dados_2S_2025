#include <stdio.h>
#include <stdlib.h>

// Definindo a estretura de um ITEM da lista ENCADEADA

typedef struct Item {
    
    int Chave;
    struct Item * Proximo;

} Item;

// Bloco principal 

int main() {

    Item * I = (Item *) malloc (sizeof(Item));

    I->Chave = 23;
    I->Proximo= NULL;

    // testes 

    printf("Endereco Hexadeciaml: %x\n", I);
    printf("%d\n", I->Chave);
    printf("%x (NULL)\n", I->Proximo);

    return 0;

}