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
    }

    if(n < (*raiz)->valor){
        inserir(&(*raiz)->esq, n);
    } else if(n > (*raiz)->valor){
        inserir(&(*raiz)->dir, n);
    }
}

int altura(Arv *raiz){
    if(raiz != NULL){
        return 1 + altura(raiz->esq) ? : altura(raiz->dir);
    }
    return 0;
}

int main(){

    Arv *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);

    printf("Altura da árvore: %d\n", altura(raiz));
    return 0;
}