#include <stdio.h>

void selection_sort(int vetor[], int tamanho){
    int i, j;

    for (i = 0; i < tamanho - 1; ++i) {
        int i_menor = i, i_maior = tamanho - i - 1;
        
        for (j = i + 1; j < tamanho; ++j) {
          if (vetor[j] < vetor[i_menor]) {
            i_menor = j;
          }
        }
        
        int temp = vetor[i];
        vetor[i] = vetor[i_menor];
        vetor[i_menor] = temp;
        
        for (j = i + 1; j < tamanho - i - 1; j++) {
          if (vetor[j] > vetor[i_maior]) {
            i_maior = j;
          }
        }
        
        int temp2 = vetor[tamanho - i - 1];
        vetor[tamanho - i - 1] = vetor[i_maior];
        vetor[i_maior] = temp2;
    }
}

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

void bubble_sort(int vet[], int n, int k){

    for(int i = 0; i < n; ++i){ // passagem pelo vetor até ficar ordenado
        int cont = 0;
        
        for(int j = 0; j < n - 1 - i; ++j){ // movimentação da janela
            for(int l = 0; l < k; l++){ // tamanho da janela que define a qnt de trocas
                int a = j;
                if(vet[a + 1] < vet[a]){
                    int temp = vet[a + 1];
                    vet[a + 1] = vet[a];
                    vet[a] = temp;
                    
                    cont++;
                }
                a++;
            }
        }
        
        if(cont == 0) //otimizador, caso seja zero não houve nenhuma troca
            return;  //logo, o vetor está ordenado 
    }
}

int main() {
  int vetor_s[] = {10, 15, 5, 1, 8, 13, 20};
  int vetor_b[] = {10, 15, 5, 1, 8, 13, 20};
  int vetor_i[] = {10, 15, 5, 1, 8, 13, 20};

  int i;

  selection_sort(vetor_s, 7);
  printf("selection: ");
  for (i = 0; i < 7; ++i) {
    printf("%d ", vetor_s[i]);
  }
  printf("\n");

  insertion_sort(vetor_i, 7);
  printf("insertion: ");
  for (i = 0; i < 7; ++i) {
    printf("%d ", vetor_i[i]);
  }
  printf("\n");

  bubble_sort(vetor_b, 7, 2);
  printf("bubble: ");
  for (i = 0; i < 7; ++i) {
    printf("%d ", vetor_b[i]);
  }
  printf("\n");
}