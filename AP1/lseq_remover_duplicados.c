unsigned int lseq_remover_duplicados(ListaSeqInt *lista) {
    // * IMPLEMENTAR
    int cont = 0;
    for(int i = 0; i < lista->tamanho; i++){ // passa pelo vetor
        for(int j = i + 1; j < lista->tamanho; j++){  // identifica iguais
            if(lista->elementos[j] == lista->elementos[i]){
                for(int k = j; k < lista->tamanho; k++){           // remover iguais ordenadamente 
                    lista->elementos[k] = lista->elementos[k + 1];}//       ''                                        
                lista->tamanho--;                                  //       ''
                cont++; //retorno da função
                j--; // fazer o elemento ser comparado novamente, já que o 'j' seria incrementado após esse laço
            }
        }
    }
    return cont;
}