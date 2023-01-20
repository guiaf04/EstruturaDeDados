#include <stdio.h>
#include "lista_encadeada.h"

int main(){
    unsigned int tamanho_l1;
    unsigned int tamanho_l2;
    int i;
    int elemento;

    ListaEncInt *l1 = lista_enc_criar();
    ListaEncInt *l2 = lista_enc_criar();

    scanf("%u", &tamanho_l1);

    for (i = 0; i < tamanho_l1; ++i) {
        scanf("%d", &elemento);
        lista_enc_inserir_fim(l1, elemento);
    }

    scanf("%u", &tamanho_l2);

    for (int j = 0; j < tamanho_l2; ++j) {
        scanf("%d", &elemento);
        lista_enc_inserir_fim(l2, elemento);
    }

    int k;
    scanf("%d", &k);

    lista_remendar(l1, l2, k);
    
    ItListaEncInt *it;

    for(it = it_lista_enc_criar(l1); 
    it_lista_enc_eh_valido(it); it_lista_enc_avancar(it)){
        printf("%d ", it_lista_enc_obter_elemento(it));
    }
    
    lista_enc_apagar(l1);
    lista_enc_apagar(l2);

    return 0;    
}

/*
    ListaEncInt *l1 = lista_enc_criar();
    ListaEncInt *l2 = lista_enc_criar();
    int k;
    scanf("%d", &k);
    
    lista_enc_inserir_fim(l1, 5);
    lista_enc_inserir_fim(l1, 7);
    lista_enc_inserir_fim(l1, 2);
    lista_enc_inserir_fim(l1, 4);
    lista_enc_inserir_fim(l1, 7);
    lista_enc_inserir_fim(l1, 8);
    lista_enc_inserir_fim(l2, 3);
    lista_enc_inserir_fim(l2, 45);
    lista_enc_inserir_fim(l2, 12);
    lista_enc_inserir_fim(l2, 2);
    lista_enc_inserir_fim(l2, 5);

    lista_remendar(l1, l2, k);
    
    for (ItListaEncInt *i = it_lista_enc_criar(l1); it_lista_enc_eh_valido(i); it_lista_enc_avancar(i))
    {
        printf("%d", it_lista_enc_obter_elemento(i));
    }
    */