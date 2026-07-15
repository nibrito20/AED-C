#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int valor;
    struct Arv* dir;
    struct Arv* esq;
} Arv;

int filhosAlt(Arv *raiz){
    if(raiz == NULL) return 0;
    else{
        int ae = filhosAlt(raiz->esq);
        int ad = filhosAlt(raiz->dir);

        if (ae > ad) {
            return 1 + ae;
        } else {
            return 1 + ad;
        }
    }
}

void rodaDir(Arv **raiz){ //filho da esquerda vira raiz, raiz vira filho da direita
    Arv *aux = (*raiz)->esq;
    (*raiz)->esq = aux->dir;
    aux->dir = (*raiz);
    *raiz = aux;
}

void rodaEsq(Arv **raiz){// filho da direita vira raiz, raiz vira vira filho da esquerda
    Arv *aux = (*raiz)->dir;
    (*raiz)->dir = aux->esq;
    aux->esq = (*raiz);
    *raiz = aux;
}

void balanco(Arv **raiz){
    if(*raiz != NULL){
        Arv *aux;
        int fb = filhosAlt((*raiz)->dir) - filhosAlt((*raiz)->esq);

        if (fb <= -2) { //rotacao direita
            aux = (*raiz)->esq;
            fb = filhosAlt(aux->dir) - filhosAlt(aux->esq); //fb do aux

            if (fb > 0) { //rotacao dupla
                rodaEsq(&((*raiz)->esq));
                rodaDir(raiz);
                printf("\nRotação: Dupla Direita");
            } else { //rotacao simples
                rodaDir(raiz);
                printf("\nRotação: Direita Simples");
            }

        } else if (fb >= 2) { //rotacao esquerda
            aux = (*raiz)->dir;
            fb = filhosAlt(aux->dir) - filhosAlt(aux->esq); //fb do aux

            if (fb < 0) { //rotacao dupla
                rodaDir(&((*raiz)->dir));
                rodaEsq(raiz);
                printf("\nRotação: Dupla Esquerda");
            } else { //rotacao simples
                rodaEsq(raiz);
                printf("\nRotação: Esquerda Simples");
            }
        }
    }
}

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

    balanco(raiz);
}

Arv *MaiorDireita(Arv **raiz){
    if((*raiz)->dir != NULL) return MaiorDireita(&((*raiz)->dir));
    else{
        Arv *aux = *raiz;
        if((*raiz)->esq != NULL){
            *raiz = (*raiz)->esq;
        } else{
            *raiz = NULL;
        }
        return aux;
    }
}

void remover(Arv **raiz, int n){
    if(*raiz == NULL){
        printf("Número não encontrado\n");
        return;
    } else if(n < (*raiz)->valor){
        remover(&(*raiz)->esq, n);
    } else if(n > (*raiz)->valor){
        remover(&(*raiz)->dir, n);
    } else{
        Arv *aux = *raiz; // guarda o endereco do nó a ser removido
        //sem filhos
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            free(*raiz);
            *raiz = NULL;
        }
        //com filhos
        else{
            if((*raiz)->dir == NULL){ //filho esquerdo
                *raiz = (*raiz)->esq;
                aux->esq = NULL;
                free(aux);
                aux = NULL;
            } else if((*raiz)->esq == NULL){ //filho direito
                *raiz = (*raiz)->dir;
                aux->dir = NULL;
                free(aux);
                aux = NULL;
            } else{ // dois filhos
                aux = MaiorDireita(&(*raiz)->esq);
                aux->esq = (*raiz)->esq;
                aux->dir = (*raiz)->dir;
                (*raiz)->dir = (*raiz)->esq = NULL;
                free(*raiz);
                *raiz = aux;
                aux = NULL;
            }
        }
    }
    balanco(raiz);
}

void preOrdem(Arv *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(Arv *raiz){
    if(raiz != NULL){
        inOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        inOrdem(raiz->dir);
    }
}

void posOrdem(Arv *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

int main(){
    Arv *raiz = NULL;

    printf("=== INSERINDO ===\n");
    inserir(&raiz, 30);
    inserir(&raiz, 20);
    inserir(&raiz, 10); // rotação direita
    inserir(&raiz, 40);
    inserir(&raiz, 50); // rotação esquerda
    inserir(&raiz, 25); // rotação dupla

    printf("\n\n=== PERCURSOS ===\n");
    printf("Pre-ordem:  "); preOrdem(raiz);  printf("\n");
    printf("In-ordem:   "); inOrdem(raiz);   printf("\n");
    printf("Pos-ordem:  "); posOrdem(raiz);  printf("\n");

    printf("\n=== REMOVENDO ===\n");
    remover(&raiz, 20);
    printf("Removeu 20 | In-ordem: "); inOrdem(raiz); printf("\n");

    remover(&raiz, 10);
    printf("Removeu 10 | In-ordem: "); inOrdem(raiz); printf("\n");

    remover(&raiz, 30);
    printf("Removeu 30 | In-ordem: "); inOrdem(raiz); printf("\n");

    remover(&raiz, 99); // não existe

    printf("\n=== ALTURA ===\n");
    printf("Altura: %d\n", filhosAlt(raiz));

    return 0;
}