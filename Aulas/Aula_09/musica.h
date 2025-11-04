#ifndef MUSICA_H
#define MUSICA_H

typedef struct Item {
    char Titulo[50];
    char Autor[100];
    int Ano;

    struct Item *Anterior;
    struct Item *Posterior;
} Item;

#endif
