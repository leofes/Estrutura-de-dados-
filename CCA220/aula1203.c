#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct {
    Celula *head;
    Celula *tail;
    int qtde;
} Fila;

Celula *criar_celula(int valor) {
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

Fila *criar_fila() {
    Fila *nova = (Fila*) malloc(sizeof(Fila));
    nova->head = NULL;
    nova->tail = NULL;
    nova->qtde = 0;
    return nova;
}

void enfileirar(Fila *fila, int valor) {
    Celula *nova = criar_celula(valor);
    if (fila->qtde == 0) {
        fila->head = nova;
        fila->tail = nova;
    } else {
        fila->tail->proximo = nova;
        nova->anterior = fila->tail;
        fila->tail = nova; // Atualiza o rabo da fila
    }
    fila->qtde++;
}

void desenfileirar(Fila *fila) {
    if (fila->qtde == 0) return; // Proteção caso a fila esteja vazia

    Celula *tmp = fila->head;
    if (fila->qtde > 1) {
        fila->head = fila->head->proximo;
        fila->head->anterior = NULL;
    } else {
        fila->head = NULL;
        fila->tail = NULL; // Corrigido de == para =
    }
    free(tmp);
    fila->qtde--;
}

void imprimir(Fila *fila) {
    Celula *atual = fila->head;
    printf("Fila (Direto): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("| Tamanho: %d\n", fila->qtde);
}

void imprimir_invertido(Fila *fila) {
    Celula *atual = fila->tail;
    printf("Fila (Inverso): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n---------------------------\n");
}

int main() {
    Fila *fila = criar_fila();
    
    enfileirar(fila, 5);
    imprimir(fila);
    imprimir_invertido(fila);
    
    enfileirar(fila, 8);
    imprimir(fila);
    imprimir_invertido(fila);
    
    enfileirar(fila, 4);
    imprimir(fila);
    imprimir_invertido(fila);
    
    enfileirar(fila, 7);
    imprimir(fila);
    imprimir_invertido(fila);
    
    printf("\nRemovendo primeiro elemento...\n");
    desenfileirar(fila);
    imprimir(fila);
    imprimir_invertido(fila);

    return 0;
}