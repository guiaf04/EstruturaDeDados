#include <stdio.h>

void reverte_vetor(int vet[], int n, int i, int f){
    int aux;
    if(i < n/2){
        aux = vet[i];
        vet[i] = vet[f];
        vet[f] = aux;
        reverte_vetor(vet, n, i + 1, f - 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    reverte_vetor(vet, n, 0, n - 1);
    
    for(int j = 0; j < n; j++){
        printf("%d ", vet[j]);
    }
}