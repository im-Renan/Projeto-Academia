#ifndef USUARIO_H
#define USUARIO_H

typedef struct Usuario {
    char nome[50];
    char matricula[6];  // 5 dígitos + '\0'
    char cpf[12];       // CPF do usuário
    char email[50];     // Email do usuário
} Usuario;

Usuario* criarUsuario(char nome[], char matricula[], char cpf[], char email[]);
int verificarUsuarioExistente(Usuario usuarios[], int totalUsuarios, char cpf[]);

#endif
