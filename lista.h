#ifndef LISTA_H_
#define LISTA_H_

#include "album.h"

// Definizione di un puntatore a una struttura 'Lista'
typedef struct Lista* ListaAlbum;

// ----------------------------------------------------------------------------
// Funzioni per la gestione della lista di album
// ----------------------------------------------------------------------------

// Funzione per creare una nuova lista di album
ListaAlbum creaListaAlbum();

// Funzione per inizializzare una lista di album
void inizializzaListaAlbum(ListaAlbum lista);

// Funzione per aggiungere un album alla lista
void aggiungiAlbumAllaLista(ListaAlbum lista, album nuovoAlbum);

// Funzione per liberare la memoria allocata per la lista di album
void freeListaAlbum(ListaAlbum lista);

// ----------------------------------------------------------------------------
// Funzioni per l'ordinamento della lista di album
// ----------------------------------------------------------------------------

// Funzione per confrontare due album per artista (usata per l'ordinamento)
int confrontoPerArtista(const void *a, const void *b);

// Funzione per confrontare due album per anno (usata per l'ordinamento)
int confrontoPerAnno(const void *a, const void *b);

// ----------------------------------------------------------------------------
// Funzioni di accesso alla lista di album
// ----------------------------------------------------------------------------

album *prendiAlbum(ListaAlbum lista);
int prendiSize(ListaAlbum lista);

#endif 
