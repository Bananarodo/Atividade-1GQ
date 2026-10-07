#include <stdlib.h>
#include <stdio.h>
#include "musica.h"
#include "lista.h"

int proxima = 0;

int adiciona_musica(Lista playlist, Musica m){
    return inserir_final(playlist, m);
}

int adiciona_musica_posicao(Lista playlist, Musica m, int pos){
    if(inserir_posicao(playlist, pos, m)){
        if(pos < proxima) proxima++;
        return 1;
    }
    return 0;
}

int remove_musica(Lista playlist, int pos){
    if(remover_posicao(playlist, pos)){
        if(pos < proxima) proxima--;
        return 1;
    }
    return 0;
}

int tempo_restante(Lista playlist){
    int total = 0;
    for(int i = proxima; i < quantidade(playlist); i++){
        total += duracao_musica(acessar_posicao(playlist, i));
    }
    printf("Tempo restante: %d:%02d\n", total / 60, total % 60);
    return total;
}

void play(Lista playlist){
    Musica m = acessar_posicao(playlist, proxima);
    if(m == NULL){
        printf("Fim da playlist\n");
        return;
    }
    printf("Tocando: ");
    imprimir_musica(m);
    proxima++;
}

int musicas_reproduzidas(Lista playlist){
    int n = proxima < quantidade(playlist) ? proxima : quantidade(playlist);
    printf("Músicas reproduzidas: %d\n", n);
    return n;
}

int main(){
    Lista playlist = criar_lista();

    Musica m[10] = {
        criar_musica("Garota de Ipanema", "Tom Jobim",        180),
        criar_musica("Aquarela",          "Toquinho",         240),
        criar_musica("Aguas de Marco",    "Elis Regina",      215),
        criar_musica("Construcao",        "Chico Buarque",    400),
        criar_musica("Tempo Perdido",     "Legiao Urbana",    300),
        criar_musica("Sera",              "Legiao Urbana",    190),
        criar_musica("Como Nossos Pais",  "Elis Regina",      260),
        criar_musica("Pais e Filhos",     "Legiao Urbana",    305),
        criar_musica("Trem das Onze",     "Adoniran Barbosa", 170),
        criar_musica("Anna Julia",        "Los Hermanos",     210)
    };

    for(int i = 0; i < 7; i++) adiciona_musica(playlist, m[i]);
    adiciona_musica_posicao(playlist, m[7], 0);
    adiciona_musica_posicao(playlist, m[8], 3);
    adiciona_musica_posicao(playlist, m[9], quantidade(playlist));

    printf("Playlist com %d musicas\n", quantidade(playlist));
    tempo_restante(playlist);

    play(playlist);
    play(playlist);
    play(playlist);
    musicas_reproduzidas(playlist);
    tempo_restante(playlist);

    printf("Remove musica da posicao 5\n");
    remove_musica(playlist, 5);
    play(playlist);
    tempo_restante(playlist);

    printf("\nMusicas na playlist: %d\n", quantidade(playlist));
    printf("Posicao da proxima musica: %d\n", proxima);

    destruir_lista(playlist);
    return 0;
}
