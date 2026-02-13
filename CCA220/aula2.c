#include <stdio.h>
#include <stdlib.h>

typedef struct Celula { 
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtd;
}LDE;

Celula * criar_celula(int valor){
    Celula *nova = malloc(sizeof(Celula));
    nova -> proximo = NULL;
    nova -> valor = valor;
    return nova;
}

LDE *criar_lista(){
    LDE *nova = malloc(sizeof(LDE));
    nova -> primeiro = NULL;
    nova -> qtd = 0;
    return nova;
}

void imprimir(LDE *lista){
    Celula *atual = lista -> primeiro;

    while(atual != NULL){
        printf("%d" , atual -> valor);
        atual = atual -> proximo;

        printf("\n");

    }
}

void remover(LDE *lista, int valor){
    if (lista -> primeiro  == NULL){
        printf("lista vazia");
    }
    

}



//Inserção lista vazia 
void inserir(LDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    if(lista->qtd == 0){
        lista -> primeiro = nova;
        lista -> qtd++;
    } else {
        Celula *anterior = NULL;
        Celula *atual = lista -> primeiro;
        while(atual != NULL && atual -> valor <  nova -> valor){
            anterior = atual;
            atual = atual -> proximo;
        }
        // Verificando se a inserção é no final da lista
        if(anterior != NULL && atual == NULL){
            anterior -> proximo = nova;
            lista -> qtd++;
        // Verificando se a inserção é no incício da lista
        }else if(anterior == NULL && atual != NULL){
            nova -> proximo = atual;
            lista -> primeiro = nova; 
            lista -> qtd++;
        // Verificando se a inserção é no meio da lista
        }else if(anterior != NULL && atual != NULL)
            anterior -> proximo = nova;
            nova -> proximo = atual;
            lista -> qtd++; 
        
    }

}


int main() {
    LDE *lista = criar_lista();
    int valores[] = {4, 1, 8, 2, 9, 0, 3, 7, 6, 5};
    for(int i = 0; i < 10; i++){
        inserir(lista, valores[i]);
        imprimir(lista);
    }
    return 0;
}