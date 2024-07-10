#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "album.h"
#include "lista.h"

// Definizione della struttura 'categorie' che rappresenta un album
struct categorie {
    char *titolo;  // Titolo dell'album
    char *genere;  // Genere musicale dell'album
    char *autore;  // Autore dell'album
    int anno;      // Anno di pubblicazione dell'album
};

// Funzione per acquisire il titolo dell'album da aggiungere
void titoloAlbum(char **titolo) {
    char buffer[100];

    printf("Inserisci il titolo dell'album che vuoi aggiungere: \n");
    scanf("%50[^\n]", buffer);
    
    buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline finale se presente
    
    *titolo = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario

    char temp;
    while((temp = getchar()) != '\n');

    if (*titolo == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il titolo dell'album da cercare
void titoloAlbumRicerca(char **titolo) {
    char buffer[100];

    printf("Inserisci il titolo dell'album che vuoi cercare: \n");
    scanf("%50[^\n]", buffer);
    
    *titolo = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario
    
    char temp;
    while((temp = getchar()) != '\n');

    if (*titolo == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il titolo dell'album da modificare
void titoloAlbumModifica(char **titolo) {
    char buffer[100];

    printf("Inserisci il titolo dell'album che vuoi modificare: ");
    scanf("%50[^\n]", buffer);
    getchar(); // Consuma il newline rimanente

    *titolo = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario

    if (*titolo == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}


// Funzione per acquisire il titolo dell'album da rimuovere
void titoloAlbumRimozione(char **titolo) {
    char buffer[100];

    printf("Inserisci il titolo dell'album che vuoi rimuovere: \n");
    scanf("%50[^\n]", buffer);
    
    buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline finale se presente
    
    *titolo = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario
    
    if (*titolo == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il genere dell'album da aggiungere
void genereAlbum(char **genere) {
    char buffer[100];

    printf("Inserisci il genere dell'album che vuoi aggiungere: \n");
    scanf("%50[^\n]", buffer);

    buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline finale se presente
   

   *genere = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario
    
    char temp;
    while((temp = getchar()) != '\n');

    if (*genere == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il genere dell'album da cercare
void genereAlbumRicerca(char **genere) {
    char buffer[100];

    printf("Inserisci il genere dell'album nuovoAlbum che vuoi cercare: \n");
    scanf("%50[^\n]", buffer);
    
    *genere = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario

    char temp;
    while((temp = getchar()) != '\n');

    if (*genere == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il nome dell'autore dell'album da aggiungere
void autoreAlbum(char **autore) {
    char buffer[100];

    printf("Inserisci il nome dell'autore dell'album che vuoi aggiungere: \n");
    scanf("%50[^\n]", buffer);
    
    buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline finale se presente
    
    *autore = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario

    char temp;
    while((temp = getchar()) != '\n');

    if (*autore == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire il nome dell'autore dell'album da cercare
void autoreAlbumRicerca(char **autore) {
    char buffer[100];

    printf("Inserisci il nome dell'autore dell'album che vuoi cercare: \n");
    scanf("%50[^\n]", buffer);
    
    buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline finale se presente
    
    *autore = strdup(buffer); // Duplica la stringa e assegna lo spazio necessario

    char temp;
    while((temp = getchar()) != '\n');

    if (*autore == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
}

// Funzione per acquisire l'anno di pubblicazione dell'album da aggiungere
void annoAlbum(int *anno) {
    char temp;
    printf("Inserisci l'anno di pubblicazione dell'album che vuoi aggiungere: \n");
    scanf("%d", anno);
    getchar(); // Consuma il carattere newline rimasto nello stdin
}

// Funzione per acquisire l'anno di pubblicazione dell'album da cercare
void annoAlbumRicerca(int *anno) {
    char temp;
    printf("Inserisci l'anno di pubblicazione dell'album che vuoi cercare: \n");
    scanf("%d", anno);
    getchar(); // Consuma il carattere newline rimasto nello stdin
}

// Funzione per creare e aggiungere un nuovo album
album aggiungiAlbum(const char *titolo, const char *genere, const char *autore, int anno) {
    album nuovoAlbum = malloc(sizeof(struct categorie));  // Alloca memoria per un nuovo album
    if (nuovoAlbum == NULL) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        exit(1);
    }
    nuovoAlbum->titolo = strdup(titolo); // Duplica il titolo
    nuovoAlbum->genere = strdup(genere); // Duplica il genere
    nuovoAlbum->autore = strdup(autore); // Duplica l'autore

    if (!nuovoAlbum->titolo || !nuovoAlbum->genere || !nuovoAlbum->autore) {
        printf("ERRORE NELL'ALLOCAZIONE\n");
        free(nuovoAlbum->titolo);
        free(nuovoAlbum->genere);
        free(nuovoAlbum->autore);
        free(nuovoAlbum);
        exit(1);
    }

    nuovoAlbum->anno = anno; // Imposta l'anno di pubblicazione nell'album

    return nuovoAlbum;
}


// Funzione per deallocare la memoria di un album
void freeAlbum(album nuovoAlbum) {
    free(nuovoAlbum->titolo);
    free(nuovoAlbum->genere);
    free(nuovoAlbum->autore);
    free(nuovoAlbum);
}

// Funzione per ottenere il titolo di un album
const char *prendiTitolo(album albumTitolo) {
    if (albumTitolo == NULL) {
        return NULL;
    }
    
    return albumTitolo->titolo;
}

// Funzione per ottenere il genere di un album
const char *prendiGenere(album albumGenere) {
    if (albumGenere == NULL) {
        return NULL;
    }
    
    return albumGenere->genere;
}

// Funzione per ottenere l'autore di un album
const char *prendiAutore(album albumAutore) {
    if (albumAutore == NULL) {
        return NULL;
    }
    
    return albumAutore->autore;
}

// Funzione per ottenere l'anno di pubblicazione di un album
int prendiAnno(album albumAnno) {
    return albumAnno->anno;
}

void modificaTitolo(album a, const char *nuovoTitolo) {
    if (nuovoTitolo && strlen(nuovoTitolo) > 0) {
        if (a->titolo) free(a->titolo);
        a->titolo = strdup(nuovoTitolo);
    }
}

void modificaGenere(album a, const char *nuovoGenere) {
    if (nuovoGenere && strlen(nuovoGenere) > 0) {
        if (a->genere) free(a->genere);
        a->genere = strdup(nuovoGenere);
    }
}

void modificaAutore(album a, const char *nuovoAutore) {
    if (nuovoAutore && strlen(nuovoAutore) > 0) {
        if (a->autore) free(a->autore);
        a->autore = strdup(nuovoAutore);
    }
}

void modificaAnno(album a, int nuovoAnno) {
    if (nuovoAnno > 0) {
        a->anno = nuovoAnno;
    }
}