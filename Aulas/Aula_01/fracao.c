#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fracao.h"

Fracao criarfracao(int N, int D) {
    Fracao F;
    F.num = N;
    F.den = D;

    return F;
}

int calcularMDC(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    while (b != 0) {
        int i = a % b;
        a = b;
        b = i;        
    }   

    return a;
}

Fracao simplificarFracao(Fracao F) {
    int mdc = calcularMDC(F.num, F.den);

    F.num /= mdc;
    F.den /= mdc;

    return F;
}

Fracao somarfracao(Fracao F, Fracao G){
    Fracao Resposta;
    Resposta.num = F.num * G.den + G.num * F.den;
    Resposta.den = F.den * G.den;
    Resposta = simplificarFracao(Resposta);

    return Resposta;
}

Fracao subtrairfracao(Fracao F, Fracao G) {
    Fracao Resposta;
    Resposta.num = F.num * G.den - G.num * F.den;
    Resposta.den = F.den * G.den;
    Resposta = simplificarFracao(Resposta);

    return Resposta;
}

void exibirFracao(Fracao F) {
    printf("%d / %d\n", F.num,F.den);
}