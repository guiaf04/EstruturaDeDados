#include <stdio.h>

void matar(int vet[], int elementos, int espada){
    
    if(vet[espada] > 0){
        if(espada != elementos - 1){
            for(int i = espada + 1; i < elementos; i++){
                    vet[i] = vet[i + 1];
                }
        }else{
            for(int i = 0; i <= elementos; i++){
                    vet[i] = vet[i + 1];
                }
        }
    }else{
      if(espada > 0){
            for(int i = espada - 1; i < elementos; i++){
                    vet[i] = vet[i + 1];
                }
        }else{
                return;
            }
        } 
}

int main(){
    
    int n, espada, fase;
    scanf("%d %d %d", &n, &espada, &fase);
    espada--;
    
    int elementos = n;
    
    int vet[n];
    for(int i = 0; i < n; i++){
        if(fase > 0){
            if(i % 2 != 0){
                vet[i] = (i + 1) * -1;
            }else
                vet[i] = i + 1;
        }else{
            if(i % 2 == 0){
                vet[i] = (i + 1) * -1;
            }else
                vet[i] = i + 1;
        }
    }
    
    for(int i = 0; i < n; i++){
        int aux = vet[espada];
        
        if(i == 0){
            printf("[ ");
            for(int j = 0; j < n; j++){
                
                if(j == espada && vet[j] > 0){
                    printf("%d", vet[j]);
                    printf("> ");
                }else if(j == espada && vet[j] < 0){
                    printf("<");
                    printf("%d ", vet[j]);
                }
                else{
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
            
            if(aux > 0){
                if(espada < elementos - 1){
                    espada++;
                }else{
                    espada = 0;
                }
            }else{
                if(espada <= 1){
                    espada = elementos - 1;
                }
                else 
                    espada -= 2;
            }
            
            
            printf("[ ");
            for(int j = 0; j < elementos; j++){
                
                if(j == espada && vet[j] > 0){
                    printf("%d", vet[j]);
                    printf("> ");
                }else if(j == espada && vet[j] <0){
                    printf("<");
                    printf("%d ", vet[j]);
                }
                else{
                    printf("%d ", vet[j]);
                }
                
                if(j == elementos -1){
                    printf("]\n");
                }
            }
        }
        
    }
    
}