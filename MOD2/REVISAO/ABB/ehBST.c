#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    }

    if(n < (*raiz)->valor) return inserir(&(*raiz)->esq, n);
    else if(n > (*raiz)->valor) return inserir(&(*raiz)->dir, n);
}

int ehBST(Arv *raiz, int min, int max){
    if(raiz != NULL){
        if(raiz->valor < min && raiz->valor > max){
            return 0;
        } else{
            ehBST(raiz->esq, min, raiz->valor);
            ehBST(raiz->dir, raiz->valor, max);
            return 1; 
        } 
        if(ehBST(raiz->esq, min, raiz->valor) == 0) return 0;
        if(ehBST(raiz->dir, raiz->valor, max) == 0) return 0;  
    }
    return 0;
}

int ehBST(Arv *raiz, int min, int max){
    if(raiz == NULL) return 1;

    if(raiz->valor < min || raiz->valor > max) return 0;

    if(ehBST(raiz->esq, min, raiz->valor) == 0) return 0;

    if(ehBST(raiz->dir, raiz->valor, max) == 0) return 0;

    return 1;
}

int main(){

    Arv *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);

    printf("%d\n", ehBST(raiz, INT_MIN, INT_MAX));

    return 0;
}