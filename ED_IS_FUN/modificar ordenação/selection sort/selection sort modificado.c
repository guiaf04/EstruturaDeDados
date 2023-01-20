#include <stdio.h>

void selection(int vet[], int n){

    for(int i = 0; i < n ; i++){
        int indice_menor = i, indice_maior = n - i - 1;

        for(int j = i + 1; j < n; j++){
            if(vet[j] < vet[indice_menor]){
               indice_menor = j;
            }
        }
        
        int aux = vet[i];
        vet[i] = vet[indice_menor];
        vet[indice_menor] = aux;

        for (int j = n - i - 1; j > i; j--){
            if(vet[j] > vet[indice_maior]){
                indice_maior = j;
            }
        }
        
        int aux2 = vet[n - i - 1];
        vet[n - i - 1] = vet[indice_maior];
        vet[indice_maior] = aux2;
    }
}

int main(){
    
    int n;
    scanf("%d", &n);
    
    int vet[n];
    for(int i = 0; i < 0; i++){
        scanf("%d", &vet[i]);
    }
    selection(vet, n);
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}