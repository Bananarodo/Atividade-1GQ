#ifndef MUSICA_H
#define MUSICA_H

typedef struct musica* Musica;

Musica criar_musica(char *titulo, char *artista, int duracao);
char *titulo_musica(Musica m);
char *artista_musica(Musica m);
int duracao_musica(Musica m);
void imprimir_musica(Musica m);
void destruir_musica(Musica m);

#endif
