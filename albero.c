#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "albero.h"
#include "lista.h"

// Definizione della struttura 'Albero' che rappresenta un albero

struct Albero {
    album nuovoAlbum; // Campo che contiene un album, rappresenta il nodo corrente dell'albero
    Nodo left;        // Puntatore al sottoalbero sinistro
    Nodo right;       // Puntatore al sottoalbero destro
};

album prendiAlbumTest(Nodo root){
        if (root == NULL) {
        return NULL;
    }
    
    return root->nuovoAlbum;
}

Nodo prendiRamoSinistro(Nodo nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    return nodo->left;
}

Nodo prendiRamoDestro(Nodo nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    return nodo->right;
}

// Funzione per raccogliere tutti gli album dall'albero e aggiungerli a una lista
void raccogliAlbum(Nodo root, ListaAlbum lista) {
    if (root == NULL) {
        return;
    }

    // Raccoglie gli album nel sottoalbero sinistro
    raccogliAlbum(root->left, lista);

    // Aggiungi l'album corrente alla lista
    aggiungiAlbumAllaLista(lista, root->nuovoAlbum);

    // Raccoglie gli album nel sottoalbero destro
    raccogliAlbum(root->right, lista);
}

// Funzione per elencare gli album nel catalogo
void elencaAlbum(Nodo root, int criterio) {
    
    if (root == NULL) {
        return;
    }

    // Crea e inizializza la lista
    ListaAlbum lista = creaListaAlbum();

    // Raccogli tutti gli album dall'albero
    raccogliAlbum(root, lista);

    // Ordina la lista in base al criterio
    if (criterio == 1) {
        qsort(prendiAlbum(lista), prendiSize(lista), sizeof(album), confrontoPerArtista);
    } else if (criterio == 2) {
        qsort(prendiAlbum(lista), prendiSize(lista), sizeof(album), confrontoPerAnno);
    }

    // Stampa gli album
    for (int i = 0; i < prendiSize(lista); ++i) {
        album alb = prendiAlbum(lista)[i];
        printf("%s - %s - %s (%d)\n", prendiTitolo(alb), prendiGenere(alb), prendiAutore(alb), prendiAnno(alb));
    }
}

// Funzione per creare un nuovo nodo nell'albero
Nodo creaNodo(album album) {
    Nodo nuovoNodo = malloc(sizeof(struct Albero));

    if (nuovoNodo == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }

    // Aggiunge l'album al nodo
    nuovoNodo->nuovoAlbum = aggiungiAlbum(prendiTitolo(album), prendiGenere(album), prendiAutore(album), prendiAnno(album));
    if (nuovoNodo->nuovoAlbum == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        free(nuovoNodo);
        exit(1);
    }

    nuovoNodo->left = NULL;
    nuovoNodo->right = NULL;
    return nuovoNodo;
}

// Funzione per aggiungere un nodo all'albero
Nodo aggiungiNodo(Nodo root, album album) {
    if (root == NULL) {
        return creaNodo(album);
    }
    if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) < 0) {
        root->left = aggiungiNodo(root->left, album);
    } else if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) > 0) {
        root->right = aggiungiNodo(root->right, album);
    }
    return root;
}

// Funzione di ricerca per titolo con flag
void cercaPerTitoloFlag(Nodo root, album album, int *flag) {
    if (root == NULL) {
        return;
    }

    // Visita il sottoalbero sinistro
    cercaPerTitoloFlag(root->left, album, flag);

    // Controlla il nodo corrente
    if (strcmp(prendiTitolo(root->nuovoAlbum), prendiTitolo(album)) == 0) {
        printf("%s - %s - %s (%d)\n", prendiTitolo(root->nuovoAlbum), prendiGenere(root->nuovoAlbum), prendiAutore(root->nuovoAlbum), prendiAnno(root->nuovoAlbum));
        *flag = 1;
    }

    // Visita il sottoalbero destro
    cercaPerTitoloFlag(root->right, album, flag);
}

// Funzione per cercare un album per titolo
void cercaPerTitolo(Nodo root, album album) {
    int flag = 0;
    cercaPerTitoloFlag(root, album, &flag);
    if (!flag) {
        printf("Nessun album trovato con questo titolo.\n");
    }
}

// Funzione di ricerca per autore con flag
void cercaPerAutoreFlag(Nodo root, album album, int *flag) {
    if (root == NULL) {
        return;
    }

    // Visita il sottoalbero sinistro
    cercaPerAutoreFlag(root->left, album, flag);

    // Controlla il nodo corrente
    if (strcmp(prendiAutore(root->nuovoAlbum), prendiAutore(album)) == 0) {
        printf("%s - %s - %s (%d)\n", prendiTitolo(root->nuovoAlbum), prendiGenere(root->nuovoAlbum), prendiAutore(root->nuovoAlbum), prendiAnno(root->nuovoAlbum));
        *flag = 1;
    }

    // Visita il sottoalbero destro
    cercaPerAutoreFlag(root->right, album, flag);
}

// Funzione per cercare un album per autore
void cercaPerAutore(Nodo root, album album) {
    int flag = 0;
    cercaPerAutoreFlag(root, album, &flag);
    if (!flag) {
        printf("Nessun album trovato con questo autore.\n");
    }
}

