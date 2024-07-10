#ifndef ALBUM_H_
#define ALBUM_H_

// Definizione del tipo puntatore a una struttura 'categorie', rappresentante un album
typedef struct categorie* album;

// ----------------------------------------------------------------------------
// Funzioni principali per la gestione degli album
// ----------------------------------------------------------------------------

// Funzione per aggiungere un nuovo album
album aggiungiAlbum(const char *titolo, const char *genere, const char *autore, const int anno);

// Funzione per deallocare la memoria occupata da un album
void freeAlbum(album nuovoAlbum);

// ----------------------------------------------------------------------------
// Funzioni di input da tastiera per titolo, genere, autore e anno
// ----------------------------------------------------------------------------

void titoloAlbum(char **titolo);
void genereAlbum(char **genere);
void autoreAlbum(char **autore);
void annoAlbum(int *anno);

// Funzioni di input da tastiera per la ricerca di album
void titoloAlbumRicerca(char **titolo);
void genereAlbumRicerca(char **genere);
void autoreAlbumRicerca(char **autore);
void annoAlbumRicerca(int *anno);

// Funzioni di input da tastiera per la modifica di album
void titoloAlbumModifica(char **titolo);
void titoloAlbumRimozione(char **titolo);

// ----------------------------------------------------------------------------
// Funzioni per la modifica di titolo, autore, genere e anno di un album
// ----------------------------------------------------------------------------

void modificaTitolo(album a, const char *nuovoTitolo);
void modificaAutore(album a, const char *nuovoAutore);
void modificaGenere(album a, const char *genere);
void modificaAnno(album a, int nuovoAnno);

// ----------------------------------------------------------------------------
// Funzioni di accesso per ottenere titolo, genere, autore e anno di un album
// ----------------------------------------------------------------------------

const char *prendiTitolo(album album);
const char *prendiGenere(album album);
const char *prendiAutore(album album);
int prendiAnno(album album);

#endif 
