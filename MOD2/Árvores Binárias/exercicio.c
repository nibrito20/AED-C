#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int chave;
    struct Arv *dir;
    struct Arv *esq;
} Arv;

void inserir(Arv **raiz, int n){
    if(*raiz == NULL){
        *raiz = (Arv*)malloc(sizeof(Arv));
        (*raiz)->chave = n;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
    } else{
        if((*raiz)->chave < n){
            inserir(&(*raiz)->dir, n);
        } else if((*raiz)->chave > n){
            inserir(&(*raiz)->esq, n);
        }
    }
}

void pre_ordem(Arv *raiz){ // RED
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void in_ordem(Arv *raiz){ //ERD
    if(raiz != NULL){
        pre_ordem(raiz->esq);
        printf("%d ", raiz->chave);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Arv *raiz){ //EDR
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

int busca(Arv *raiz, int n){
    if(raiz == NULL){
        return 0;
    } else if(raiz->chave == n){
        return 1;
    } else if(raiz->chave > n){ // valores menores ficam à esquerda
        return busca(raiz->esq, n);
    } else{ // valores menores ficam à direita
        return busca(raiz->dir, n);
    }
}

void remover(Arv **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (numero < (*pRaiz)->chave)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->chave)
    remover(&(*pRaiz)->dir, numero);
  else {
    Arv *pAux = *pRaiz;
    // 01 - no sem filhos
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } else {
      // 02 - no com filho direito
      if ((*pRaiz)->esq == NULL) {
        (*pRaiz) = (*pRaiz)->dir;
        pAux->dir = NULL;
        free(pAux);
      } else {
        // 02 - no com filho esquerdo
        if ((*pRaiz)->dir == NULL) {
          (*pRaiz) = (*pRaiz)->esq;
          pAux->esq = NULL;
          free(pAux);
        } else {
          // 03 - no com dois filhos
          pAux = MaiorDireita(&(*pRaiz)->esq);
          pAux->esq = (*pRaiz)->esq;
          pAux->dir = (*pRaiz)->dir;
          free(*pRaiz);
          *pRaiz = pAux;
        }
      }
    }
  }
}

int maiorElemento(Arv *raiz){
    if(raiz != NULL){
        if(raiz->dir != NULL){
            return maiorElemento(raiz->dir);
        } else {
            return raiz->chave;
        }
    }
    return 0;
}

void imprimirFolhas(Arv *raiz){
    if(raiz != NULL){
        if(raiz->dir == NULL && raiz->esq == NULL){
            printf("%d ", raiz->chave);
        } 
        imprimirFolhas(raiz->esq);
        imprimirFolhas(raiz->dir);
    }
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

    printf("PRÉ-ORDEM\n");
    pre_ordem(raiz);
    printf("\nIN-ORDEM\n");
    in_ordem(raiz);
    printf("\nPÓS-ORDEM\n");
    pos_ordem(raiz);

    printf("\n%d\n", busca(raiz, 12));

    printf("\n%d\n", maiorElemento(raiz));

    imprimirFolhas(raiz);

    return 0;
}