// Funzione di ricerca per anno con flag
void cercaPerAnnoFlag(Nodo root, album album, int *flag) {
    if (root == NULL) {
        return;
    }

    // Visita il sottoalbero sinistro
    cercaPerAnnoFlag(root->left, album, flag);

    // Controlla il nodo corrente
    if (prendiAnno(root->nuovoAlbum) == prendiAnno(album)) {
        printf("%s - %s - %s (%d)\n", prendiTitolo(root->nuovoAlbum), prendiGenere(root->nuovoAlbum), prendiAutore(root->nuovoAlbum), prendiAnno(root->nuovoAlbum));
        *flag = 1;
    }

    // Visita il sottoalbero destro
    cercaPerAnnoFlag(root->right, album, flag);
}

// Funzione per cercare un album per anno
void cercaPerAnno(Nodo root, album album) {
    int flag = 0;
    cercaPerAnnoFlag(root, album, &flag);
    if (!flag) {
        printf("Nessun album trovato per questo anno.\n");
    }
}

// Funzione di ricerca per genere con flag
void cercaPerGenereFlag(Nodo root, album album, int *flag) {
    if (root == NULL) {
        return;
    }

    // Visita il sottoalbero sinistro
    cercaPerGenereFlag(root->left, album, flag);

    // Controlla il nodo corrente
    if (strcmp(prendiGenere(root->nuovoAlbum), prendiGenere(album)) == 0) {
        printf("%s - %s - %s (%d)\n", prendiTitolo(root->nuovoAlbum), prendiGenere(root->nuovoAlbum), prendiAutore(root->nuovoAlbum), prendiAnno(root->nuovoAlbum));
        *flag = 1;
    }

    // Visita il sottoalbero destro
    cercaPerGenereFlag(root->right, album, flag);
}

// Funzione per cercare un album per genere
void cercaPerGenere(Nodo root, album album) {
    int flag = 0;
    cercaPerGenereFlag(root, album, &flag);
    if (!flag) {
        printf("Nessun album trovato con questo genere.\n");
    }
}

// Funzione per cercare un album da modificare
Nodo cercaAlbumDaModificare(Nodo root, album album) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) < 0) {
        return cercaAlbumDaModificare(root->left, album);
    } else if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) > 0) {
        return cercaAlbumDaModificare(root->right, album);
    } else {
        return root;
    }
}

// Funzione per modificare un album
void modificaAlbum(Nodo root, album album, char *nuovoTitolo, char *nuovoGenere, char *nuovoAutore, char *nuovoAnno) {
    Nodo nodo = cercaAlbumDaModificare(root, album);
    if (nodo == NULL) {
        printf("Album non trovato.\n");
        return;
    }

    // Modifica i dati dell'album solo se il nuovo campo non è vuoto
    if (strlen(nuovoTitolo) > 0) {
        modificaTitolo(nodo->nuovoAlbum, nuovoTitolo);
    }
    if (strlen(nuovoGenere) > 0) {
        modificaGenere(nodo->nuovoAlbum, nuovoGenere);
    }
    if (strlen(nuovoAutore) > 0) {
        modificaAutore(nodo->nuovoAlbum, nuovoAutore);
    }
    if (strlen(nuovoAnno) > 0) {
        modificaAnno(nodo->nuovoAlbum, atoi(nuovoAnno));
    } 
}

// Funzione per trovare il nodo con il valore massimo nell'albero
Nodo cercaMassimo(Nodo root) {
    if (root->right == NULL) {
        return root;
    }
    return cercaMassimo(root->right);
}

// Funzione per rimuovere un nodo dall'albero
Nodo rimuoviNodo(Nodo root, album album) {
    // Verifica se l'album da rimuovere esiste
    Nodo nodoDaRimuovere = cercaAlbumDaModificare(root, album);
    if (nodoDaRimuovere == NULL) {
        printf("Album non trovato. Impossibile rimuovere.\n");
        return root;
    }
    
    if (root == NULL) {
        return root;
    }
    if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) < 0) {
        root->left = rimuoviNodo(root->left, album);
    } else if (strcmp(prendiTitolo(album), prendiTitolo(root->nuovoAlbum)) > 0) {
        root->right = rimuoviNodo(root->right, album);
    } else {
        // Nodo da rimuovere trovato
        if (root->left == NULL) {
            Nodo temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Nodo temp = root->left;
            free(root);
            return temp;
        }

        Nodo temp = cercaMassimo(root->left);

        modificaTitolo(root->nuovoAlbum, prendiTitolo(temp->nuovoAlbum));
        modificaAutore(root->nuovoAlbum, prendiAutore(temp->nuovoAlbum));
        modificaGenere(root->nuovoAlbum, prendiGenere(temp->nuovoAlbum));
        modificaAnno(root->nuovoAlbum, prendiAnno(temp->nuovoAlbum));

        root->left = rimuoviNodo(root->left, root->nuovoAlbum);
    }

    return root;
}

// Funzione per liberare la memoria dell'albero
void freeAlbero(Nodo root) {
    if (root == NULL) {
        return;
    }
    freeAlbero(root->left);
    freeAlbero(root->right);
    free(root);
}
