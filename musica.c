#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musica.h"

struct musica{
    char titulo[100];
    char artista[100];
    int duracao;
};

Musica criar_musica(char *titulo, char *artista, int duracao){
    Musica m = malloc(sizeof(struct musica));
    if(m != NULL){
        strncpy(m->titulo, titulo, 99);
        m->titulo[99] = '\0';
        strncpy(m->artista, artista, 99);
        m->artista[99] = '\0';
        m->duracao = duracao;
    }
    return m;
}

char *titulo_musica(Musica m){
    return m->titulo;
}

char *artista_musica(Musica m){
    return m->artista;
}

int duracao_musica(Musica m){
    return m->duracao;
}

void imprimir_musica(Musica m){
    printf("%s - %s (%d:%02d)\n", m->titulo, m->artista,
           m->duracao / 60, m->duracao % 60);
}

void destruir_musica(Musica m){
    if(m != NULL) free(m);
}
