#include <stdio.h>
#include <stdlib.h>
// https://www.inf.ufsc.br/~aldo.vw/estruturas/simulador/AVL.html

typedef struct arv {
  int num;
  struct arv *esq;
  struct arv *dir;
} Arv;

int filhosAlt(Arv *r);
void roda_dir(Arv **p);
void roda_esq(Arv **p);
void balanco(Arv **p);

void inserir(Arv **t, int num);
void preordem(Arv *t);
void remover(Arv **pRaiz, int numero);
Arv *MaiorDireita(Arv **no);

int main() {
  Arv *t = NULL;

  inserir(&t, 6);
  inserir(&t, 10);
  inserir(&t, 15);
  printf("\n>>Rotação devido a inserção do 15\n");

  inserir(&t, 3);
  inserir(&t, 1);
  printf("\n>>Rotação devido a inserção do 1\n");

  printf("\nPRE-ordem:");
  preordem(t);
  printf("\n");

  return 0;
}

int filhosAlt(Arv *r) {
  if (r == NULL)
    return 0;
  else {
    int ae = filhosAlt(r->esq);
    int ad = filhosAlt(r->dir);
    return 1 + (ae > ad ? ae : ad);
  }
}

void roda_dir(Arv **p) {
  Arv *aux = (*p)->esq;
  (*p)->esq = aux->dir;
  aux->dir = (*p);
  *p = aux;
}

void roda_esq(Arv **p) {
  Arv *aux = (*p)->dir;
  (*p)->dir = aux->esq;
  aux->esq = (*p);
  *p = aux;
}

void balanco(Arv **p) {
  if(*p != NULL){
    Arv *aux;
    int fb = filhosAlt((*p)->dir) - filhosAlt((*p)->esq);

    if (fb <= -2) {
      aux = (*p)->esq;
      fb = filhosAlt(aux->dir) - filhosAlt(aux->esq);

      if (fb > 0) {
        roda_esq(&((*p)->esq));
        roda_dir(p);
        printf("\nRotação: Dupla Direita");
      } else {
        roda_dir(p);
        printf("\nRotação: Direita Simples");
      }
    } else if (fb >= 2) {
      aux = (*p)->dir;
      fb = filhosAlt(aux->dir) - filhosAlt(aux->esq);

      if (fb < 0) {
        roda_dir(&((*p)->dir));
        roda_esq(p);
        printf("\nRotação: Dupla Esquerda");
      } else {
        roda_esq(p);
        printf("\nRotação: Esquerda Simples");
      }
    }
  }
}

void preordem(Arv *t) {
  if (t != NULL) {
    printf("%d ", t->num);
    preordem(t->esq);
    preordem(t->dir);
  }
}

void inserir(Arv **t, int n) {
  if (*t == NULL) {
    *t = (Arv *)malloc(sizeof(Arv));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->num = n;
  } else if (n < (*t)->num)
    inserir(&(*t)->esq, n);
  else if (n > (*t)->num)
    inserir(&(*t)->dir, n);

  balanco(t);
}

Arv *MaiorDireita(Arv **no) {
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
    printf("\nRemoção: Numero nao existe na arvore!");
    return;
  }
  else if (numero < (*pRaiz)->num)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->num)
    remover(&(*pRaiz)->dir, numero);
  else {
    Arv *pAux = *pRaiz;
    // 01 - no sem filhos
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)) {
      free(pAux);
      (*pRaiz) = NULL;
    } 
    else {
      // 02 - no com filho direito
      if ((*pRaiz)->esq == NULL) {
        (*pRaiz) = (*pRaiz)->dir;
        pAux->dir = NULL;
        free(pAux);
        pAux = NULL;
      } 
      else {
        // 02 - no com filho esquerdo
        if ((*pRaiz)->dir == NULL) {
          (*pRaiz) = (*pRaiz)->esq;
          pAux->esq = NULL;
          free(pAux);
          pAux = NULL;
        } else {
          // 03 - no com dois filhos
          pAux = MaiorDireita(&(*pRaiz)->esq);
          pAux->esq = (*pRaiz)->esq;
          pAux->dir = (*pRaiz)->dir;
          (*pRaiz)->esq = (*pRaiz)->dir = NULL;
          free((*pRaiz));
          *pRaiz = pAux;
          pAux = NULL;
        }
      }
    }
  }
  balanco(pRaiz);
}
