#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "expressao.h"

#define PREC_ATOM 4
#define PREC_POW  3
#define PREC_MUL  2
#define PREC_ADD  1

#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

typedef struct {
    float *dados;
    int topo;
    int capacidade;
} FloatStack;

typedef struct {
    char *texto;
    int precedencia;
} InfixNode;

typedef struct {
    InfixNode *dados;
    int topo;
    int capacidade;
} NodeStack;

FloatStack* criarPilha(int capacidade) {
    FloatStack *pilha = (FloatStack*)malloc(sizeof(FloatStack));
    if (!pilha)
        return NULL;
    pilha->dados = (float*)malloc(capacidade * sizeof(float));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

void empilhar(FloatStack *pilha, float valor) {
    if (pilha->topo < pilha->capacidade - 1)
        pilha->dados[++pilha->topo] = valor;
}

float desempilhar(FloatStack *pilha) {
    if (pilha->topo >= 0)
        return pilha->dados[pilha->topo--];
    return 0.0f;
}

void liberarPilha(FloatStack *pilha) {
    if (pilha) {
        free(pilha->dados);
        free(pilha);
    }
}

NodeStack* criarPilhaNos(int capacidade) {
    NodeStack *pilhaN = (NodeStack*)malloc(sizeof(NodeStack));
    if (!pilhaN)
        return NULL;
    pilhaN->dados = (InfixNode*)malloc(capacidade * sizeof(InfixNode));
    pilhaN->topo = -1;
    pilhaN->capacidade = capacidade;
    return pilhaN;
}

void empilharNo(NodeStack *pilhaN, char *texto, int prec) {
    if (pilhaN->topo < pilhaN->capacidade - 1) {
        pilhaN->topo++;
        pilhaN->dados[pilhaN->topo].texto = texto;
        pilhaN->dados[pilhaN->topo].precedencia = prec;
    }
}

InfixNode desempilharNo(NodeStack *pilhaN) {
    InfixNode no = {NULL, 0};
    if (pilhaN->topo >= 0)
        no = pilhaN->dados[pilhaN->topo--];
    return no;
}

void liberarPilhaNos(NodeStack *pilhaN) {
    if (pilhaN) {
        while (pilhaN->topo >= 0) {
            free(pilhaN->dados[pilhaN->topo--].texto);
        }
        free(pilhaN->dados);
        free(pilhaN);
    }
}

int ehOperador(char *simbolo) {
    return (strcmp(simbolo, "+") == 0 || strcmp(simbolo, "-") == 0 ||
            strcmp(simbolo, "*") == 0 || strcmp(simbolo, "/") == 0 ||
            strcmp(simbolo, "%") == 0 || strcmp(simbolo, "^") == 0);
}

int ehFuncao(char *simbolo) {
    return (strcmp(simbolo, "raiz") == 0 || strcmp(simbolo, "sen") == 0 ||
            strcmp(simbolo, "cos") == 0 || strcmp(simbolo, "tg") == 0 ||
            strcmp(simbolo, "log") == 0);
}

int precedencia(char *op) {
    if (strcmp(op, "^") == 0) return PREC_POW;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0) return PREC_MUL;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return PREC_ADD;
    return 0;
}

float calcular(char *op, float operando1, float operando2, int isBinary, int *erro) {
    *erro = 0;
    if (isBinary) {
        if (strcmp(op, "+") == 0)
            return operando1 + operando2;
        if (strcmp(op, "-") == 0)
            return operando1 - operando2;
        if (strcmp(op, "*") == 0)
            return operando1 * operando2;
        if (strcmp(op, "/") == 0) {
            if (operando2 == 0) {
                fprintf(stderr, "Erro: Divisao por zero.\n");
                *erro = 1;
                return 0;
            }
            return operando1 / operando2;
        }
        if (strcmp(op, "^") == 0)
            return powf(operando1, operando2);
        if (strcmp(op, "%") == 0)
            return fmodf(operando1, operando2);
    } else {
        if (strcmp(op, "raiz") == 0) {
            if (operando2 < 0) {
                fprintf(stderr, "Erro: Raiz quadrada de numero negativo.\n");
                *erro = 1;
                return 0;
            }
            return sqrtf(operando2);
        }
        if (strcmp(op, "log") == 0) {
            if (operando2 <= 0) {
                fprintf(stderr, "Erro: Logaritmo de numero nao positivo.\n");
                *erro = 1;
                return 0;
            }
            return log10f(operando2);
        }
        float rad = operando2 * (M_PI / 180.0f);
        if (strcmp(op, "sen") == 0)
            return sinf(rad);
        if (strcmp(op, "cos") == 0)
            return cosf(rad);
        if (strcmp(op, "tg") == 0)
            return tanf(rad);
    }
    *erro = 1;
    return 0;
}

