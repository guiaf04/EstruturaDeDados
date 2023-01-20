#include <stdlib.h>
#include <stdbool.h>

typedef struct pilha{
    char *elementos;
    int inicio;
    int fim;
}Pilha;

Pilha *pilha_criar(){
    Pilha *nova_pilha = malloc(sizeof(Pilha));
    
    nova_pilha->elementos = malloc(25000 * sizeof(char));
    nova_pilha->inicio = 0;
    nova_pilha->fim = 0;
    
    return nova_pilha;
}

bool pilha_vazia(Pilha *p){
    if(p->fim == 0){
        return true;
    }else{
        return false;
    }
}

void pilha_inserir(Pilha *p, char c){
    p->elementos[p->fim] = c;
    p->fim++;
}

bool pilha_remover(Pilha *p){
    if(pilha_vazia(p)){
        return false;
    }else{
        p->fim--;
        return true;
    }
}
void pilha_libera(Pilha *p){
    free(p);
}

int main(){
    Pilha *resultado = pilha_criar();
    Pilha *buffer = pilha_criar();
    
    int qnt_op;
    scanf("%d", &qnt_op);
    
    
    char op, auxiliar = '0';
    char texto[50];
    int cont = 0; // saber quantos caracteres foram desfeitos para refazer na mesma quantidade
    
    for(int i = 0; i < qnt_op; i++){
        scanf(" %c", &op);
        
        if(op == 'i'){
            cont = 0; // reinicia, já que o desfazer pegará agora essa nova string colocada
            if(pilha_vazia(buffer) == false){
                buffer->fim = 0;
            }
            
            scanf(" %[^\n]", texto);
            int tam = strlen(texto);
            
            for(int j = 0; j < tam; j++){
                pilha_inserir(resultado, texto[j]);
                cont++;
            }
            
            for(int a = 0; a < resultado->fim; a++){
                printf("%c", resultado->elementos[a]);
            }
            
            printf("$\n");
        }else if(op == 'a'){
            int N;
            scanf("%d", &N);
            cont = N;
            
            if(pilha_vazia(buffer) == false){
                buffer->fim = 0;
            }
            
            for(int k = 0; k < N && resultado->fim != 0; k++){
                pilha_inserir(buffer, resultado->elementos[resultado->fim - 1]);
                pilha_remover(resultado);
            }
            
            for(int m = 0; m < resultado->fim; m++){
                printf("%c", resultado->elementos[m]);
            }
            printf("$\n");
            
        }else if(op == 'd'){
            
            if(auxiliar == 'a'){
                for(int l = 0; l < cont; l++){
                    pilha_inserir(resultado, buffer->elementos[buffer->fim - 1]);
                    pilha_remover(buffer);
                }
            }else{
                for(int l = 0; l < cont; l++){
                    pilha_inserir(buffer, resultado->elementos[resultado->fim - 1]);
                    pilha_remover(resultado);
                }
            }
            
            for(int p = 0; p < resultado->fim; p++){
                printf("%c", resultado->elementos[p]);
            }
            printf("$\n");
        }else if(op == 'r'){
            for(int q = 0; q < cont; q++){
                pilha_inserir(resultado, buffer->elementos[buffer->fim - 1]);
                pilha_remover(buffer);
            }
            
            for(int r = 0; r < resultado->fim; r++){
                printf("%c", resultado->elementos[r]);
            }
            
            printf("$\n");
        }
        
        auxiliar = op;
    }
    
    pilha_libera(resultado);
    pilha_libera(buffer);
}