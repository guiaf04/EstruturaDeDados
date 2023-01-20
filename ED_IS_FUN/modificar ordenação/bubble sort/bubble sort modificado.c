#include <stdbool.h>

bool bubble_sort(int vetor[], int tamanho, int k) {
  int i, j;
  if(k< tamanho){
        for (i = 0; i < tamanho; ++i) {
            for(j = 0; j < tamanho - 1 - i; ++j) {
                if (vetor[j + 1] < vetor[j]) {
                    int temp = vetor[j + 1];
                    vetor[j + 1] = vetor[j];
                    vetor[j] = temp;
                    }
            }
        }
    return true;
    } 
  else
    return false;
}
