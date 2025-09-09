#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

// Recebe NomeArquivo como parâmetro e retorna vetor de Equipes

Equipe * LerDados(char * NomeArquivo) {

    FILE * fp = fopen(NomeArquivo, "r");
    if(fp == NULL) {
        printf("ERRO: o arquivo não pode ser aberto");
        exit(ERRO);
    }
    
    char buffer[200];
    fscanf(fp, "%s", buffer);

    Equipe * X = malloc(20 * sizeof(Equipe));
    int i = 0;

    while (fscanf(fp,
        "%d;%[^;];%[^;];%d;%d;%d;%d;%d;%d;%d;%d\n",
         &X[i].Posicao, // Lendo a posição da equipe (1ª coluna)
         X[i].Estado,   // Lendo estado (incluindo espaços em nomes compostos)
         X[i].Nome,&X[i].Pontos,&X[i].J,&X[i].V,&X[i].E,&X[i].D,&X[i].GP,&X[i].GC,&X[i].SG
         ) == 11) {
                X[i].Aproveitamento = 100 * (float) X[i].Pontos / (float) (3 * X[i].J);                
                i++;
    }

    fclose(fp);
    return X;

}

int getPontos(Equipe * T, int Posicao) {
    
    int i;

    for(i = 0; i < 20; i++) {
        if(T[i].Posicao == Posicao){
            return T[i].Posicao;
        }
    }

    return ERRO;

}

float getAproveitamento(Equipe * T, char * Nome) {

    int i;

    for(i = 0; i < 20; i++) {
        if(T[i].Nome, Nome) {
            return T[i].Aproveitamento;
        }
    }

}

void Insertiontort(Equipe * V, int N){

    Equipe chave; // Elemento que sera insirido na parte ordenada
    int i; // Posicao (ou Cordenada) do elemento chave 
    int j; // Posicao de emento da "parte ordenada" que sera comparada com chave 

    for(i = 1; i < N; i++){
        chave = V[i];
        j = i - 1;

        while (j >= 0 && strcmp(V[j].Nome, chave.Nome) > 0){
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = chave; // Copiando a chave do no ultimo lugar modificado      
    }

}