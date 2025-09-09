#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

int main() {

    system("cls");

    Equipe * tabela = LerDados("data\\tabela.csv");
    Insertiontort(tabela, 20);

    printf("%.2f%%\n", getAproveitamento(tabela, "Flamengo"));

}
