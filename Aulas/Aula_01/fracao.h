#ifndef FRACAO_H
#define FRACAO_H

typedef struct {
    int num;
    int den;
} Fracao;

int calcularMDC(int a, int b);
Fracao simplificarFracao(Fracao F);
Fracao criarfracao(int N, int D);
Fracao somarfracao(Fracao F, Fracao G);
Fracao subtrairfracao(Fracao F, Fracao G);
Fracao multiplicarfrcao(Fracao F, Fracao G);
void exibirFracao(Fracao F);

#endif 