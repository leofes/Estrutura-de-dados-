#include <stdio.h>
#include <stdlib.h> // Necessário para o malloc

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
         // Corrigido de fila.tail para fila->tail
    }
    fila->tail = nova;
    fila->qtde++;
}

void desenfileirar(Fila *fila){
    if(fila->qtde > 1){
        Celula *tmp = fila->head;
        fila->head->proximo->anterior = NULL;
        fila->head = fila->head->proximo;
        free(tmp);
        fila->qtde--;
    }else if(fila->qtde == 1){
        Celula *tmp = fila->head;
        fila->head = NULL;
        fila->tail == NULL;
        free(tmp);
        fila->qtde--;
    }
}

void imprimir(Fila *fila) {
    Celula *atual = fila->head;
    printf("Fila: ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("(Tamanho: %d)\n", fila->qtde);
}

void imprimir_invertido(Fila *fila){
    Celula *atual = fila->tail
    while(atual != NULL){
        printf("%d", atual->valor);
        atual = atual -> anterior;

    }
}

int main() {
    Fila *fila = criar_fila();
    
    enfileirar(fila, 5);
    imprimir(fila);
    imprimir_invertido(fila)
    enfileirar(fila, 8);
    imprimir(fila);
    imprimir_invertido(fila)
    enfileirar(fila, 4);
    imprimir(fila);
    imprimir_invertido(fila)
    enfileirar(fila, 7);
    imprimir(fila);
    imprimir_invertido(fila);
    desenfileirar(fila);
    imprimir(fila);
    imprimir_invertido(fila);

    return 0;
}