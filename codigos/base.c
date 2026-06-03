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
};
struct Tarefa lista[10];




int main() {
    int opcao;
    int i = 0;

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
                printf("=====ADICIONE NOVAS TAREFAS=====");
                i++;
                break;
            case 2:
                printf("=====LISTA DE TAREFAS=====");
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





