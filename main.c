#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "albero.h"
#include "lista.h"
#include "menu.h"

// Definizione del menu principale
#define MENU                                                                    \
  "------------------------------------------------\n"                          \
  "Menu:\n"                                                                     \
  "1. Aggiungi Album.\n"                                                        \
  "2. Cerca Album per \"titolo\".\n"                                            \
  "3. Cerca Album per \"autore\".\n"                                            \
  "4. Cerca Album per \"genere\".\n"                                            \
  "5. Cerca Album per \"anno\".\n"                                              \
  "6. Modifica Album [INSERIRE TITOLO ALBUM].\n"                                \
  "7. Rimuovi Album [INSERIRE TITOLO ALBUM].\n"                                 \
  "8. Elenca Album.\n"                                                          \
  "9. Esci.\n"                                                                  \
  "------------------------------------------------\n"

int main() {
    Nodo root = NULL;  // Nodo radice dell'albero degli album
    int scelta; 
    char nuovoTitolo[51], nuovoGenere[51], nuovoAutore[51], nuovoAnno[5];       // Variabile per memorizzare la scelta dell'utente
    album nuovoAlbum;
    do {
        // Stampa il menu principale
        printf(MENU);
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);
        getchar(); // per consumare il carattere newline rimasto nello stdin.

        // Gestisce le diverse opzioni del menu
        switch (scelta) {
            case 1:
                aggiungiAlbumMenu(&root);  // Opzione per aggiungere un nuovo album
                break;
            case 2:
                cercaAlbumPerTitoloMenu(root);  // Opzione per cercare un album per titolo
                break;
            case 3:
                cercaAlbumPerAutoreMenu(root);  // Opzione per cercare un album per autore
                break;
            case 4:
                cercaAlbumPerGenereMenu(root);  // Opzione per cercare un album per genere
                break;
            case 5:
                cercaAlbumPerAnnoMenu(root);  // Opzione per cercare un album per anno di pubblicazione
                break;
            case 6:
                modificaAlbumMenu(root);  // Opzione per modificare un album
                break;
            case 7:
                rimuoviAlbumMenu(&root);  // Opzione per rimuovere un album
                break;
            case 8:
                elencaAlbumMenu(root);  // Opzione per elencare gli album
                break;
            case 9:
                printf("Uscita...\n");  // Opzione per uscire dal programma
                break;
            default:
                printf("Scelta non valida.\n");  // Opzione per gestire scelte non valide
                break;
        }
    } while (scelta != 9);  // Il ciclo continua fino a quando l'utente sceglie di uscire

    // Libera la memoria allocata per l'albero degli album
    freeAlbero(root);

    return 0;
}
