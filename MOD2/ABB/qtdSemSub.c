#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int chave;
    struct Arv *esq;
    struct Arv *dir;
} Arv;

void inserir(Arv **raiz, int chave){
    if(*raiz == NULL){
        *raiz = (Arv*)malloc(sizeof(Arv));
        (*raiz)->chave = chave;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
    } else{
        if(chave > (*raiz)->chave){
            inserir(&(*raiz)->dir, chave);
        } else if(chave < (*raiz)->chave){
            inserir(&(*raiz)->esq, chave);
        }
    }
}

// int qtdSemSub(Arv *raiz, int chaveSub){
//     int count = 0;
//     if(raiz != NULL){
//         if(raiz->chave == chaveSub){
//             return 0;
//         } else{
//             count++;
//             count += qtdSemSub(raiz->esq, chaveSub);
//             count +=qtdSemSub(raiz->dir, chaveSub);
//         }
//     }
//     return count;
// }

int qtdSemSub(Arv *raiz, int chaveSub){
    if(raiz == NULL){
        return 0;
    } else if(raiz->chave == chaveSub){
        return 0;
    } else{
        return 1 + qtdSemSub(raiz->esq, chaveSub) + qtdSemSub(raiz->dir, chaveSub);
    }
}

int main(){

    Arv *raiz = NULL;
    inserir(&raiz, 10);
    inserir(&raiz, 5);
    inserir(&raiz, 15);
    inserir(&raiz, 20);
    inserir(&raiz, 5);
    inserir(&raiz, 3);
    inserir(&raiz, 7);

    printf("%d\n", qtdSemSub(raiz, 5));

    return 0;
}