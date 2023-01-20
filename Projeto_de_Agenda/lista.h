#ifndef QXD_ED_LISTA
#define QXD_ED_LISTA 1

#include <stdbool.h>

struct lista;
struct it_lista;
typedef struct lista ListaInt;
typedef struct it_lista ListaIntIterador;

ListaInt *lista_criar();
void lista_apagar(ListaInt *lista);

void lista_inserir(ListaInt *lista, int elemento);
void lista_inserir_ordenado(ListaInt *lista, int elemento);
int lista_remover(ListaInt *lista, unsigned int indice);
int lista_remover_ordenado(ListaInt *lista, unsigned int indice);
bool lista_buscar(ListaInt *lista, int elemento);
int lista_buscar_indice_ordenado(ListaInt *lista, int elemento);

ListaIntIterador *it_lista_criar(ListaInt *lista);
void it_lista_apagar(ListaIntIterador *it);
bool it_lista_tem_proximo(ListaIntIterador *it);
int it_lista_obter_elemento(ListaIntIterador *it);
void it_lista_avancar(ListaIntIterador *it);
int lista_obter_reverso(ListaInt *lista, unsigned int r_indice);

#endif