#include <stdio.h>

void quick_sort(int vet[], int tam, int inicio, int fim){
    int l = inicio;
    int r = fim;
    int pivo = vet[inicio];
    
    while(l <= r){
        while(vet[l] < pivo){
            l++;
        }

        while(vet[r] >= pivo){
            r--;
        }

        if(l <= r){
            int aux = vet[l];
            vet[l] = vet[r];
            vet[r] = aux;
            r--;
            l++;
        }
    }

    if(inicio < r){
        quick_sort(vet, tam, inicio, r);
    }
    if(l < fim){
        quick_sort(vet, tam, l, fim);
    }
    
}

int main(){
    int n;

    printf("Digite a quantidade de elementos que deseja inserir: \n");

    scanf("%d", &n);
    
    int vet[n];
    printf("Digite os elementos do vetor: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    quick_sort(vet, n, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}