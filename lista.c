#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "album.h"
#include "albero.h"
#include "lista.h"

// Definizione della struttura 'Lista' che rappresenta una lista dinamica di album
struct Lista {
    album *Album;   // Array dinamico di album
    int size;       // Numero di elementi attualmente presenti nella lista
    int capienza;   // Capacità massima attuale della lista
};

// Funzione per creare e inizializzare una nuova lista di album
ListaAlbum creaListaAlbum() {
    ListaAlbum lista = malloc(sizeof(struct Lista)); // Allocazione della struttura 'Lista'
    if (lista == NULL) {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    inizializzaListaAlbum(lista); // Inizializza la lista creata
    return lista;
}

// Funzione di inizializzazione di una lista di album
void inizializzaListaAlbum(ListaAlbum lista) {
    lista->size = 0; // Inizializza la dimensione della lista a 0
    lista->capienza = 10; // Inizializza la capacità iniziale della lista a 10
    lista->Album = malloc(lista->capienza * sizeof(album)); // Allocazione iniziale dell'array di album
    if (lista->Album == NULL) {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
}

// Funzione per aggiungere un nuovo album alla lista
void aggiungiAlbumAllaLista(ListaAlbum lista, album nuovoAlbum) {
    // Se la lista ha raggiunto la sua capacità massima, raddoppia la capacità
    if (lista->size == lista->capienza) {
        lista->capienza *= 2;
        lista->Album = realloc(lista->Album, lista->capienza * sizeof(album)); // Rialloca l'array di album
        if (lista->Album == NULL) {
            printf("Errore di allocazione memoria\n");
            exit(1);
        }
    }
    lista->Album[lista->size++] = nuovoAlbum; // Aggiunge il nuovo album alla lista
}

// Funzione per deallocare la memoria occupata dalla lista di album
void freeListaAlbum(ListaAlbum lista) {
    // Dealloca ogni album presente nella lista
    for (int i = 0; i < lista->size; ++i) {
        freeAlbum(lista->Album[i]);
    }
    free(lista->Album); // Dealloca l'array di album
}

// Funzione di confronto per ordinare la lista di album per artista (ordine lessicografico)
int confrontoPerArtista(const void *a, const void *b) {
    album albumA = *(album *)a;
    album albumB = *(album *)b;
    return strcmp(prendiAutore(albumA), prendiAutore(albumB));
}

// Funzione di confronto per ordinare la lista di album per anno
int confrontoPerAnno(const void *a, const void *b) {
    album albumA = *(album *)a;
    album albumB = *(album *)b;
    return prendiAnno(albumA) - prendiAnno(albumB);
}

// Funzione di accesso per ottenere l'array di album dalla lista
album *prendiAlbum(ListaAlbum lista) {
    return lista->Album;
}

// Funzione di accesso per ottenere la dimensione attuale della lista
int prendiSize(ListaAlbum lista) {
    return lista->size;
}
