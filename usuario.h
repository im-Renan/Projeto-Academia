#ifndef USUARIO_H
#define USUARIO_H

typedef struct Usuario {
    char nome[50];
    char matricula[6];  // 5 d�gitos + '\0'
    char cpf[12];       // CPF do usu�rio
    char email[50];     // Email do usu�rio
} Usuario;

Usuario* criarUsuario(char nome[], char matricula[], char cpf[], char email[]);
int verificarUsuarioExistente(Usuario usuarios[], int totalUsuarios, char cpf[]);

#endif
