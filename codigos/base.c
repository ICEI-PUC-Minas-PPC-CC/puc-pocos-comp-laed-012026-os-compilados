#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Tarefa {
    char nome[50];
    char descricao[100];
    int status; 
};
struct Tarefa lista[10];




int inserir_tarefa(int indice){
    char nameTarefa[50];
    char nameDescricao[100];
    char status[20];
    lista[indice].status = 0;

    printf("Digite o nome da %dº tarefa:\n", indice+1);
    scanf("%49s", nameTarefa);
    strcpy(lista[indice].nome, nameTarefa);

    printf("Digite a descrição da tarefa [%s]: ");
    scanf("%99s", nameDescricao);
    strcpy(lista[indice].descricao, nameDescricao);

    while (lista[indice].status == 0)
    {
        printf("Digite o status da sua tarefa \n[em_andamento]\n[pendente]\n[concluida]\n");
        scanf("%19s", status);

        if (strcmp(status, "pendente") == 0)
        {
            lista[indice].status = 0;
            break;
        } else if (strcmp(status, "em_andamento") == 0)
        {
             lista[indice].status = 1;
        }else if (strcmp(status, "concluída") == 0)
        {
            lista[indice].status = 2;
        }
        
        
        
    }
    

    printf("%s\n", lista[indice].nome);
    printf("%s\n", lista[indice].descricao);
    printf("%d\n", lista[indice].status);

    return 0;
}

int listar_tarefa(int tamanho_indice){
    int i;
    for (i = 0; i < tamanho_indice; i++)
    {
        printf("=====LISTANDO TAREFAS=====\n");
        printf("%dº Tarefa: %s\nStatus: %d\n",i+1, lista[i].nome, lista[i].status);
        printf("=============================\n");
        
    }
    

    return 0;
}




int main() {
    int opcao;
    int i = 0;


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
                listar_tarefa(i);
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





