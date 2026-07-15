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
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    }

    if(n < (*raiz)->valor){
        inserir(&(*raiz)->esq, n);
    } else if(n >(*raiz)->valor){
        inserir(&(*raiz)->dir, n);
    }
}

int contarNos(Arv *raiz){
    if(raiz != NULL){
        return 1 + contarNos(raiz->esq) + contarNos(raiz->dir);
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

    printf("Qtd de nós: %d\n", contarNos(raiz));
    return 0;
}