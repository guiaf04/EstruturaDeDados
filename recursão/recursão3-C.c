#include <stdio.h>

int conversor_binario(int n){
    if(n <= 1){
        return n;
    }else{
        return 10 * (conversor_binario(n/2)) + (n % 2);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", conversor_binario(n));
}