#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *dir;
    struct Arv *esq;
} Arv;

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

int arvBalanceada(Arv *raiz){
    if(raiz == NULL) return 1;
    if(raiz->esq != NULL && raiz->esq->valor > raiz->valor) return 0;
    if(raiz->dir != NULL && raiz->dir->valor < raiz->valor) return 0;
    arvBalanceada(raiz->esq);
    arvBalanceada(raiz->dir);
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

    printf("%d\n", arvBalanceada(raiz));

    return 0;
}