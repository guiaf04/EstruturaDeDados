#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void converte_para_minusculo(char vet[], int n){
    for(int i = 0; i < n; i++){
        if(vet[i] != ' ' && vet[i] < 92)
            vet[i] += 32;
    }
}

void remove_espaco(char vet[], int n){
    for(int i = 0; i < n; i++){
        if(vet[i] == ' '){
            for(int j = i; j < n; j++){
                vet[j] = vet[j + 1];
            }
            n--;
            i--;
        }
    }
}

bool palindromo_char(char vet[], int i, int f){
    if(i <= f){
        if(vet[i] == vet[f]){
            return palindromo_char(vet, i + 1, f - 1);
        }else{
            return false;
        }
    }else{
        return true;
    }
}

bool palindromo_int(int vet[], int i, int f){
    if(i <= f){
        if(vet[i] == vet[f]){
            return palindromo_int(vet, i + 1, f - 1);
        }else{
            return false;
        }
    }else{
        return true;
    }
}

int main(){
    char string[100];
    scanf("%[^\n]", string);

    int n;
    scanf("%d", &n);

    int vet[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    converte_para_minusculo(string, strlen(string));
    remove_espaco(string, strlen(string));

    printf("%d\n", palindromo_char(string, 0, strlen(string) - 1));
    printf("%d\n", palindromo_int(vet, 0, n - 1));
}