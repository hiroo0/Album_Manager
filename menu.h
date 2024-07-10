#ifndef MENU_H_
#define MENU_H_

#include "album.h"
#include "albero.h"
#include "lista.h"

// ----------------------------------------------------------------------------
// Funzioni per la gestione del menu di interazione con il catalogo di album
// ----------------------------------------------------------------------------

// Funzione per aggiungere un nuovo album al catalogo
void aggiungiAlbumMenu(Nodo *root);

// Funzioni per cercare un album in base a uno specifico criterio
void cercaAlbumPerTitoloMenu(Nodo root);
void cercaAlbumPerAutoreMenu(Nodo root);
void cercaAlbumPerGenereMenu(Nodo root);
void cercaAlbumPerAnnoMenu(Nodo root);

// Funzione per modificare un album nel catalogo
void modificaAlbumMenu(Nodo root);

// Funzione per rimuovere un album dal catalogo
void rimuoviAlbumMenu(Nodo *root);

// Funzione per elencare gli album presenti nel catalogo
void elencaAlbumMenu(Nodo root);

#endif 
