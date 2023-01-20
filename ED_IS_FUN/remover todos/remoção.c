#include <stdio.h>

int achar_indice(int vet[], int n, int x){
    int retorno = -1;
    
    for(int i = 0; i < n; i++){
        if(x == vet[i])
            retorno = i;
    }
    return retorno;
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    int qnt_sairam;
    scanf("%d", &qnt_sairam);
    
    int quem_saiu[qnt_sairam];
    for(int i = 0; i < qnt_sairam; i++){
        scanf("%d", &quem_saiu[i]);
    }
    
    for(int i = 0; i < qnt_sairam; i++){
        int indice = achar_indice(vet, n, quem_saiu[i]);
        
        if(indice >= 0){
            for(int i = indice; i < n - 1; i++){
                vet[i] = vet[i+1];
            }
            n--;
        }
    }
    
    for(int i = 0; i < n ; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}