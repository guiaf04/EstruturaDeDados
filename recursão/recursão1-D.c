#include <stdio.h>

void contar_de(int n){
    if(n >= 0){
        if(n % 2 == 0){
            printf("%d ", n);
            contar_de(n - 1);
        }else{
            contar_de(n - 1); // retorna para imprimir os pares e depois imprime os ímpares de forma crescente;
            printf("%d ", n);
        }
    }
}

int main(){
    contar_de(10);
}