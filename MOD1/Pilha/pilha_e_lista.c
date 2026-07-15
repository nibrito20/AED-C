#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[30];
    struct Pessoa *next;
} Pessoa;

void inserirFila(Pessoa **head, Pessoa **tail, char *nome){
    Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
    if(novo != NULL){
        strcpy(novo->nome, nome);
        novo->next = NULL;
    }

    if(*head == NULL){
        *head = *tail = novo;
    } else{
        (*tail)->next = novo;
        *tail = novo;
    }
}

void concatenar(Pessoa *headFila, Pessoa **headPilha){
    if(headFila == NULL) return;

    while(headFila != NULL){
        Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
        strcpy(novo->nome, headFila->nome);
        novo->next = *headPilha;
        *headPilha = novo;
        headFila = headFila->next;
    }    
}

void intercalar(Pessoa *headFila1, Pessoa *headFila2, Pessoa **headPilha){
    if(headFila1 == NULL || headFila2 == NULL) return;

    while(headFila1 != NULL || headFila2 != NULL){

        if(headFila1 != NULL){
            Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
            strcpy(novo->nome, headFila1->nome);
            novo->next = *headPilha;
            *headPilha = novo;
            headFila1 = headFila1->next;
        }

        if(headFila2 != NULL){
            Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
            strcpy(novo->nome, headFila2->nome);
            novo->next = *headPilha;
            *headPilha = novo;
            headFila2 = headFila2->next;
        }
    }
}

void imprimir(Pessoa *head){
    while(head != NULL){
        printf("%s\n", head->nome);
        head = head->next;
    }
}

int main(){
    Pessoa *headFila1 = NULL;
    Pessoa *tailFila1 = NULL;
    Pessoa *headFila2 = NULL;
    Pessoa *tailFila2 = NULL;
    Pessoa *pilha1 = NULL;
    Pessoa *pilha2 = NULL;

    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");
    inserirFila(&headFila1, &tailFila1, "Ana");

    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");
    inserirFila(&headFila2, &tailFila2, "Bia");

    concatenar(headFila1, &pilha1);
    concatenar(headFila2, &pilha1);

    intercalar(headFila1, headFila2, &pilha2);

    printf("\n=== FILA 1 ===\n");
    imprimir(headFila1);

    printf("\n=== FILA 2 ===\n");
    imprimir(headFila2);

    printf("\n=== PILHA 1 ===\n");
    imprimir(pilha1);

    printf("\n=== PILHA 2 ===\n");
    imprimir(pilha2);

    return 0;
}
