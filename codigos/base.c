// PROJETO: GERENCIADOR DE TAREFAS
//NOMES: DANIEL BARBOSA MONTE VERDE, PABLO DE OLIVEIRA, RONALDO ZHU JIA HUI



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct Tarefa {
    char nome[50];
    char descricao[100];
    int status;  // 0 significará pendente; 1 significará em anamento; 2 significará concluída
    char statusDescr[20];
    int ativo;
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
            strcpy(lista[indice].statusDescr, "Pendente");
            break;
        } else if (strcmp(status, "em_andamento") == 0)
        {
             lista[indice].status = 1;
             strcpy(lista[indice].statusDescr, "Em andamento");

        }else if (strcmp(status, "concluída") == 0)
        {
            strcpy(lista[indice].statusDescr, "Concluída");
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
        if (lista[i].ativo != 0)
        {
            printf("=====LISTANDO TAREFAS=====\n");
            printf("%dº Tarefa: %s\nStatus: %s\n",i+1, lista[i].nome, lista[i].statusDescr);
            printf("=============================\n");
        }




    }


    return 0;
}




int main() {
    int opcao;
    int i = 0;
    int tamanho_i;

    setlocale(LC_ALL, "Portuguese");


    do{
        printf("\n--- GERENCIADOR DE TAREFAS ---\n");
        printf("\n1.  INSERIR TAREFA \n");
        printf("\n2.  LISTAR TAREFAS \n");
        printf("\n3.  EDITAR TAREFA \n");
        printf("\n4.  EXCLUIR TAREFA \n");
        printf("\n5.  PESQUISAR TAREFA \n");
        printf("\n6.  LIMPAR SISTEMA/TAREFAS \n");
        printf("\n0.  SAIR DO SISTEMA \n");

        printf("\nDIGITE UMA OPCAO: \n");
        scanf(" %d", &opcao);

        switch (opcao){
            case 1:
                printf("=====ADICIONE NOVAS TAREFAS=====\n");
                if(i<=10){
                    inserir_tarefa(i);
                    lista[i].ativo = 1;
                    i++;
                }
                break;
            case 2:
                listar_tarefa(i);
                break;
            case 3:
                printf("=====EDITOR DE TAREFAS=====");
                break;
            case 4:
                printf("=====EXCLUIDOR DE TAREFAS=====");
                i = i-1; // DEVE TER UM BLOCO DE CÓDIGO QUE IRÁ MANIPULAR A LISTA DE TAREFAS COM BASE NA PESPERCTIVA DE QUE O INDÍCE DIMINUIU, FAZENDO COM QUE POSIÇOES ANTERIORES RECEBAM VALORES QUE ERAM DO INDÍCE SUCESSOR.
                break;
            case 5:
                printf("=====BUSCADOR DE TAREFAS=====\n\n");
                break;
            case 6:
                i = 0;
                printf("Todas as tarefas foram excluidas.\n"); //O INDÍCE FOI ZERADO, MAS AINDA EXISTE A NECESSIDADE DE MANIPULAR A LISTA DE TAREFAS FAZEN DO COM QUE TODOS OS CAMPOS SEJAM ZERADOS.
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





