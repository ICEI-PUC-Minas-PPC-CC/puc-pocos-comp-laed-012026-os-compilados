#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct Tarefa {
    char nome[50];
    char descricao[100];
    int status; 
    char statusDescr[20];
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
        printf("=====LISTANDO TAREFAS=====\n");
        printf("%dº Tarefa: %s\nStatus: %s\n",i+1, lista[i].nome, lista[i].statusDescr);
        printf("=============================\n");
        
    }
    

    return 0;
}

int editar_tarefa(int tamanho_indice){
    int op;
    int i;
    char editando[20];
    char novoNome[50];
    char novoStatus[20];
    char novaDescricao[100];

    printf("Informe a tarefa que deseja editar [digite do 1 até o número da tarefa máxima]: ");
    listar_tarefa(tamanho_indice);
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
                scanf("%49s", novoNome);

                strcpy(lista[i].nome, novoNome);
            }else if (strcmp(editando, "descrição") == 0)
            {
                printf("Digite a descrição que irá substituir a descrição --> %s\n", lista[i].descricao);
                scanf("%99s", novaDescricao);

                strcpy(lista[i].descricao, novaDescricao);
            }else if (strcmp(editando, "status") == 0)
            {
                do
                {
                    printf("Digite o status que irá substituir o status --> %s\n", lista[i].statusDescr);
                    scanf("%19s", novoStatus);

                } while (strcmp(novoStatus, "em_andamento") != 0 && strcmp(novoStatus, "pendente") != 0 && strcmp(novoStatus, "concluída") != 0);

                if (strcmp(novoStatus, "em_andamento") == 0){
                    lista[i].status = 1;
                    strcpy(lista[i].statusDescr, "Em andamento");
                }else if (strcmp(novoStatus, "pendente"))
                {
                    lista[i].status = 0;
                    strcpy(lista[i].statusDescr, "Pendente");
                }else if (strcmp(novoStatus, "concluída"))
                {
                    lista[i].status = 0;
                    strcpy(lista[i].statusDescr, "Concluída");
                }
                
            }
            
        }
        
    }

    return 0;

}

int excluir_tarefa(int tamanho_indice){
    int op;

    printf("Informe a tarefa que deseja excluir [digite do 1 até o número da tarefa máxima]: ");
    listar_tarefa(tamanho_indice);
    scanf("%d", &op);

    op--;

    for (op; op < tamanho_indice - 1; op++)
    {
        strcpy(lista[op].nome, lista[op+1].nome);
        strcpy(lista[op].descricao, lista[op+1].descricao);
        strcpy(lista[op].statusDescr, lista[op+1].statusDescr);
        lista[op].status = lista[op+1].status;
    }
    
    return tamanho_indice-1;
}




int main() {
    int opcao;
    int i = 0;

    setlocale(LC_ALL, "Portuguese");


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
                editar_tarefa(i);
                break;
            case 4:
                i = excluir_tarefa(i);
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





