#include <stdlib.h>
#include "lista.h"

struct no{
    Musica musica;
    struct no *prox;
};
typedef struct no* No;

struct lista{
    No inicio;
    int qtd;
};

Lista criar_lista(){
    Lista l = malloc(sizeof(struct lista));
    if(l != NULL){
        l->inicio = NULL;
        l->qtd = 0;
    }
    return l;
}

int inserir_inicio(Lista l, Musica m){
    No novo = malloc(sizeof(struct no));
    if(novo == NULL) return 0;
    novo->musica = m;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->qtd++;
    return 1;
}

int inserir_posicao(Lista l, int pos, Musica m){
    if(pos < 0 || pos > l->qtd) return 0;
    if(pos == 0) return inserir_inicio(l, m);

    No novo = malloc(sizeof(struct no));
    if(novo == NULL) return 0;

    No ant = l->inicio;
    for(int i = 0; i < pos - 1; i++) ant = ant->prox;

    novo->musica = m;
    novo->prox = ant->prox;
    ant->prox = novo;
    l->qtd++;
    return 1;
}

int inserir_final(Lista l, Musica m){
    return inserir_posicao(l, l->qtd, m);
}

int remover_posicao(Lista l, int pos){
    if(pos < 0 || pos >= l->qtd) return 0;

    No rem;
    if(pos == 0){
        rem = l->inicio;
        l->inicio = rem->prox;
    }else{
        No ant = l->inicio;
        for(int i = 0; i < pos - 1; i++) ant = ant->prox;
        rem = ant->prox;
        ant->prox = rem->prox;
    }
    destruir_musica(rem->musica);
    free(rem);
    l->qtd--;
    return 1;
}

int remover_primeira(Lista l){
    return remover_posicao(l, 0);
}

int remover_ultima(Lista l){
    return remover_posicao(l, l->qtd - 1);
}

Musica acessar_primeira(Lista l){
    if(l->qtd > 0) return l->inicio->musica;
    return NULL;
}

Musica acessar_posicao(Lista l, int pos){
    if(pos < 0 || pos >= l->qtd) return NULL;
    No atual = l->inicio;
    for(int i = 0; i < pos; i++) atual = atual->prox;
    return atual->musica;
}

int quantidade(Lista l){
    return l->qtd;
}

void destruir_lista(Lista l){
    if(l == NULL) return;
    No atual = l->inicio;
    while(atual != NULL){
        No prox = atual->prox;
        destruir_musica(atual->musica);
        free(atual);
        atual = prox;
    }
    free(l);
}
