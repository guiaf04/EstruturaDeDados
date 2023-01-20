void bubble_modificado(int vet[], int n, int k){

    for(int i = 0; i < n; ++i){ // passagem pelo vetor até ficar ordenado
        int cont = 0;
        
        for(int j = 0; j < n - 1 - i; ++j){ // movimentação da janela
            for(int l = 0; l < k; l++){ // tamanho da janela que define a qnt de trocas
                int a = j;
                if(vet[a + 1] < vet[a]){
                    int temp = vet[a + 1];
                    vet[a + 1] = vet[a];
                    vet[a] = temp;
                    
                    cont++;
                }
                a++;
            }
        }
        
        if(cont == 0){
            return;
        } //otimizador, caso seja zero não houve nenhuma troca

        //logo, o vetor está ordenado 
    }
}

void selection(int vetor[], int tamanho){
    int i, j;

    for (i = 0; i < tamanho - 1; ++i) {
        int i_menor = i, i_maior = tamanho - i - 1;
        
        for (j = i + 1; j < tamanho; ++j) {
          if (vetor[j] < vetor[i_menor]) {
            i_menor = j;
          }
        }
        
        int temp = vetor[i];
        vetor[i] = vetor[i_menor];
        vetor[i_menor] = temp;
        
        for (j = i + 1; j < tamanho - i - 1; j++) {
          if (vetor[j] > vetor[i_maior]) {
            i_maior = j;
          }
        }
        
        int temp2 = vetor[tamanho - i - 1];
        vetor[tamanho - i - 1] = vetor[i_maior];
        vetor[i_maior] = temp2;
    }
}