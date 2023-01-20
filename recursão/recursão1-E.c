#include <stdio.h>

int somar_de(int n){
    if(n > 0){
        return n + somar_de(n - 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", somar_de(n));

    return 0;
}