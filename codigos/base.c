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

    printf("Digite o nome da %dº tarefa: ", indice+1);
    scanf(" %49[^\n]", nameTarefa);
    strcpy(lista[indice].nome, nameTarefa);

    printf("Digite a descrição da tarefa [%s]: ");
    scanf(" %99[^\n]", nameDescricao);
    strcpy(lista[indice].descricao, nameDescricao);

    while (lista[indice].status == 0)
    {
        printf("Digite o status da sua tarefa --> [em andamento]-[pendente]-[concluida]\n -->");
        scanf(" %19[^\n]", status);

        if (strcmp(status, "pendente") == 0)
        {
            lista[indice].status = 0;
            strcpy(lista[indice].statusDescr, "Pendente");
            break;
        } else if (strcmp(status, "em andamento") == 0)
        {
             lista[indice].status = 1;
             strcpy(lista[indice].statusDescr, "Em andamento");

        }else if (strcmp(status, "concluída") == 0)
        {
            strcpy(lista[indice].statusDescr, "Concluída");
            lista[indice].status = 2;
        }


    }

    return 0;
}
int listar_tarefa(int tamanho_indice){
    int i;
    for (i = 0; i < tamanho_indice; i++)
    {
        if (lista[i].ativo != 0)
        {
            printf("\n===============LISTANDO TAREFAS===============\n");
            printf("%dº Tarefa: %s\nStatus: %s\n",i+1, lista[i].nome, lista[i].statusDescr);
            printf("\n==============================\n");
        }


    }
    printf("Digite qualquer caractere e aperte [enter] para continuar: ");
    scanf(" %s");

    return 0;
}

int editar_tarefa(int tamanho_indice){
    int op;
    int i;
    char editando[20];
    char novoNome[99];
    char novoStatus[99];
    char novaDescricao[100];

    printf("\nInforme a tarefa que deseja editar: \n");
    listar_tarefa(tamanho_indice);
    printf("\n[digite do 1 até o número da tarefa máxima que deseja editar]: \n");
    scanf("%d", &op);

    for (i = 0; i < tamanho_indice; i++){
        if (i == (op-1))
        {
            printf("Digite o que deseja editar na tarefa [%s] [digite o que está dentro de <...>]\n\n", lista[i].nome);
            
            printf("O <nome>: %s\n", lista[i].nome);
            printf("A <descricão>: %s\n", lista[i].descricao);
            printf("O <status>: %s\n", lista[i].statusDescr);

            scanf("%19s", editando);

            if (strcmp(editando, "nome") == 0)
            {
                printf("Digite o nome que irá substituir o nome --> %s\n", lista[i].nome);
                scanf(" %99[^\n]", novoNome);

                strcpy(lista[i].nome, novoNome);
            }else if (strcmp(editando, "descrição") == 0)
            {
                printf("Digite a descrição que irá substituir a descrição --> %s\n", lista[i].descricao);
                scanf(" %99[^\n]", novaDescricao);

                strcpy(lista[i].descricao, novaDescricao);
            }else if (strcmp(editando, "status") == 0)
            {
                do
                {
                    printf("Digite o status que irá substituir o status --> %s\n", lista[i].statusDescr);
                    scanf(" %19[^\n]", novoStatus);

                } while (strcmp(novoStatus, "em andamento") != 0 && strcmp(novoStatus, "pendente") != 0 && strcmp(novoStatus, "concluída") != 0);

                if (strcmp(novoStatus, "em_andamento") == 0){
                    lista[i].status = 1;
                    strcpy(lista[i].statusDescr, "Em andamento");
                }else if (strcmp(novoStatus, "pendente") == 0)
                {
                    lista[i].status = 0;
                    strcpy(lista[i].statusDescr, "Pendente");
                }else if (strcmp(novoStatus, "concluída") == 0)
                {
                    lista[i].status = 2;
                    strcpy(lista[i].statusDescr, "Concluída");
                }
                
            }
            
        }
        
    }
 
    return 0;

}

