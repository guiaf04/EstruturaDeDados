#include "lista_encadeada.h"

#include <stdlib.h>

//
// !!!!!!======      Não altere a definição das estruturas      ======!!!!!!
//
// ===>>> Veja abaixo o local que você deve editar
//

typedef struct no_lista_encadeada {
    int elemento;
    struct no_lista_encadeada *proximo;
} NoListaEncInt;

struct lista_encadeada {
    struct no_lista_encadeada *primeiro;
    struct no_lista_encadeada *ultimo;
    unsigned int tamanho;
};

struct it_lista_encadeada {
    ListaEncInt *lista;
    struct no_lista_encadeada *atual;
};

//
// ===>>> Altere a porção a seguir com as definições das funções necessárias.
//
// ---------------------------------------------------------------------------------------------------------------------

NoListaEncInt *no_enc_criar(int elemento){
    NoListaEncInt *novo_no = malloc(sizeof(struct no_lista_encadeada));
    
    novo_no->elemento = elemento;
    novo_no->proximo = NULL;
    
    return novo_no;
}

void lenc_inserir_fim(ListaEncInt *lista, int elemento) {
    // * IMPLEMENTAR
    
    NoListaEncInt *atual = lista->primeiro;
    NoListaEncInt *novo_no = no_enc_criar(elemento);
    
    if(lista->primeiro == NULL){
        lista->primeiro = novo_no;
    }else{
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo_no;
    }
}

ListaEncInt *lenc_ordenar(ListaEncInt *lista){ //Q3
    // * IMPLEMENTAR
    NoListaEncInt *atual = lista->primeiro;
    NoListaEncInt *aux = lista->primeiro;
    NoListaEncInt *no_menor = lista->primeiro;
    int menor;
    
    if(lista->primeiro != NULL){
        while(atual->proximo != NULL){
            no_menor = atual;
            menor = atual->elemento;
            
            while(aux != NULL){
                if(aux->elemento < menor){
                    menor = aux->elemento;
                    no_menor = aux;
                }
                aux = aux->proximo;
            }
            
            no_menor->elemento = atual->elemento;
            atual->elemento = menor;
            
            atual = atual->proximo;
            aux = atual;
        }
    }
    
    return lista;
}

ListaEncInt *lenc_entrelacar(ListaEncInt *lista1, ListaEncInt *lista2) { //Q2
    // * IMPLEMENTAR
    NoListaEncInt *atual_l1 = lista1->primeiro;
    NoListaEncInt *atual_l2 = lista2->primeiro;
    
    ListaEncInt *entrelacada = lenc_criar();
    NoListaEncInt *atual_entrelacada = entrelacada->primeiro;
    
    if(lista1->primeiro == NULL){
        entrelacada->primeiro = lista2->primeiro;
    }else if(lista2->primeiro == NULL){
        entrelacada->primeiro = lista1->primeiro;
    }else{
        
        if(lista1->primeiro->elemento < lista2->primeiro->elemento){
            entrelacada->primeiro = lista1->primeiro;
            
            while(atual_l1->proximo != NULL){
                if(atual_l1->elemento < atual_l2->elemento){
                    atual_entrelacada->proximo = atual_l1;
                    atual_l1 = atual_l1->proximo;
                    atual_entrelacada = atual_entrelacada->proximo;
                }else{
                    atual_entrelacada->proximo = atual_l2;
                    atual_l2 = atual_l2->proximo;
                    atual_entrelacada = atual_entrelacada->proximo;
                }
            }
        }else{
            entrelacada->primeiro = lista2->primeiro;
            
            while(atual_l2->proximo != NULL){
                if(atual_l1->elemento < atual_l2->elemento){
                    atual_entrelacada->proximo = atual_l1;
                    atual_l1 = atual_l1->proximo;
                    atual_entrelacada = atual_entrelacada->proximo;
                }else{
                    atual_entrelacada->proximo = atual_l2;
                    atual_l2 = atual_l2->proximo;
                    atual_entrelacada = atual_entrelacada->proximo;
                }
            }
        }
         
    }
    
    return entrelacada;
}

/// (Função privada)
/// Devolver a memória de *todos* os nós da `lista`. Cada nó será passado para a função `free` do C.
///
/// Garantia: Ao final da execução, a lista estará numa configuração *idêntica* à de uma lista vazia.
void lenc_devolver_nos(ListaEncInt *lista) {
    // * IMPLEMENTAR
    NoListaEncInt *atual = lista->primeiro;
    NoListaEncInt *aux;
    
    if(lista->primeiro != NULL){
        while(atual->proximo != NULL){
            aux = atual;
            aux = aux->proximo;
            free(atual);
            atual = aux;
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// !!!!!!======      Não altere a partir daqui.      ======!!!!!!

ListaEncInt *lenc_criar() {
    ListaEncInt *nova_lista = (ListaEncInt *) malloc(sizeof(struct lista_encadeada));

    nova_lista->primeiro = NULL;
    nova_lista->ultimo = NULL;
    nova_lista->tamanho = 0;

    return nova_lista;
}

void lenc_devolver(ListaEncInt *lista) {
    lenc_devolver_nos(lista);
    free(lista);
}

unsigned int lenc_tamanho(ListaEncInt *lista) {
    return lista->tamanho;
}

ItListaEncInt *lenc_criar_iterador(ListaEncInt *lista) {
    ItListaEncInt *novo_it = (ItListaEncInt *) malloc(sizeof(struct it_lista_encadeada));

    novo_it->lista = lista;
    novo_it->atual = lista->primeiro;

    return novo_it;
}

void lenc_devolver_iterador(ListaEncInt const *lista, ItListaEncInt *iterador) {
    if (iterador->lista == lista) {
        free(iterador);
    }
}

bool it_lenc_valido(ItListaEncInt *iterador) {
    return (iterador != NULL && iterador->lista != NULL && iterador->atual != NULL);
}

void it_lenc_avancar(ItListaEncInt *iterador) {
    if(iterador->atual != NULL) {
        iterador->atual = iterador->atual->proximo;
    }
}

int it_lenc_elemento(ItListaEncInt *iterador) {
    return iterador->atual->elemento;
}