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

int inserir(LES * lista, int valor){
    if(esta_cheia(lista)) {
        return 0;
    }
}

int main() {
    return 0;
}