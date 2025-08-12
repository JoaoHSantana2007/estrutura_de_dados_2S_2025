#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fracao.h"

int main() {

    system("cls");

    Fracao F1 = criarfracao(24,30);
    F1 = simplificarFracao(F1);
    exibirFracao(F1);//sera exibido 4 / 5

    Fracao F2 = criarfracao(-30,40);
    F2 = simplificarFracao(F2);
    exibirFracao(F2);//sera exibido -3 / 4

    Fracao F3 = criarfracao(37,42);
    F3 = simplificarFracao(F3);
    exibirFracao(F3);//sera exibido 37 / 42

    Fracao F4 = criarfracao(5,6);
    Fracao F5 = criarfracao(4,9);
    Fracao F6 = somarfracao(F4,F5);
    exibirFracao(F6);//sera exibido 23/18

    Fracao F7 = criarfracao(5,6);
    Fracao F8 = criarfracao(4,9);
    Fracao F9 = subtrairfracao(F4,F5);
    exibirFracao(F6);//sera exibido 23/18

    //atividade pratica 3/4 - 7/9 + 5/12
    Fracao F10 = criarfracao(3,4);
    Fracao F11 = criarfracao(7,9);
    Fracao F12 = criarfracao(5,12);
    Fracao F13 = subtrairfracao(F10,F11);
    Fracao F14 = somarfracao(F12,F13);
    exibirFracao(F14);//sera exibido 7 / 18

    return 0;
}