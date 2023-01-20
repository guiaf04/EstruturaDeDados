#include <stdio.h>

int ocorrencias_iguais(char t[], int n1, char p[], int n2, int i, int j){
    int cont;

    if(i == n1 || j == n2){
        return 0;
    }

    if(i < n1){
        if(j < n2){
            if(t[i] == p[j]){
                cont = 1 + ocorrencias_iguais(t, n1, p, n2, i, j +1); 
            }else{
                ocorrencias_iguais(t, n1, p, n2, i, j+1);
            }
        }
        ocorrencias_iguais(t, n1, p, n2, i + 1, 0);
    }

    return cont;
}

int main(){
    int n1, n2;
    scanf("%d", &n1);

    int t[n1];
    for(int i = 0; i < n1; i++){
        scanf("%d", &t[i]);
    }

    scanf("%d", &n2);
    int p[n2];
    for(int i = 0; i < n2; i++){
        scanf("%d", &p[i]);
    }

    printf("%d\n", ocorrencias_iguais(t, n1, p, n2, 0, 0));

    return 0;
}

/*int cont;
    if(n1 == i || n2 == j){
        return 0;
    }
    if(j < n2){
        if(t[i] == p[j]){
            cont = 1 + ocorrencias_iguais(t, n1, p, n2, i, j + 1);
        }else{
            ocorrencias_iguais(t, n1, p, n2, i, j + 1);
        }
    }else if(j == n2){
        ocorrencias_iguais(t, n1, p, n2, i + 1, 0);
    }

    return cont;*/