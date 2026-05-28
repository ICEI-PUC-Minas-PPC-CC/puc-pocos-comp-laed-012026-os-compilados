#include <stdio.h>
//GERENCIADOR DE TAREFAS
int main(){
    int op;



    do{
        printf("========BEM VINDO AO GERENCIADOR DE TAREFAS SELECIONE UMA OPCAO ABAIXO========\n");
        printf("1 - Incluir tarefa: \n");
        printf("2 - Agendar tarefa: \n");
        printf("3 - Editar tarefa: \n");
        printf("4 - Concluir tarefa: \n");
        printf("5 - Excluir tarefa: \n");
        printf("0 - Fechar o sistema: \n");

        printf("Digite uma opcao: ");
        scanf(" %d", &op);

        switch (op){
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
    }while(op != 0);

    return 0;
}


//agendar tarefa
//concluir
//incluir tar
//excluir tarefa
//editar tarefa
//FECHAR O BAGUI
