#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void insercao(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        
    } else {
        Node *aux = *head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = novo;
    }
}

void inserir_inicio(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    if(*head != NULL){
        Node *aux = *head;
        *head = novo;
        (*head)->next = aux;
    } else{
        *head = novo;
    }

}

void imprimir(Node *head){
    if(head == NULL){
        printf("Lista vazia.\n");
    } else {
        while(head != NULL){
            printf("%d ", head->valor);
            head = head->next;
        }
        printf("\n");
    }
}

void remocao(Node **head){

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
    }
    
    if(*head != NULL){
        Node *aux = *head;
        while(aux->next->next != NULL){
            aux = aux->next;
        }
        free(aux->next);
        aux->next = NULL;
    } else{
        printf("Lista vazia.\n");
    } 
}

int main(){
    Node *head = NULL;
    insercao(&head, 5);
    insercao(&head, 6);
    imprimir(head);
    inserir_inicio(&head, 4);
    imprimir(head);
    remocao(&head);
    imprimir(head);
    return 0;
}