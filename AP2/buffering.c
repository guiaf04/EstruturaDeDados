#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct fila_circular{
    char *elementos;
    int inicio;
    int fim;
    int capacidade; //B
}Fila;

Fila *fila_criar(int capacidade){
    Fila *nova_fila = malloc(sizeof(Fila));
    
    nova_fila->elementos = malloc(capacidade * sizeof(char));
    nova_fila->inicio = 0;
    nova_fila->fim = 0;
    nova_fila->capacidade = capacidade;
    
    return nova_fila;
}

void fila_devolver(Fila *f){
    free(f->elementos);
    free(f);
}

bool fila_cheia(Fila *f){
    int novo_fim = (f->fim + 1) % f->capacidade;
    
    return f->inicio == novo_fim;    
}

bool fila_vazia(Fila *f){
    return f->inicio == f->fim;
}

void enfileirar(Fila *f, char x){
    f->elementos[f->fim] = x;
    f->fim = (f->fim + 1) % f->capacidade;
}

bool desenfileirar(Fila *f){
    if(fila_vazia(f)){
        return false;
    }
    
    f->inicio = (f->inicio + 1) % f->capacidade;
    
    return true;
}

int quantidade_elementos(Fila *f){
    int cont = 0;
    
    for(int i = f->inicio; i < f->fim; i = (i + 1) % f->capacidade){
        cont++;
    }
    
    return cont;
}

int main(){
    int O, Q, D, T, B; //O = qnt operações, Q = tamanho do quadro D = quadros/segundo, T = tempo de buffering, B = capacidade da fila. 
    scanf("%d %d %d %d %d", &O, &Q, &D, &T, &B);
    
    Fila *f = fila_criar(B);
    char op;
    int tempo = 0;
    
    for(int i = 0; i < 2 * O; i++){
        scanf("%c", &op);
        
        if(op == 'd'){
            int N, cont = 0;
            scanf("%d", &N);
            char str[N];
            scanf("%s", str);
            
            for(int j = 0; j < N; j++){
                if(fila_cheia(f)){
                    cont++;
                }
                enfileirar(f, str[j]);
            }
            
            if(cont == 0){
                printf("OK\n");
            }else{
                printf("SOBRESCRITA %d\n", cont);
            }
        }else if(op == 'q'){
            int num = quantidade_elementos(f);
            if(num < Q){
                if(tempo < T){
                    tempo++;
                    printf("BUFFERING\n");
                }else{
                    printf("QUADRO ");
                    for(int j = 0; j < Q; j++){
                        printf("%c", f->elementos[f->inicio]);
                        desenfileirar(f);
                    }
                    printf("\n");
                    tempo = 0;
                    }
            }
        }
    }

    fila_devolver(f);
}       