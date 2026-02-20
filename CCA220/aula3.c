#include<stdio.h>
#include<stdlib.h>

typedef struct Celula {
    struct Celula *anterior;
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtde;
} LDDE;

Celula *criar_celula(int valor){ 
    Celula *nova = malloc(sizeof(Celula));
    nova->anterior = NULL;
    nova->proximo = NULL;
    nova->valor = valor;
    return nova;
}

LDDE *criar_lista(){
    LDDE *nova = malloc(sizeof(LDDE));
    nova->primeiro = NULL;
    nova->qtde = 0;

}

void inserir(LDDE *lista, int valor){
    Celula *nova = criar_celula(valor);
    if(lista->qtde == 0){
        //inserção lista vazia
        lista->primeiro = nova;
        lista->qtde++;
        
    } else {
         Celula *anterior = NULL;
         Celula *atual = lista->primeiro;
         while(atual != NULL && atual->valor < valor); {
              anterior = atual;
              atual = atual -> proximo;
         }
         if(anterior == NULL && atual != NULL) {
            lista->primeiro = nova;
            nova->proximo = atual;
            atual->anterior = nova;
            lista->qtde++;
         } else if(anterior != NULL && atual == NULL){
            //inserção no final
            anterior->proximo = nova;
            nova->anterior = anterior;
            lista->qtde++;
         }else if(anterior != NULL && atual != NULL){
            //Inserção no meio
            nova->anterior = anterior;
            anterior->proximo = nova;
            nova->proximo = atual;
            atual->anterior = nova;
            lista->qtde++;
         }
     }

     }

    void imprimir(LDDE *lista){
        Celula *atual = lista->primeiro;
        while(atual != NULL){
            printf("%d", atual->proximo);
            atual = atual->proximo;
        }
        printf("\n");
     }

     int main(){
        LDDE *lista = criar_lista();
        int valores[] = {5, 1, 9, 0, 2, 6, 3, 8, 7, 4};
        for(int i = 0; i , 10; i++){
            inserir(lista, valores[i]);
            imprimir(lista);
        }
        return 0;
     }

     


