# Projeto-Academia

# Sistema de Matrícula de Alunos com Desconto

# Descrição:
ste projeto foi desenvolvido para a disciplina de Estruturas de Dados em C. O sistema permite gerenciar matrículas de alunos em uma academia de ginástica, onde um aluno que indica novos membros recebe um desconto com base no nível da árvore de indicação. O desconto é calculado conforme a hierarquia de indicados: 5% para o pai, 4% para o avô, 3% para o bisavô, e assim por diante.

# Autores
- Renan Moreira da Silva
GitHub: iGitHub: [im-Renan](https://github.com/im-Renan)

- Alan Victor Mondego Pimenta
GitHub: GitHub: [Alan-mondego](https://github.com/Alan-mondego)
# Funcionalidades:

Matricular Aluno: Permite a matrícula de novos alunos e a indicação de outros alunos para a academia.
Imprimir Sub-árvore e Desconto: Exibe a sub-árvore de um aluno específico e calcula o desconto total com base no nível de indicação.
Desconto Progressivo: Calcula descontos para alunos com base no número de níveis na árvore de indicações.

# Tecnologias Utilizadas:
- 🖥️ Linguagem de Programação: C
- 🔗 Bibliotecas: Nenhuma biblioteca externa necessária (somente bibliotecas padrão)
Como Executar:

#Requisitos:

Compilador C (GCC ou similar)
Ambiente de desenvolvimento (como IDE ou terminal)
** Compilação e Execução:** 
- I. Compile o código utilizando o GCC ou outro compilador C:
```
gcc -o sistema_matriculas main.c arvore.c usuario.c
```
- II. Execute o programa:
 ```
./sistema_matriculas
```
# Estrutura do Projeto:
```
src/
│
├── arvore.c                 # Implementação das operações da árvore de alunos
├── arvore.h                 # Definições da árvore de alunos
├── usuario.c                # Implementação das operações dos usuários
├── usuario.h                # Definições dos usuários
├── main.c                   # Função principal do prog
```