float getValorPosFixa(char *StrPosFixa) {
    if (!StrPosFixa || strlen(StrPosFixa) == 0)
        return 0.0f;

    char *copia = strdup(StrPosFixa);
    if (!copia)
        return 0.0f;

    FloatStack *pilha = criarPilha(512);
    char *simbolo = strtok(copia, " ");
    int erro = 0;

    while (simbolo != NULL) {
        if (isdigit(simbolo[0]) || (simbolo[0] == '-' && isdigit(simbolo[1])) || simbolo[0] == '.') {
            empilhar(pilha, strtof(simbolo, NULL));
        } else if (ehOperador(simbolo)) {
            if (pilha->topo < 1) {
                fprintf(stderr, "Erro de expressao: Operandos insuficientes para '%s'.\n", simbolo);
                erro = 1; break;
            }
            float operando2 = desempilhar(pilha);
            float operando1 = desempilhar(pilha);
            int erroMath = 0;
            float resultado = calcular(simbolo, operando1, operando2, 1, &erroMath);
            if (erroMath) { erro = 1; break; }
            empilhar(pilha, resultado);
        } else if (ehFuncao(simbolo)) {
            if (pilha->topo < 0) {
                fprintf(stderr, "Erro de expressao: Operando insuficiente para '%s'.\n", simbolo);
                erro = 1; break;
            }
            float operando = desempilhar(pilha);
            int erroMath = 0;
            float resultado = calcular(simbolo, 0, operando, 0, &erroMath);
            if (erroMath) { erro = 1; break; }
            empilhar(pilha, resultado);
        } else {
            fprintf(stderr, "Erro de expressao: Token '%s' invalido.\n", simbolo);
            erro = 1; break;
        }
        simbolo = strtok(NULL, " ");
    }

    float resultado = 0.0f;
    if (!erro && pilha->topo == 0)
        resultado = desempilhar(pilha);
    else if (!erro && pilha->topo > 0)
        fprintf(stderr, "Erro de expressao: Elementos restantes na pilha.\n");

    free(copia);
    liberarPilha(pilha);
    return resultado;
}

char * getFormaInFixa(char *Str) {
    if (!Str)
        return NULL;

    char *copia = strdup(Str);
    if (!copia)
        return NULL;

    NodeStack *pilha = criarPilhaNos(512);
    char *simbolo = strtok(copia, " ");
    int erro = 0;

    while (simbolo != NULL) {
        if (isdigit(simbolo[0]) || (simbolo[0] == '-' && isdigit(simbolo[1])) || simbolo[0] == '.') {
            char *textoOperando = strdup(simbolo);
            empilharNo(pilha, textoOperando, PREC_ATOM);
        }
        else if (ehOperador(simbolo)) {
            if (pilha->topo < 1) {
                erro = 1;
                fprintf(stderr, "Erro de conversao: Operandos insuficientes para '%s'.\n", simbolo);
                break;
            }

            InfixNode direito = desempilharNo(pilha);
            InfixNode esquerdo = desempilharNo(pilha);
            int precAtual = precedencia(simbolo);

            char *textoEsq, *textoDir;

            if (esquerdo.precedencia < precAtual) {
                textoEsq = (char*)malloc(strlen(esquerdo.texto) + 3);
                sprintf(textoEsq, "(%s)", esquerdo.texto);
            } else {
                textoEsq = strdup(esquerdo.texto);
            }

            int precisaParDir = 0;
            if (direito.precedencia < precAtual)
                precisaParDir = 1;
            else if (direito.precedencia == precAtual && strcmp(simbolo, "^") != 0)
                precisaParDir = 1;

            if (precisaParDir) {
                textoDir = (char*)malloc(strlen(direito.texto) + 3);
                sprintf(textoDir, "(%s)", direito.texto);
            } else {
                textoDir = strdup(direito.texto);
            }

            char *novaStr = (char*)malloc(strlen(textoEsq) + strlen(textoDir) + strlen(simbolo) + 1);
            sprintf(novaStr, "%s%s%s", textoEsq, simbolo, textoDir);

            empilharNo(pilha, novaStr, precAtual);

            free(textoEsq);
            free(textoDir);
            free(esquerdo.texto);
            free(direito.texto);
        }
        else if (ehFuncao(simbolo)) {
            if (pilha->topo < 0) {
                erro = 1;
                fprintf(stderr, "Erro de conversao: Operando insuficiente para funcao '%s'.\n", simbolo);
                break;
            }

            InfixNode noFunc = desempilharNo(pilha);

            char *novaStr = (char*)malloc(strlen(simbolo) + strlen(noFunc.texto) + 3);
            sprintf(novaStr, "%s(%s)", simbolo, noFunc.texto);

            empilharNo(pilha, novaStr, PREC_ATOM);
            free(noFunc.texto);
        }
        else {
            erro = 1;
            fprintf(stderr, "Erro de conversao: Token '%s' desconhecido.\n", simbolo);
            break;
        }
        simbolo = strtok(NULL, " ");
    }

    char *resultado = NULL;
    if (!erro && pilha->topo == 0) {
        InfixNode noFinal = desempilharNo(pilha);
        resultado = noFinal.texto;
    } else {
        liberarPilhaNos(pilha);
        resultado = NULL;
    }

    free(copia);

    if (pilha) {
        free(pilha->dados);
        free(pilha);
    }

    return resultado;
}