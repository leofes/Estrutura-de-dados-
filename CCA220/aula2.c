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
    return nova
}

LDE *criar_lista(){
    LDE *nova = malloc(sizeof(LDE));
    nova -> primeiro = NULL;
    nova -> qtd = 0;
    return nova;
}

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
        if(anterior != NULL && atual == NULL){
            anterior -> proxuno = nova;
            lista -> qtd++;
        }else if(anterior == NULL && atual != NULL){
            nova -> proximo = atual;
            lista -> primeiro = nova; 
            lista -> qtd++;
        }
        
    }

}


int main() {

    return 0;
}