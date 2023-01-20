#include <limits.h>
#include <stdlib.h>

#include "lista.h"

struct lista {
  // local de armazenamento
  int *elementos;
  // quantidade de índices *usados*
  unsigned int quantidade;
  // quantidade de índices *alocados*
  unsigned int capacidade;
};

struct it_lista {
  ListaInt *lista;
  // Índice do próximo elemento a ser reportado
  unsigned int i_elemento;
};

ListaIntIterador *it_lista_criar(ListaInt *lista) {
  ListaIntIterador *novo_it = malloc(sizeof(struct it_lista));

  novo_it->lista = lista;
  novo_it->i_elemento = 0;

  return novo_it;
}

void it_lista_apagar(ListaIntIterador *it) {
  free(it);
}

bool it_lista_tem_proximo(ListaIntIterador *it) {
  return it->i_elemento < it->lista->quantidade;
}

int it_lista_obter_elemento(ListaIntIterador *it) {
  return it->lista->elementos[it->i_elemento];
}

void it_lista_avancar(ListaIntIterador *it) {
  ++it->i_elemento;
}

// Cria uma liva lista
ListaInt *lista_criar() {
  ListaInt *nova_lista = malloc(sizeof(struct lista));

  nova_lista->elementos = NULL;
  nova_lista->capacidade = 0;
  nova_lista->quantidade = 0;

  return nova_lista;
}

void lista_apagar(ListaInt *lista) {
  if(lista->elementos != NULL) {
    free(lista->elementos);
  }
  free(lista);
}

static
void lista_garante_capacidade(ListaInt *lista, unsigned int capacidade_minima) {
  if(lista->capacidade < capacidade_minima) {
    // Realocar o vetor `elementos`
    // `realloc` se encarrega de transportar os dados anteriores
    // para a nova porção de memória.
    lista->elementos = realloc(lista->elementos, capacidade_minima*sizeof(int));
    lista->capacidade = capacidade_minima;
  }
}

void lista_inserir(ListaInt *lista, int elemento) {
  lista_garante_capacidade(lista, lista->quantidade + 1);

  // Supondo que existe capacidade
  lista->elementos[lista->quantidade] = elemento;
  ++lista->quantidade;
}

void lista_inserir_ordenado(ListaInt *lista, int elemento) {
  lista_garante_capacidade(lista, lista->quantidade + 1);

  if (lista->quantidade == 0) {
    lista->elementos[lista->quantidade] = elemento;
    ++lista->quantidade;
  }

  int j;
  for (j = lista->quantidade - 1; j >= 0 && lista->elementos[j] > elemento;
       --j) {
    lista->elementos[j + 1] = lista->elementos[j];
  }

  lista->elementos[j + 1] = elemento;
  ++lista->quantidade;
}

int lista_remover(ListaInt *lista, unsigned int indice) {
  if (indice >= lista->quantidade) {
    return INT_MIN;
  }

  lista->elementos[indice] = lista->elementos[lista->quantidade - 1];
  --lista->quantidade;

  // TODO: Retornar valor que foi removido
}

int lista_remover_ordenado(ListaInt *lista, unsigned int indice) {
  if (indice >= lista->quantidade) {
    return INT_MIN;
  }

  int i;

  for (i = indice; i < lista->quantidade - 1; ++i) {
    lista->elementos[i] = lista->elementos[i + 1];
  }
  --lista->quantidade;

  // TODO: Retornar valor que foi removido
}

bool lista_buscar(ListaInt *lista, int elemento) {
  unsigned int i;
  for (i = 0; i < lista->quantidade; ++i) {
    if (lista->elementos[i] == elemento) {
      return true;
    }
  }

  return false;
}

int lista_buscar_indice_ordenado(ListaInt *lista, int elemento) {
  unsigned int inicio, fim, meio;

  if (lista->quantidade == 0) {
    return -1;
  }

  inicio = 0;
  fim = lista->quantidade - 1;

  while (inicio <= fim) {
    meio = inicio + (fim - inicio) / 2;

    if (elemento == lista->elementos[meio]) {
      return meio;
    } else if (elemento < lista->elementos[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }

  return -1;
}

bool lista_buscar_ordenado(ListaInt *lista, int elemento) {
  // TODO: Aproveitar chamando `lista_buscar_indice_ordenado`
}

int lista_obter_reverso(ListaInt *lista, unsigned int r_indice){
    return lista->elementos[lista->quantidade - r_indice - 1];
}