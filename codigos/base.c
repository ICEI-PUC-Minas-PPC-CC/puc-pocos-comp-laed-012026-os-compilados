* PROJETO DE AED I - ETAPA 1 (Entrega: 02/06)
 * TÍTULO: Gerenciador de Tarefas
 * GRUPO: Pablo, Daniel, Ronaldo

CÓDIGO EM C:

#include <stdio.h>
#include <stdlib.h>

// 1. ESTRUTURA DO CÓDIGO DE ACORDO COM REQUISITOS DO DIEGO

struct Tarefa {
    int codigo;
    char nome[50];
    int ativa; // 1 para ativa, 0 para excluida
};

int main() {
    // 2. requisito vetor com capacidade para 10 tarefas
    struct Tarefa lista[10];
    int opcao;
    int i;

    //precisamos definir o for aqui, começar ele zerado vazio <--
    
    // 3. laço principal do menu
    do{
        printf("\n--- GERENCIADOR DE TAREFAS ---\n");
        printf("1. - INSERIR TAREFA \n");
        printf("2. - LISTAR TAREFA \n");
        printf("3. - EDITAR TAREFA \n");
        printf("4. - EXLUIR TAREFA \n");
        printf("5. - PESQUISAR TAREFA \n");
        printf("6. - LIMPAR SISTEMA/TAREFAS \n");
        printf("0. - SAIR DO SISTEMA \n");

        printf("DIGITE UMA OPCAO: ");
        scanf(" %d", &opcao);

        switch (opcao){
            case 1:
                printf("Incluindo...\n\n");
                break;
            case 2:
                printf("Incluindo...\n\n");
                break;
            case 3:
                printf("Incluindo...\n\n");
                break;
            case 4:
                printf("AAA\n\n");
                break;
            case 5:
                printf("AAAA\n\n");
                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("[ERRO]\n\n");
                break;

        }
    }while(opcao != 0);

    return 0;
}
