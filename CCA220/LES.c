#include<stdio.h>
#include<stdlib.h>
#define TAM 8

typedef  struct {
    int arr[TAM];
    int qtd; 
} LES; 

int esta_cheia(LES *lista){
    return lista->qtd == TAM;
}

int pos_insercao(LES *lista, int valor){
    int i = 0;
    while(valor > lista->arr[i]){
        i++;
    }
    return i;
}

void deslocar_dir(LES *lista, int pos){
    int i = lista->qtd;
    while(i > pos){
        lista->arr[i] = lista->arr[i-1];
        i--;
    }
}



int inserir(LES * lista, int valor){
    if(esta_cheia(lista)) {
        return 0;
    }
}

int main() {
    return 0;
}