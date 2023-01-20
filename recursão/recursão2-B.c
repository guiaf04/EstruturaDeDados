#include <stdio.h>

int maximo(int vet[], int n){
    if(n == 0){
        return vet[n];
    }else if(n > 0){
        int aux = maximo(vet, n - 1);
        if(aux > vet[n]){
            return aux;
        }else{
            return vet[n];
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    printf("%d", maximo(vet, n - 1));
}