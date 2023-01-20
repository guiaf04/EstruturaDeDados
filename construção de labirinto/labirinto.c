#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char labirinto[11][11];
char ordem[] = {'e', 'd', 'c', 'b'};

struct posicao{
    int linha;
    int coluna;
};

struct posicao pilha[121];
int topo = 1;

void imprimir_labirinto(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------\n");
}
void inicializar_labirinto(){
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            labirinto[i][j] = '#'; //parede
        }
    }
}

char* embaralhar_ordem(){
    for(int i = 3; i > 0; i--){
        int escolhido = rand()% i;
        char temp = ordem[i];
        ordem[i] = ordem[escolhido];
        ordem[escolhido] = temp;
    }
    return ordem;
}

void imprimir_ordem(){
    for(int i = 0; i < 4; i++){
        printf("%c ", ordem[i]);
    }
    printf("\n");
}

void imprimir_pilha(){
    printf("[");
    for(int i = 0; i < topo; i++){
        printf("l = %d, c = %d", pilha[i].linha, pilha[i].coluna);
    }
    printf("] \n");
}

void push(int linha, int coluna){
    pilha[topo].linha = linha;
    pilha[topo].coluna = coluna;
    topo++;
}

void pop(){
    topo--;
}

void olhar_vizinho(struct posicao pilha, char movimento){
    if(movimento == 'e'){
        push(pilha.linha, pilha.coluna - 1);
    }else if(movimento == 'd'){
        push(pilha.linha, pilha.coluna + 1);
    }else if(movimento == 'c'){
        push(pilha.linha - 1, pilha.coluna);
    }else if(movimento == 'b'){
        push(pilha.linha + 1, pilha.coluna);
    }
}

bool movimento_possivel(struct posicao *pilha, char* movimento, int i){
    olhar_vizinho(pilha[topo], movimento[i]);
    if(pilha[topo].linha < 0 || pilha[topo].linha > 11 || pilha[topo].coluna < 0 || pilha[topo].coluna > 11){
        pop();
        return false;
    }else if(labirinto[pilha[topo].linha][pilha[topo].coluna] == ' '){
        pop();
        return false;
    }
    return true;

}

void gerar_labirinto(){
    //TODO
    // 1.Empilhar entrada(se ainda n foi) e por espaço '' na matriz
    // 2. Enquanto pilha não vazia
    //    2.1 embaralhar 'ordem'
    //    2.2 olhar vizinhos do topo da pilha na ordem, um de cada vez
    //          2.2.1 se puder andar para ele, empilhar
    //          2.2.2 se não pudermos, ver próximos vizinhos
    //    2.3 se todos os vizinhos são proibidos, desempilhar
    
    int linha = 10; // começo do 
    int coluna = 0; // labirinto

    push(linha, coluna);
    labirinto[linha][coluna] = ' ';

    while(pilha != NULL){
        char* movimento = embaralhar_ordem();
        int i = 0;
        while(movimento_possivel(pilha, movimento, i)== false || i < 4){
            i++;
            movimento_possivel(pilha, movimento, i);
        }
        linha = pilha[topo].linha;
        coluna = pilha[topo].coluna;

        if(movimento_possivel == true){
            labirinto[linha][coluna] = ' ';
        }
    }
}

int main(){
    inicializar_labirinto();
    gerar_labirinto();
    imprimir_labirinto();
    return 0;
}