int pesquisar_tarefa(int tamanho_indice){
    int i;
    int encontrou;
    char pesquisa[50];

    printf("Digite o nome da tarefa que deseja pesquisar: ");
    scanf(" %99[^\n]", pesquisa);

    for (i = 0; i < tamanho_indice; i++)
    {
        if (strcmp(lista[i].nome, pesquisa) == 0)
        {
            printf("\n===============TAREFA ENCONTRADA===============\n");
            printf("%dº Tarefa: %s\n", i+1, lista[i].nome);
            printf("Descricao: %s\n", lista[i].descricao);
            printf("Status: %s\n", lista[i].statusDescr);
            printf("\n==============================\n");

            encontrou = 1;
        }
    }

    if (encontrou == 0)
    {
        printf("Tarefa nao encontrada.\n");
    }

    return 0;
}

int excluir_tarefa(int tamanho_indice){
    int op;

    printf("Informe a tarefa que deseja excluir [digite do 1 até o número da tarefa máxima]: ");
    listar_tarefa(tamanho_indice);
    scanf("%d", &op);

    op--;

    for (op; op < tamanho_indice; op++)
    {
        strcpy(lista[op].nome, lista[op+1].nome);
        strcpy(lista[op].descricao, lista[op+1].descricao);
        strcpy(lista[op].statusDescr, lista[op+1].statusDescr);
        lista[op].status = lista[op+1].status;
    }
    
    return tamanho_indice-1;

}

int resumir_tarefas(int tamanho_indice) {
    int i;
    int total;
    int pendentes = 0;
    int em_andamento = 0;
    int concluidas = 0;

    for (i = 0; i < tamanho_indice; i++) {
        if (lista[i].ativo != 0) {
            total++;

            if (lista[i].status == 0) {
                pendentes++;
            } else if (lista[i].status == 1) {
                em_andamento++;
            } else if (lista[i].status == 2) {
                concluidas++;
            }
        }
    }

    printf("\n===== RESUMO DAS TAREFAS =====\n");
    printf("Total de tarefas: %d\n", total);
    printf("Pendentes: %d\n", pendentes);
    printf("Em andamento: %d\n", em_andamento);
    printf("Concluidas: %d\n", concluidas);

    if (total == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
    }

    printf("==============================\n");

    return 0;
}



int main() {
    int opcao;
    int i = 0;
    int tamanho_i;

    setlocale(LC_ALL, "Portuguese");


    do{
        printf("\n===============GERENCIADOR DE TAREFAS===============\n");
        printf("\n1.  INSERIR TAREFA \n");
        printf("\n2.  LISTAR TAREFAS \n");
        printf("\n3.  EDITAR TAREFA \n");
        printf("\n4.  EXCLUIR TAREFA \n");
        printf("\n5.  PESQUISAR TAREFA \n");
        printf("\n6.  LIMPAR SISTEMA/TAREFAS \n");
        printf("\n7. RESUMO DE SUAS TAREFAS \n");
        printf("\n0.  SAIR DO SISTEMA \n");

        printf("\nDIGITE UMA OPCAO: \n");
        scanf(" %d", &opcao);

        switch (opcao){
            case 1:
                printf("\n===============ADICIONE NOVAS TAREFAS===============\n");
                if(i<10){
                    inserir_tarefa(i);
                    lista[i].ativo = 1;
                    i++;
                }
                else{
                    printf("\n[ERRO], Limite de tarefas atingidas\n");
                }
                break;
            case 2:
                listar_tarefa(i);
                break;
            case 3:
                printf("\n===============EDITOR DE TAREFAS===============\n");
                editar_tarefa(i);
                break;
            case 4:
                printf("\n===============EXCLUIDOR DE TAREFAS===============\n");
                i = excluir_tarefa(i); // DEVE TER UM BLOCO DE CÓDIGO QUE IRÁ MANIPULAR A LISTA DE TAREFAS COM BASE NA PESPERCTIVA DE QUE O INDÍCE DIMINUIU, FAZENDO COM QUE POSIÇOES ANTERIORES RECEBAM VALORES QUE ERAM DO INDÍCE SUCESSOR.
                break;
            case 5:
                pesquisar_tarefa(i);
                break;
            case 6:
                i = 0;
                printf("\n===============[ATENÇÃO !!!] Todas as tarefas foram excluidas.===============\n");
                break;
            case 7:
                resumir_tarefas(i);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\n\n[ERRO]\n\n");
                break;

        }
    }while(opcao != 0);

    return 0;
}





