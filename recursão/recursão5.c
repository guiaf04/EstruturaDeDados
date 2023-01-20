#include <stdio.h>

int numero_binomial(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }else if(k == 1){
        return n;
    }else if(k < n){
        return numero_binomial(n - 1, k) + numero_binomial(n - 1, k -1);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", numero_binomial(n,k));
}