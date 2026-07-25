#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "falhas.h"
#include "ArvoreBinaria.h"

NO_DEC* criarNoDecisao(int id, char *pergunta, int folha){

    NO_DEC *novo;
    novo = (NO_DEC*) malloc(sizeof(NO_DEC));

    if(novo == NULL)
        return NULL;

    novo->id = id;
    strcpy(novo->pergunta, pergunta);
    novo->ehFolha = folha;
    novo->solucao[0] = '\0';
    novo->referencia[0] = '\0';
    novo->sim = NULL;
    novo->nao = NULL;

    return novo;
}

void inserirFilho(NO_DEC *pai, NO_DEC *filho, int respSim){

    if(pai == NULL)
        return;

    if(filho == NULL)
        return;

    if(respSim)
        pai->sim = filho;
    else
        pai->nao = filho;
}

int contarDiagnosticos(NO_DEC *raiz) {
    
    if(raiz == NULL)
    return 0;

    if(raiz->ehFolha)
        return 1;

    return contarDiagnosticos(raiz->sim) + contarDiagnosticos(raiz->nao);
}

int contarPerguntas(NO_DEC *raiz){

    if(raiz == NULL)
    return 0;

    if(raiz->ehFolha)
        return 0;

    return contarPerguntas(raiz->sim) + contarPerguntas(raiz->nao) + 1;
}

void navegarDiagnostico(NO_DEC *raiz){}
void exibirArvoreCompleta(NO_DEC *raiz, int nivel){}
void salvarArvoreArquivo(NO_DEC *raiz){}
NO_DEC* carregarArvoreArquivo(FILE *f){}
void registrarSessao(int idDiagnostico, char *data, FILE *f){}