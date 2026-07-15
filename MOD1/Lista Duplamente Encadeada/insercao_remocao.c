#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
    struct Node *previous;
} Node;

void inserirComeco(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->next = *head;
        novo->previous = NULL;

        if(*head != NULL){
            (*head)->previous = novo;
        }
        *head = novo;
    }
}

void removerComeco(Node **head){
    if(*head != NULL){
        Node *aux = *head;
        *head = (*head)->next;
        free(aux);

        if(*head != NULL){
            (*head)->previous = NULL;
        }
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d\n", head->valor);
        head = head->next;
    }
    printf("\n");
}

void imprimirInverso(Node *head){
    if(head != NULL){

        while(head->next != NULL){
            head = head->next;
        }
        
        while(head != NULL){
            printf("%d\n", head->valor);
            head = head->previous;
        }
    }
}

int main(){
    Node *head = NULL;
    Node *previous = NULL;

    inserirComeco(&head, 10);
    inserirComeco(&head, 5);
    inserirComeco(&head, 2);

    imprimir(head);
    imprimirInverso(head);

    return 0;
}