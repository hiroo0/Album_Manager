#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "album.h"
#include "albero.h"
#include "lista.h"
#include "menu.h"

// Funzione per aggiungere un album al database
void aggiungiAlbumMenu(Nodo *root) {
    char *titolo, *genere, *autore, temp;
    int anno;
    
    // Chiede all'utente di inserire i dettagli dell'album
    titoloAlbum(&titolo);
 
    genereAlbum(&genere);
    
    autoreAlbum(&autore);
    
    annoAlbum(&anno);
    

    // Crea un nuovo album e lo aggiunge all'albero
    album nuovo = aggiungiAlbum(titolo, genere, autore, anno);
    *root = aggiungiNodo(*root, nuovo);

    // Libera la memoria allocata per le stringhe
    free(titolo);
    free(genere);
    free(autore);
}

// Funzione per cercare un album per titolo nel database
void cercaAlbumPerTitoloMenu(Nodo root) {
    char *titolo;
    titoloAlbumRicerca(&titolo);

    // Crea un album temporaneo con il titolo fornito per la ricerca
    album temp = aggiungiAlbum(titolo, "", "", 0);
    cercaPerTitolo(root, temp);

    // Libera la memoria allocata per le stringhe
    freeAlbum(temp);
    free(titolo);
}

// Funzione per cercare un album per autore nel database
void cercaAlbumPerAutoreMenu(Nodo root) {
    char *autore;
    autoreAlbumRicerca(&autore);

    // Crea un album temporaneo con l'autore fornito per la ricerca
    album temp = aggiungiAlbum("", "", autore, 0);
    cercaPerAutore(root, temp);

    // Libera la memoria allocata per le stringhe
    freeAlbum(temp);
    free(autore);
}

// Funzione per cercare un album per genere nel database
void cercaAlbumPerGenereMenu(Nodo root) {
    char *genere;
    genereAlbumRicerca(&genere);

    // Crea un album temporaneo con il genere fornito per la ricerca
    album temp = aggiungiAlbum("", genere, "", 0);
    cercaPerGenere(root, temp);

    // Libera la memoria allocata per le stringhe
    freeAlbum(temp);
    free(genere);
}

// Funzione per cercare un album per anno di pubblicazione nel database
void cercaAlbumPerAnnoMenu(Nodo root) {
    int anno;
    annoAlbumRicerca(&anno);

    // Crea un album temporaneo con l'anno fornito per la ricerca
    album temp = aggiungiAlbum("", "", "", anno);
    cercaPerAnno(root, temp);

    // Libera la memoria allocata per le stringhe
    freeAlbum(temp);
}

void modificaAlbumMenu(Nodo root) {
    char *titolo = malloc(51 * sizeof(char));
    char nuovoTitolo[51], nuovoGenere[51], nuovoAutore[51], nuovoAnno[5];

    if (!titolo) {
        printf("Errore di allocazione della memoria.\n");
        return;
    }

    titoloAlbumModifica(&titolo);

    album temp = aggiungiAlbum(titolo, "", "", 0);  // album che come criterio ha solo il criterio "titolo" per la ricerca

    printf("Inserire i nuovi dati dell'album (lasciare vuoto per non modificare quel campo):\n");

    printf("Nuovo titolo: ");
    if (fgets(nuovoTitolo, sizeof(nuovoTitolo), stdin)) {
        nuovoTitolo[strcspn(nuovoTitolo, "\n")] = '\0';
    }

    printf("Nuovo genere: ");
    if (fgets(nuovoGenere, sizeof(nuovoGenere), stdin)) {
        nuovoGenere[strcspn(nuovoGenere, "\n")] = '\0';
    }

    printf("Nuovo autore: ");
    if (fgets(nuovoAutore, sizeof(nuovoAutore), stdin)) {
        nuovoAutore[strcspn(nuovoAutore, "\n")] = '\0';
    }

    printf("Nuovo anno: ");
    if (fgets(nuovoAnno, sizeof(nuovoAnno), stdin)) {
        nuovoAnno[strcspn(nuovoAnno, "\n")] = '\0';
    }

    modificaAlbum(root, temp, nuovoTitolo, nuovoGenere, nuovoAutore, nuovoAnno);

    freeAlbum(temp);
    free(titolo);
}



// Funzione per rimuovere un album dal database
void rimuoviAlbumMenu(Nodo *root) {
    char *titolo;
    titoloAlbumRimozione(&titolo);

    // Crea un album temporaneo con il titolo fornito per la ricerca
    album temp = aggiungiAlbum(titolo, "", "", 0);
    *root = rimuoviNodo(*root, temp);

    // Libera la memoria allocata per le stringhe
    freeAlbum(temp);
    free(titolo);
}

// Funzione per elencare gli album nel database in base a un criterio di ordinamento
void elencaAlbumMenu(Nodo root) {
    int criterio;
    printf("Inserisci il criterio di ordinamento:\n1. Autore\n2. Anno\n");
    scanf("%d", &criterio);
    getchar(); // per consumare il carattere newline rimasto nello stdin.

    // Chiama la funzione per l'ordinamento e l'elenco degli album
    elencaAlbum(root, criterio);
}
