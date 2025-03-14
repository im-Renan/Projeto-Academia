#ifndef ARVORE_H
#define ARVORE_H

typedef struct Aluno {
    char nome[50];
    char matricula[6]; // 5 dígitos + '\0'
    char email[50];    // Email do aluno
    struct Aluno *filho;
    struct Aluno *irmao;
} Aluno;

Aluno* criarAluno(char nome[], char matricula[], char email[]);
void adicionarFilho(Aluno *pai, Aluno *filho);
Aluno* buscarAlunoPorNome(Aluno *raiz, char nome[]);
void imprimirSubarvore(Aluno *raiz, int nivel);
float calcularDesconto(Aluno *raiz, int nivel);
void liberarArvore(Aluno *raiz);

#endif
