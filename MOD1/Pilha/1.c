#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->next = *head;
        *head = novo;
    }
}

void remover(Node **head){
    if(head != NULL){
        Node *aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d\n", head->valor);
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    inserir(&head, 5);
    inserir(&head, 10);
    imprimir(head);
    printf("---------\n");
    remover(&head);
    imprimir(head);
    return 0;
}