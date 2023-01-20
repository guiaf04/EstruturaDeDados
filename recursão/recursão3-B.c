#include <stdio.h>

int soma_digitos_natural(int n){
    if(n < 10){
        return n;
    }else{
        return soma_digitos_natural(n/10) + (n % 10);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", soma_digitos_natural(n));

    return 0;
}