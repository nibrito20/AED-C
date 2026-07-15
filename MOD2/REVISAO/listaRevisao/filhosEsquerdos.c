#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
}Arv;

void inserir(Arv **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Arv*)malloc(sizeof(Arv));
        (*raiz)->valor = n;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        return;
    }

    if(n < (*raiz)->valor) inserir(&(*raiz)->esq, n);
    else if(n > (*raiz)->valor) inserir(&(*raiz)->dir, n);
}

void filhosEsquerdos(Arv *raiz){
    if(raiz == NULL) return;
    if(raiz->esq != NULL) printf("%d ", raiz->esq->valor);
    filhosEsquerdos(raiz->esq);
    filhosEsquerdos(raiz->dir);
}

int main(){

    Arv *raiz = NULL;

    inserir(&raiz, 4);
    inserir(&raiz, 2);
    inserir(&raiz, 7);
    inserir(&raiz, 1);
    inserir(&raiz, 3);
    inserir(&raiz, 5);
    inserir(&raiz, 8);

    filhosEsquerdos(raiz);
    
    return 0;
}