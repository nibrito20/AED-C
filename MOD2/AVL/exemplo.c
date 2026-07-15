#include <stdio.h>
#include <stdlib.h>

/*
CÁLCULO FB = QTD_DE_NÍVEIS(DIREITA) - QTD_DE_NÍVEIS(ESQUERDA)
ENTRE -1 E 1 = BALANCEADO
ENTRE -2 E 2 = DESBALANCEADO
o FB DA ESQUERDA É NEGATIVO E O DA DIREITA POSITIVO
SE EU TÔ NA ESQUERDA É ROTAÇÃO DUPLA SE FB DO AUX FOR MAIOR DO QUE 0.
SE EU TÔ NA DIREIRA É ROTAÇÃO DUPLA SE O FB DO AUX FOR MENOR DO QUE 0.
*/

typedef struct Arv{
    int chave;
    struct Arv *esq;
    struct Arv *dir;
} Arv;

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

int main(){
    return 0;
}