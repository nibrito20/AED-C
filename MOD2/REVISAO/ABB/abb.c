#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv *esq;
    struct Arv *dir;
} Arv;

void inserir(Arv **raiz, int valor){

  if(*raiz == NULL){
    *raiz = (Arv*) malloc(sizeof(Arv));
    (*raiz)->valor = valor;
    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
  } 

  if(valor < (*raiz)->valor){
    inserir(&(*raiz)->esq, valor);
  }else if(valor > (*raiz)->valor){
    inserir(&(*raiz)->dir, valor);
  }
}

void preOrdem(Arv *raiz){ // RAIZ ESQ DIR
  if(raiz != NULL){
    printf("| %d |", raiz->valor);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
  }
}

void inOrdem(Arv *raiz){ // ESQ RAIZ DIR
  if(raiz != NULL){
    inOrdem(raiz->esq);
    printf("| %d |", raiz->valor);
    inOrdem(raiz->dir);
  }
}

void posOrdem(Arv *raiz){ // ESQ DIR RAIZ
  if(raiz != NULL){
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("| %d |", raiz->valor);
  }
}

int busca(Arv *raiz, int n){
  if(raiz == NULL){
    return 0;
  } else if(raiz->valor == n){
    return 1;
  } else if(n < raiz->valor){
    return busca(raiz->esq, n);
  } else{
    return busca(raiz->dir, n);
  }
}

Arv *MaiorDireita(Arv **no) { //pega o maior nó a direita DO FILHO ESQUERDO do nó a remover
  if ((*no)->dir != NULL)
    return MaiorDireita(&(*no)->dir);
  else {
    Arv *aux = *no;
    if ((*no)->esq != NULL) {
      *no = (*no)->esq;
    } else {
      *no = NULL;
    }
    return aux;
  }
}

void remover(Arv **pRaiz, int numero) {
  if (*pRaiz == NULL) {
    printf("Numero nao existe na arvore!");
    return;
  }
  if (numero < (*pRaiz)->valor)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->valor)
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

int main(){

    Arv *raiz = NULL;

    inserir(&raiz, 48);
    inserir(&raiz, 30);
    inserir(&raiz, 82);
    inserir(&raiz, 15);
    inserir(&raiz, 37);
    inserir(&raiz, 61);
    inserir(&raiz, 98);

    printf("\nPRE-ordem:");
    preOrdem(raiz);

    printf("\nIN-ordem:");
    inOrdem(raiz);

    printf("\nPOS-ordem:");
    posOrdem(raiz);
    printf("\n\n");

    if (busca(raiz,15)) {
    printf("\nO numero está na arvore!\n");
    } else {
    printf("O numero NAO está na arvore!\n");
    }

    printf("\nPre-ordem:");
    preOrdem(raiz);
    printf("\n");

    remover(&raiz, 30);

    printf("\nPrint após remoção (Pre-ordem):");
    preOrdem(raiz);
    printf("\n");
    return 0;
}