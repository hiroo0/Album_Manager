#ifndef ALBERO_H_
#define ALBERO_H_

#include "album.h"
#include "lista.h"

// Definizione del tipo puntatore a una struttura 'Albero', che rappresenta un nodo dell'albero
typedef struct Albero* Nodo;

// ----------------------------------------------------------------------------
// Funzione getter
// ----------------------------------------------------------------------------
album prendiAlbumTest(Nodo root);
Nodo prendiRamoSinistro(Nodo nodo);
Nodo prendiRamoDestro(Nodo nodo);

// ----------------------------------------------------------------------------
// Funzioni principali dell'albero
// ----------------------------------------------------------------------------

// Funzione per modificare un album
void modificaAlbum(Nodo root, album album, char *nuovoTitolo, char *nuovoGenere, char *nuovoAutore, char *nuovoAnno);

// Funzione che raccoglie gli album dell'albero in una lista
void raccogliAlbum(Nodo root, ListaAlbum lista);

// Funzione che elenca gli album dell'albero secondo un dato criterio
void elencaAlbum(Nodo root, int criterio);

// ----------------------------------------------------------------------------
// Funzioni di gestione dei nodi
// ----------------------------------------------------------------------------

// Funzione per creare un nuovo nodo dell'albero
Nodo creaNodo(album album);

// Funzione per aggiungere un nodo con un album all'albero
Nodo aggiungiNodo(Nodo root, album album);

// Funzione per cercare il massimo valore (ultimo elemento) nell'albero
Nodo cercaMassimo(Nodo root);

// Funzione per rimuovere un nodo con un album dall'albero
Nodo rimuoviNodo(Nodo root, album album);

// Funzione per deallocare la memoria occupata dall'albero
void freeAlbero(Nodo root);

// ----------------------------------------------------------------------------
// Funzioni di ricerca per criterio
// ----------------------------------------------------------------------------

// Funzione per cercare un album per titolo nell'albero
void cercaPerTitolo(Nodo root, album album);

// Funzione per cercare un album per titolo nell'albero con un flag di controllo
void cercaPerTitoloFlag(Nodo root, album album, int *flag);

// Funzione per cercare un album per autore nell'albero
void cercaPerAutore(Nodo root, album album);

// Funzione per cercare un album per autore nell'albero con un flag di controllo
void cercaPerAutoreFlag(Nodo root, album album, int *flag);

// Funzione per cercare un album per anno nell'albero
void cercaPerAnno(Nodo root, album album);

// Funzione per cercare un album per anno nell'albero con un flag di controllo
void cercaPerAnnoFlag(Nodo root, album album, int *flag);

// Funzione per cercare un album per genere nell'albero
void cercaPerGenere(Nodo root, album album);

// Funzione per cercare un album per genere nell'albero con un flag di controllo
void cercaPerGenereFlag(Nodo root, album album, int *flag);

#endif 
