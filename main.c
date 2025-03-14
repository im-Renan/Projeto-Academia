#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "arvore.h"
#include "usuario.h"

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Aluno *raiz = NULL;
    Usuario usuarios[100];
    int totalUsuarios = 0;
    char nome[50], cpf[6], indicador[50], email[50];
    int opcao;

    do {
        printf("\n1. Matricular Aluno\n2. Imprimir Sub-árvore e Desconto\n3. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Nome do novo aluno: ");
            scanf(" %[^\n]", nome);
            printf("Digite os 5 primeiros dígitos do seu CPF para ser usado como matrícula: ");
            scanf(" %[^\n]", cpf);

            // Gerar matrícula com os 5 primeiros dígitos do CPF
            char matricula[6]; // 5 dígitos + '\0'
            strncpy(matricula, cpf, 5);
            matricula[5] = '\0';

            // Verificar se o usuário já está cadastrado
            if (verificarUsuarioExistente(usuarios, totalUsuarios, cpf)) {
                printf("Usuário já cadastrado!\n");
                continue;
            }

            // Solicitar email apenas para o primeiro aluno
            if (totalUsuarios == 0) {
                printf("Email do aluno: ");
                scanf(" %[^\n]", email);
            } else {
                strcpy(email, ""); // Para alunos subsequentes, o email não é necessário
            }

            // Adicionar usuário à lista de usuários
            usuarios[totalUsuarios++] = *criarUsuario(nome, matricula, cpf, email);

            if (raiz == NULL) {
                // Primeiro aluno é a raiz
                raiz = criarAluno(nome, matricula, email);
                printf("Aluno %s matriculado como raiz.\n", nome);
            } else {
                // Alunos subsequentes precisam de um indicador
                printf("Nome do aluno que indicou: ");
                scanf(" %[^\n]", indicador);
                toLowercase(indicador);

                Aluno *indicadorAluno = buscarAlunoPorNome(raiz, indicador);
                if (indicadorAluno) {
                    Aluno *novoAluno = criarAluno(nome, matricula, email);
                    adicionarFilho(indicadorAluno, novoAluno);
                    printf("Aluno %s matriculado com sucesso.\n", nome);
                } else {
                    printf("Indicador não encontrado.\n");
                }
            }
        } else if (opcao == 2) {
            printf("Nome do aluno para imprimir a sub-árvore: ");
            scanf(" %[^\n]", nome);
            toLowercase(nome);
            Aluno *aluno = buscarAlunoPorNome(raiz, nome);
            if (aluno) {
                imprimirSubarvore(aluno, 0);
                float desconto = calcularDesconto(aluno, 0);
                printf("Desconto total: %.2f%%\n", desconto * 100);
            } else {
                printf("Aluno não encontrado.\n");
            }
        } else if (opcao != 3) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    liberarArvore(raiz);
    printf("Programa encerrado.\n");
    return 0;
}
