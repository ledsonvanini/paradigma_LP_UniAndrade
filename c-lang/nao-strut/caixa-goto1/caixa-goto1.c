#include <stdio.h>

// Estrutura para representar uma conta
typedef struct {
    int numero_conta;
    float saldo;
} Conta;

// Função para criar uma conta
void criar_conta(Conta *conta) {
    printf("Digite o número da conta: ");
    scanf("%d", &conta->numero_conta);
    printf("\nDigite o saldo inicial: ");
    scanf("%f", &conta->saldo);
}

// Função para depositar dinheiro em uma conta
void depositar(Conta *conta) {
    float valor;
    printf("\nDigite o valor a depositar: ");
    scanf("%f", &valor);
    conta->saldo += valor;
    printf("\nDepósito de R$%.2f realizado com sucesso.\n", valor);
}

// Função para sacar dinheiro de uma conta
void sacar(Conta *conta) {
    float valor;
    printf("\nDigite o valor a sacar: ");
    scanf("%f", &valor);
    if (valor > conta->saldo) {
        printf("\nSaldo insuficiente.\n");
    } else {
        conta->saldo -= valor;
        printf("\nSaque de R$%.2f realizado com sucesso.\n\n", valor);
    }
}

// Função para consultar o saldo de uma conta
void consultar_saldo(Conta *conta) {
    printf("\nSaldo atual: R$%.2f\n", conta->saldo);
}

int main() {
    Conta conta;
    int opcao;

    // Menu principal
    menu:
    printf("\n------ Caixa Eletronico Fake ---------\n\n");
    printf("1. Criar conta\n");
    printf("2. Acessar conta\n");
    printf("3. Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);
    
    printf("\n------ Caixa Eletronico Fake ---------\n\n");
    switch (opcao) {
        case 1:
            criar_conta(&conta);
            goto menu;
        case 2:
            // Menu da conta
            menu_conta:
            printf("1. Depositar\n");
            printf("2. Sacar\n");
            printf("3. Consultar saldo\n");
            printf("4. Voltar\n");
            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    depositar(&conta);
                    goto menu_conta;
                case 2:
                    sacar(&conta);
                    goto menu_conta;
                case 3:
                    consultar_saldo(&conta);
                    goto menu_conta;
                case 4:
                    goto menu;
                default:
                    printf("\nOpção inválida.\n");
                    goto menu_conta;
            }
        case 3:
            printf("\nSaindo...\n\n");
            return 0;
        default:
            printf("\nOpcao inválida.\n");
            goto menu;
    }

    return 0;
}



