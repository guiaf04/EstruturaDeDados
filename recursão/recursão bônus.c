#include <stdio.h>

int imprime_seq(int n, int i){
    if(n > 0){
        printf("%d ", n);
        printf("%d ", i);
        imprime_seq(n - 1, i + 1);
    }
}

int main(){
    imprime_seq(10, 0);
}