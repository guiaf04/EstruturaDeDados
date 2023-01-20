#include <stdio.h>

void imprime_contrario(int vet[], int n){
    if(n > 0){
        printf("%d ", vet[n - 1]);
        imprime_contrario(vet, n - 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    imprime_contrario(vet, n);
}