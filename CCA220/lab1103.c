#include <stdio.h>
#include <string.h>

#define MAX_FILA 10
#define MAX_NOME 20

typedef struct {
    char nome[MAX_NOME];
    int senha;
} Cliente;

typedef struct {
    Cliente data[MAX_FILA];
    int head;
    int tail;
    int qtde;
} Fila;

void inicializar_fila(Fila *fila) {
    fila->head = 0;
    fila->tail = 0;
    fila->qtde = 0;
}

int fila_cheia(Fila *fila) {
    return fila->qtde >= MAX_FILA;
}

int fila_vazia(Fila *fila) {
    return fila->qtde == 0;
}

// 1. Inserir na Fila
void entrar_na_fila(Fila *fila, char *nome, int senha) {
    if (fila_cheia(fila)) {
        printf("Fila lotada\n");
    } else {
        strcpy(fila->data[fila->tail].nome, nome);
        fila->data[fila->tail].senha = senha;
        
        printf("Cliente %s adicionado - Senha: %d\n", nome, senha);
        
        // O tail "roda" para o início se chegar no fim do array
        fila->tail = (fila->tail + 1) % MAX_FILA;
        fila->qtde++;
    }
}

// 2. Atender (Remover) Cliente
void atender_cliente(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia\n");
    } else {
        printf("Atendendo: %s (Senha: %d)\n", fila->data[fila->head].nome, fila->data[fila->head].senha);
        
        // O head também "roda" circularmente
        fila->head = (fila->head + 1) % MAX_FILA;
        fila->qtde--;
    }
}

// 3. Mostrar Fila
void mostrar_fila(Fila *fila) {
    if (fila_vazia(fila)) {
        printf("Fila vazia\n");
    } else {
        printf("Fila atual:\n");
        int pos = fila->head;
        for (int i = 0; i < fila->qtde; i++) {
            printf("%d. %s (Senha: %d)\n", i + 1, fila->data[pos].nome, fila->data[pos].senha);
            pos = (pos + 1) % MAX_FILA;
        }
    }
}

// 4. Buscar Cliente por Senha
int buscar_cliente(Fila *fila, int senha) {
    int pos = fila->head;
    for (int i = 0; i < fila->qtde; i++) {
        if (fila->data[pos].senha == senha) {
            printf("Cliente encontrado: %s (Posicao: %d)\n", fila->data[pos].nome, i + 1);
            return 1;
        }
        pos = (pos + 1) % MAX_FILA;
    }
    printf("Cliente nao encontrado\n");
    return 0;
}

// 5. Mostrar Tamanho Atual
void tamanho_fila(Fila *fila) {
    printf("Tamanho da fila: %d\n", fila->qtde);
}

int main(void) {
    Fila fila_atendimento;
    inicializar_fila(&fila_atendimento);
    
    int senha = 1000;
    
    entrar_na_fila(&fila_atendimento, "Maria", senha++);
    entrar_na_fila(&fila_atendimento, "Joao", senha++);
    entrar_na_fila(&fila_atendimento, "Ana", senha++);
    
    printf("\nFila inicial criada com 3 clientes\n");
    mostrar_fila(&fila_atendimento);
    printf("\n");
    
    printf("=== DEMONSTRACAO DAS OPERACOES ===\n");
    
    printf("\n1. Verificar tamanho da fila:\n");
    tamanho_fila(&fila_atendimento);
    
    printf("\n2. Buscar cliente com senha 1001:\n");
    buscar_cliente(&fila_atendimento, 1001);
    
    printf("\n3. Atender proximo cliente:\n");
    atender_cliente(&fila_atendimento);
    mostrar_fila(&fila_atendimento);
    
    printf("\n4. Adicionar novo cliente:\n");
    entrar_na_fila(&fila_atendimento, "Pedro", senha++);
    mostrar_fila(&fila_atendimento);
    
    printf("\n5. Atender todos os clientes restantes:\n");
    while (!fila_vazia(&fila_atendimento)) {
        atender_cliente(&fila_atendimento);
    }
    
    printf("\n6. Tentar atender fila vazia:\n");
    atender_cliente(&fila_atendimento);
    
    printf("\n7. Tamanho final da fila:\n");
    tamanho_fila(&fila_atendimento);
    
    return 0;
}