#include "lista_sequencial.h"
#include <stdlib.h>

// *** Altere este arquivo com as definições das funções e estruturas
// *** necessárias.
struct ListaSeq{
    int *elementos;
    int capacidade;
    int quantidade;
};

struct ItListaSeq{
    ListaSeq *lista;
    unsigned int i_elemento;
};

ItListaSeq *lseq_criar_iterador(ListaSeq *lista){
  ItListaSeq *novo_it = malloc(sizeof(struct ItListaSeq));

  novo_it->lista = lista;
  novo_it->i_elemento = 0;

  return novo_it;
}

void lseq_inserir_fim(ListaSeq *lista, int elemento){
    ++lista->quantidade;
    lista->elementos[quantidade] = elemento;
}

ListaSeq *lseq_criar(){
    ListaSeq *nova_lista = malloc(sizeof(struct ListaSeq));
    
    nova_lista->elementos = NULL;
    nova_lista->capacidade = 0;
    nova_lista->quantidade = 0;
    
    return nova_lista;
}

bool it_lseq_valido(ItListaSeq *iterador){
      return iterador->i_elemento < iterador->lista->quantidade;
}

void it_lseq_avancar(ItListaSeq *iterador){
      ++iterador->i_elemento;
}

void lseq_devolver_iterador(ListaSeq *lista, ItListaSeq *iterador){
    if(iterador->elementos != NULL){
        free(iterador->elementos);
    }
    free(iterador);
}

void lseq_devolver(ListaSeq *lista) {
  if(lista->elementos != NULL){
    free(lista->elementos);
  }
  free(lista);
}

void lseq_remover_menores_que(ListaSeq *lista, int elemento){
    int cont = 0;
    
    for(int i = 0; i < lista->quantidade; i++){
        if(lista->elementos == elemento){
            cont++;
        }
        
        if(cont == 0){
            return;
        }else if(cont == lista->quantidade){
            lseq_devolver(lista);
        }else{
            for(int j = 0; j < lista->quantidade; j++){
                if(lista->elementos == elemento){
                    ItListaSeq->elementos[j] = lista->elementos[j + 1];
                }
            }
        }
        
    }
}

void lseq_inserir_varios(ListaSeq *lista, unsigned int indice, unsigned int num, int novos[]){
    
    if(indice >= lista->quantidade){
        for(int i = 0; i < num; i++){
            lseq_inserir_fim(lista, novos[i]);
        }
    }else
    
    if(num == 0){
        return;
    }else{
        int capacidade_minima = lista->quantidade + num;
        lista->elementos = realloc(lista->elementos, capacidade_minima*sizeof(int));
        lista->capacidade = capacidade_minima;
        lista->quantidade += num;
        
        for(int i = indice, j = indice + num; i < indice + num && j < lista->quantidade; i++, j++){
            lista->elementos[j] = lista->elementos[i];
        }
    
        for(int i = indice, j = 0; i <= indice + num && j < num; j++, i++){
            lista->elementos[i] = novos[j];
        }
    }
}