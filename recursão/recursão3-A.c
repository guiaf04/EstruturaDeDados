#include <stdio.h>

int qnt_digitos(int n){
    if(n < 10){
        return 1;
    }else{
        return 1 + qnt_digitos(n / 10);
    }
}

int main(){
    int x;
    scanf("%d", &x);

    printf("%d", qnt_digitos(x));
}