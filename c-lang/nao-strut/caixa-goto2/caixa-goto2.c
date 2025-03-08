#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define _XOPEN_SOURCE 700

// Estrutura para representar uma conta
typedef struct {
    int numero_conta;
    float saldo;
} Conta;

// Função para criar uma conta
bool criar_conta(Conta *contas, int tamanho, Conta *nova_conta) {
    printf("Digite o número da conta: ");
    scanf("%d", &nova_conta->numero_conta);

    // Verificar se a conta já existe
    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero_conta == nova_conta->numero_conta) {
            printf("Erro: Conta já existe.\n");
            return false;
        }
    }

    printf("Digite o saldo inicial: ");
    scanf("%f", &nova_conta->saldo);

    // Adicionar a nova conta ao array
    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero_conta == 0) {
            contas[i] = *nova_conta;
            return true;
        }
    }

    printf("Erro: Não há espaço para criar uma nova conta.\n");
    return false;
}

// Função para depositar dinheiro em uma conta
bool depositar(Conta *contas, int tamanho) {
    int numero_conta;
    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    // Verificar se a conta existe
    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero_conta == numero_conta) {
            float valor;
            printf("Digite o valor a depositar: ");
            scanf("%f", &valor);

            if (valor <= 0) {
                printf("Erro: Valor de depósito inválido.\n");
                return false;
            }

            contas[i].saldo += valor;
            printf("Depósito de R$%.2f realizado com sucesso.\n", valor);
            return true;
        }
    }

    printf("Erro: Conta não existe.\n");
    return false;
}

// Função para sacar dinheiro de uma conta
bool sacar(Conta *contas, int tamanho) {
    int numero_conta;
    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    // Verificar se a conta existe
    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero_conta == numero_conta) {
            float valor;
            printf("Digite o valor a sacar: ");
            scanf("%f", &valor);

            if (valor <= 0) {
                printf("Erro: Valor de saque inválido.\n");
                return false;
            }

            if (valor > contas[i].saldo) {
                printf("Erro: Saldo insuficiente.\n");
                return false;
            }

            contas[i].saldo -= valor;
            printf("Saque de R$%.2f realizado com sucesso.\n", valor);
            return true;
        }
    }

    printf("Erro: Conta não existe.\n");
    return false;
}

// Função para consultar o saldo de uma conta
bool consultar_saldo(Conta *contas, int tamanho) {
    int numero_conta;
    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    // Verificar se a conta existe
    for (int i = 0; i < tamanho; i++) {
        if (contas[i].numero_conta == numero_conta) {
            printf("Saldo atual: R$%.2f\n", contas[i].saldo);
            return true;
        }
    }

    printf("Erro: Conta não existe.\n");
    return false;
}

int main() {
    
    setlocale(LC_ALL, "Portuguese");

    const int MAX_CONTAS = 100;
    Conta contas[MAX_CONTAS];
    Conta nova_conta;

    // Inicializar as contas
    for (int i = 0; i < MAX_CONTAS; i++) {
        contas[i].numero_conta = 0;
        contas[i].saldo = 0;
    }

    while (1) {
        printf("1. Criar conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Consultar saldo\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (criar_conta(contas, MAX_CONTAS, &nova_conta)) {
                printf("Conta criada com sucesso.\n");
            }
            break;
        case 2:
        case 3:
        case 4:
            // Verificar se há contas criadas
            bool conta_criada = false;
            for (int i = 0; i < MAX_CONTAS; i++) {
                if (contas[i].numero_conta != 0) {
                    conta_criada = true;
                    break;
                }
            }

            if (!conta_criada) {
                printf("Erro: Não há contas criadas.\n");
                break;
            }

            switch (opcao) {
                case 2:
                    depositar(contas, MAX_CONTAS);
                    break;
                case 3:
                    sacar(contas, MAX_CONTAS);
                    break;
                case 4:
                    consultar_saldo(contas, MAX_CONTAS);
                    break;
            }
            break;
        case 5:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Erro: Opção inválida.\n");
    }
}

return 0;

}

