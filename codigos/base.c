// * PROJETO DE AED I - ETAPA 1 (Entrega: 02/06)
//  * TÍTULO: Gerenciador de Tarefas
//  * GRUPO: Pablo, Daniel, Ronaldo

// CÓDIGO EM C:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DO CÓDIGO DE ACORDO COM REQUISITOS DO DIEGO

struct Tarefa {
    char nome[50];
    char descricao[100];
    int status; // 1 para ativa, 0 para excluida 2 para pendente
};
struct Tarefa lista[10];

int inserir_tarefa(int indice){
    char nameTarefa[50];
    char nameDescricao[100];

    printf("Digite o nome da %dº tarefa:\n", indice+1);
    scanf("%49s", nameTarefa);
    strcpy(lista[indice].nome, nameTarefa);

    printf("Digite a descrição da tarefa [%s]: ");
    scanf("%99s", nameDescricao);
    strcpy(lista[indice].descricao, nameDescricao);





    printf("%s\n", lista[indice].nome);
    printf("%s", lista[indice].descricao);

    return 0;
}

int main() {
    // 2. requisito vetor com capacidade para 10 tarefas
    int opcao;
    int i = 0;

    //precisamos definir o for aqui, começar ele zerado vazio <--
    
    // 3. laço principal do menu
    do{
        printf("\n--- GERENCIADOR DE TAREFAS ---\n");
        printf("\n1.  INSERIR TAREFA \n");
        printf("\n2.  LISTAR TAREFAS \n");
        printf("\n3.  EDITAR TAREFA \n");
        printf("\n4.  EXLUIR TAREFA \n");
        printf("\n5.  PESQUISAR TAREFA \n");
        printf("\n6.  LIMPAR SISTEMA/TAREFAS \n");
        printf("\n0.  SAIR DO SISTEMA \n");

        printf("\nDIGITE UMA OPCAO: \n");
        scanf(" %d", &opcao);

        switch (opcao){
            case 1:
                inserir_tarefa(i);
                i++;
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





