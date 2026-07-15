#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *ant;
    struct Node *next; 
} Node;

void inserirFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->next = *head;
            novo->ant = *tail;
            *head = novo;
            *tail = *head;
        } else {
            novo->ant = *tail; 
            (*tail)->next = novo;
            *tail = novo;
            novo->next = *head;
            (*head)->ant = novo;
        }
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head != NULL){

        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;
            return;
        }
        Node *remover = *tail;
        *tail = (*tail)->ant;
        (*tail)->next = *head;
        free(remover);
    }
}

void inserirInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->next = novo;
            novo->ant = novo;
            *head = novo;
            *tail = *head;
        } else {
            novo->next = *head;
            novo->ant = *tail;
            (*head)->ant = novo;
            (*tail)->next = novo;
            *head = novo;
        }
    }
}

void removerInicio(Node **head, Node **tail){
    if(*head != NULL){

        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;
            return;
        }

        Node *remover = *head;
        *head = (*head)->next;
        (*tail)->next = *head;
        (*head)->ant = *tail;
        free(remover);
    }
}

void imprimir(Node *head, Node *tail){
    if(head != NULL){
        do{
            printf("%d ", head->valor);
            head = head->next;
        } while(head != tail->next);
        printf("\n");
    }
}

void imprimirInvertido(Node *head, Node *tail){
    if(head != NULL){
        Node *atual = tail;
        do{
            printf("%d ", atual->valor);
            atual = atual->ant;
        } while(atual != head->ant);
        printf("\n");
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    /*inserirInicio(&head, &tail, 1);
    inserirInicio(&head, &tail, 2);
    inserirInicio(&head, &tail, 3);
    imprimir(head, tail);

    removerInicio(&head, &tail);
    imprimir(head, tail);
    imprimirInvertido(head, tail);*/

    inserirFinal(&head, &tail, 1);
    inserirFinal(&head, &tail, 2);
    inserirFinal(&head, &tail, 3);
    imprimir(head, tail);

    removerFinal(&head, &tail);
    imprimir(head, tail);
    imprimirInvertido(head, tail);

    return 0;
}