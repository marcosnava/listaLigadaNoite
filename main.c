#include <stdio.h>

#include "ListaDuplamenteLigada.h"

// constantes
enum {
    OP_NAO_SELECIONADA = 0,
    OP_ADICIONAR,
    OP_EXCLUIR,
    OP_LISTAR,
    OP_LISTAR_DEC,
    OP_SAIR
};

// protótipos
int menu();
void listar();
void listarDec();

int main(void)
{
    int opcao = OP_NAO_SELECIONADA;
    int numero = 0;

    inicializar();
    while(opcao != OP_SAIR) {
        opcao = menu();
        switch(opcao) {
            case OP_ADICIONAR:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                adicionar(numero);
                break;
            case OP_EXCLUIR:
                printf("Digite um numero: ");
                scanf("%d", &numero);
                excluir(numero);
                break;
            case OP_LISTAR:
                listar();
                break;
            case OP_LISTAR_DEC:
                listarDec();
                break;
            case OP_SAIR:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
    finalizar(inicio);

    return 0;
}

int menu() {
    int op = OP_NAO_SELECIONADA;

    printf("Menu\n");
    printf("%d - Adicionar\n", OP_ADICIONAR);
    printf("%d - Excluir\n", OP_EXCLUIR);
    printf("%d - Listar\n", OP_LISTAR);
    printf("%d - Listar decrescente\n", OP_LISTAR_DEC);
    printf("%d - Sair\n", OP_SAIR);
    printf("Digite sua opcao: ");
    scanf("%d", &op);

    return op;
}

void listar() {
    int dado;
    if(inicio != NULL) {
        paraInicio();

        do {
            if(getCorrente(&dado)) {
                printf("%d ", dado);
            }
        } while(paraProximo());
        printf("\n");
    }
}

void listarDec() {
    int dado;
    if(inicio != NULL) {
        paraFinal();

        do {
            if(getCorrente(&dado)) {
                printf("%d ", dado);
            }
        } while(paraAnterior());
        printf("\n");
    }
}