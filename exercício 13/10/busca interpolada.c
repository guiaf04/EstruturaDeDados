#include <stdio.h>

void insertion_sort(int vetor[], int tamanho) {
  int i, j;

  for (i = 1; i < tamanho; ++i) {
    int temp = vetor[i];

    for (j = i - 1; j >= 0 && vetor[j] > temp; --j) {
      //j>=0 para evitar que o elemento caia fora do vetor
      vetor[j + 1] = vetor[j]; 
      // temos que mover os elementos maiores que o valor a ser inserido para que o mesmo possa entrar
    }

    vetor[j + 1] = temp;
  }
}

int busca_interpolada(int x, int vet[], int n){
    int i = 0;
    int f = n - 1;

    if (n == 0) {
        return -1;
    }

    while(i <= f){
        float porcentagem = (((vet[f] - x) * 100) / (vet[f] - vet[i]));
        int meio = f - ((porcentagem * (f - i)) / 100);

        if(x < vet[meio]){
            f = meio - 1;
        }else if(vet[meio] == x){
            return meio;
        }else{
            i = meio + 1;
        }
    }

    return -1;
}

int main(){

    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    int x;
    scanf("%d", &x);

    insertion_sort(vet, n);

    printf("%d", busca_interpolada(x, vet, n));
}