#include <stdio.h>

void matar(int vet[], int elementos, int espada){
    if(espada != elementos - 1){
        for(int i = espada + 1; i < elementos; i++){
                vet[i] = vet[i + 1];
            }
    }else{
        for(int i = 0; i <= elementos; i++){
                vet[i] = vet[i + 1];
            }
    }
    
}

int main(){
    
    int n, espada;
    scanf("%d %d", &n, &espada);
    espada--;
    int elementos = n;
    
    
    int vet[n];
    for(int i = 0; i < n; i++){
        vet[i] = i + 1;
    }
    
    for(int i = 0; i < n; i++){
        if(i == 0){
            printf("[ ");
            for(int j = 0; j < n; j++){
                
                if(j == espada){
                    printf("%d", vet[j]);
                    printf("> ");
                }else{
                    printf("%d ", vet[j]);
                }
                
                if(j == n -1){
                    printf("]\n");
                }
            }
        }
        else{
            matar(vet, elementos, espada);
            elementos--;
            
            if(espada < elementos - 1){
                espada++;
            }else{
                espada = 0;
            }
            
            printf("[ ");
            for(int j = 0; j < elementos; j++){
                
                if(j == espada){
                    printf("%d", vet[j]);
                    printf("> ");
                }else{
                    printf("%d ", vet[j]);
                }
                
                if(j == elementos -1){
                    printf("]\n");
                }
            }
        }
        
    }
    
}