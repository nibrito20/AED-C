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

void imprimirBase(Node *head){
    while(head->next != NULL){
        head = head->next;
    }
    printf("%d\n", head->valor);
}

void imprimirTopo(Node *head){
    printf("%d\n", head->valor);
}

void remover(Node **head){
    if(head != NULL){
        Node *aux = *head;
        *head = (*head)->next;
        free(aux);
    }
}

void imprimirPar(Node *head){
    int count = 1;
    while(head != NULL){
        if(count % 2 == 0){
            printf("%d\n", head->valor);
        }
        count++;
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    inserir(&head, 5);
    inserir(&head, 10);
    inserir(&head, 15);
    imprimirBase(head);
    imprimirTopo(head);
    imprimirPar(head);
}