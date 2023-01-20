#include <stdio.h>

int main(){
    
    int n, r;
    scanf("%d %d", &n, &r);
    r = r % n;
    
    int vet[n];
    int vet2[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }
    
    for(int i = n - r, j = 0; i < n; i++, j++){
        vet2[j] = vet[i];
    }
    
    for(int i = 0, j = r; i < n - r; i++, j++){
        vet2[j] = vet[i];
    }
    
    printf("[ ");    
    for(int i = 0; i < n; i++){
        printf("%d ", vet2[i]);
    }
    printf("]\n");
}