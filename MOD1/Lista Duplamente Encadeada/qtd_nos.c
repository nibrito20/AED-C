#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void contar_nos(Node *head, int x, int *cont_apos, int *cont_antes){
    Node *guardar = NULL;
    Node *aux = head;
    while(aux != NULL){
        if(aux->valor == x){
            guardar = aux->prox;
        }
        aux = aux->prox;
    }

    while(guardar != NULL){
        (*cont_apos)++;
        guardar = guardar->prox;
    }

    while(head != NULL && head->valor != x){
        (*cont_antes)++;
        head = head->prox;
    }
}

void inserir(Node **head, Node **tail, int x){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = x;
        novo->prox = NULL;
        if(*head == NULL){
            novo->ant = NULL;
            *head = novo;
            *tail = *head;
        } else {
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    inserir(&head, &tail, 1);
    inserir(&head, &tail, 2);
    inserir(&head, &tail, 3);
    inserir(&head, &tail, 4);
    inserir(&head, &tail, 5);

    imprimir(head);

    int cont_apos = 0;
    int cont_antes = 0;

    contar_nos(head, 3, &cont_apos, &cont_antes);

    printf("Antes: %d\n", cont_antes);
    printf("Depois: %d\n", cont_apos);

    return 0;
}