#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

//structs
typedef struct cliente CLIENTE;
struct cliente{
    char nome[256];
    char cpf[12];
    int numero_da_conta;
    float saldo;
};

//structs

//funções

void menuPrincipal(){
    int opcao;
    do{
        printf("1 - Cadastro de cliente\n");
        printf("2 - Ver conta\n");
        printf("3 - Sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            cadastroCliente();
            break;
        case 2:
            verificar();
            break;
        default:
            printf("Opcao invalida!\n");
            getch();
            system("cls");
        case 3:
            printf("Obrigado por sua visita!");
        }
    }while(opcao != 3);
}

void cadastroCliente(){
    FILE * dadosCliente;
    CLIENTE cliente;
    dadosCliente = fopen("dadosCliente.txt", "ab");
    if(dadosCliente == NULL){
        printf("Problemas na abertura do arquivo\n");
    }else{
        fflush(stdin);
        printf("Digite o nome: ");
        gets(cliente.nome);

        fflush(stdin);
        printf("Digite o cpf: ");
        gets(cliente.cpf);

        fflush(stdin);
        printf("Quanto de saldo deseja colocar?");
        scanf("%f", &cliente.saldo);

    /*
    int numero_da_conta;
    struct cliente cliente;
    float saldo;
    */

        fwrite(&cliente, sizeof(CLIENTE),1, dadosCliente);
        fclose(dadosCliente);
        printf("Aperte qualquer tecla para continuar");
        getch();
        system("cls");
    }
}

void verificar(){
    system("cls");
    FILE * dadosCliente;
    CLIENTE cliente;
    dadosCliente = fopen("dadosCliente.txt", "rb");
    if(dadosCliente == NULL){
        printf("Problemas na abertura do arquivo\n");
    }else{
        while(fread(&cliente, sizeof(CLIENTE),1, dadosCliente)== 1){
            printf("Nome: %s", cliente.nome);
            printf("\nCPF: %s", cliente.cpf);
            printf("\nSaldo: %.2f", cliente.saldo);
            printf("\n-------------------------------------------------\n");
        }
    }
    fclose(dadosCliente);
    getch();
    system("cls");
}
//funções


int main()
{
    menuPrincipal();

    return 0;
};

