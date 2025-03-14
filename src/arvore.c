#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"

Aluno* criarAluno(char nome[], char matricula[], char email[]) {
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    strcpy(novo->matricula, matricula);
    strcpy(novo->email, email);
    novo->filho = novo->irmao = NULL;
    return novo;
}

void adicionarFilho(Aluno *pai, Aluno *filho) {
    if (!pai->filho) {
        pai->filho = filho;
    } else {
        Aluno *temp = pai->filho;
        while (temp->irmao) {
            temp = temp->irmao;
        }
        temp->irmao = filho;
    }
}

Aluno* buscarAlunoPorNome(Aluno *raiz, char nome[]) {
    if (!raiz) return NULL;

    // Converter nomes para minúsculas antes de comparar
    char raizNome[50], nomeBusca[50];
    strcpy(raizNome, raiz->nome);
    strcpy(nomeBusca, nome);
    toLowercase(raizNome);
    toLowercase(nomeBusca);

    if (strcmp(raizNome, nomeBusca) == 0) return raiz;

    Aluno *temp = buscarAlunoPorNome(raiz->filho, nome);
    if (temp) return temp;
    return buscarAlunoPorNome(raiz->irmao, nome);
}

void imprimirSubarvore(Aluno *raiz, int nivel) {
    if (!raiz) return;
    for (int i = 0; i < nivel; i++) printf("--");
    printf("%s - Matrícula: %s\n", raiz->nome, raiz->matricula);
    imprimirSubarvore(raiz->filho, nivel + 1);
    imprimirSubarvore(raiz->irmao, nivel);
}

float calcularDesconto(Aluno *raiz, int nivel) {
    if (raiz == NULL) {
        return 0;
    }

    float desconto = 0;
    if (nivel < 5) {
        desconto = (5 - nivel) * 0.01;
    }

    Aluno *filhoAtual = raiz->filho;
    while (filhoAtual != NULL) {
        desconto += calcularDesconto(filhoAtual, nivel + 1);
        filhoAtual = filhoAtual->irmao;
    }

    return desconto;
}

void liberarArvore(Aluno *raiz) {
    if (!raiz) return;
    liberarArvore(raiz->filho);
    liberarArvore(raiz->irmao);
    free(raiz);
}
