#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_VETOR 10

typedef struct HashList {
    int chave;
    struct HashList* prox;
} HashList;

int FuncaoHashing(int num) {
    return num % TAMANHO_VETOR;
}

void InserirNaHash(HashList* tabela[], int pos, int num) {
    HashList* novoElemento = (HashList*)malloc(sizeof(HashList));
    if (!novoElemento) {
        return;
    }

    novoElemento->chave = num;
    novoElemento->prox = tabela[pos];
    tabela[pos] = novoElemento;

    printf("Número %d inserido na posição %d da tabela hash.\n", num, pos);
}

void RemoverDaHash(HashList* tabela[], int num) {
    int pos = FuncaoHashing(num);

    HashList* atual = tabela[pos];
    HashList* anterior = NULL;

    while (atual != NULL && atual->chave != num) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Número %d não encontrado na tabela hash.\n", num);
        return;
    }

    if (anterior == NULL) {
        tabela[pos] = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Número %d removido da posição %d da tabela hash.\n", num, pos);
}

void imprimirTabela(HashList* tabela[]) {
    printf("\nConteúdo da Tabela Hash:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("[%d]: ", i);

        HashList* atual = tabela[i];
        while (atual != NULL) {
            printf("%d ", atual->chave);
            atual = atual->prox;
        }

        printf("\n");
    }
}

int main() {
    HashList* Tabela[TAMANHO_VETOR];

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        Tabela[i] = NULL;
    }

    int op, pos, num;

    do {
        printf("\nMenu:\n\n");
        printf("\t1 - Inserir na Tabela Hash\n");
        printf("\t2 - Remover da Tabela Hash\n");
        printf("\t3 - Imprimir\n");
        printf("\t0 - Sair do programa\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &num);
                pos = FuncaoHashing(num);
                InserirNaHash(Tabela, pos, num);
                break;

            case 2:
                printf("Digite o número a ser removido: ");
                scanf("%d", &num);
                RemoverDaHash(Tabela, num);
                break;
            case 3:
                imprimirTabela(Tabela);
                break;
            case 0:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (op != 0);

    return 0;
}