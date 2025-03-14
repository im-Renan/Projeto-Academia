#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario* criarUsuario(char nome[], char matricula[], char cpf[], char email[]) {
    Usuario *novoUsuario = (Usuario*)malloc(sizeof(Usuario));
    if (novoUsuario == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }
    strcpy(novoUsuario->nome, nome);
    strcpy(novoUsuario->matricula, matricula);
    strcpy(novoUsuario->cpf, cpf);
    strcpy(novoUsuario->email, email);
    return novoUsuario;
}

int verificarUsuarioExistente(Usuario usuarios[], int totalUsuarios, char cpf[]) {
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            return 1; // Usu�rio j� existe
        }
    }
    return 0; // Usu�rio n�o existe
}
