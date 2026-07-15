#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;


void maior(Node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }

    Node *aux = *head;
    Node *maior = *head;
    Node *antMaior = NULL;
    Node *ant = NULL;

    while(aux != NULL){
        if(aux->valor > maior->valor){
            maior = aux;
            antMaior = ant;
        }
        ant = aux;
        aux = aux->next;
    }

    if(maior == *head){
        return;
    }

    antMaior->next = maior->next;
    maior->next = *head;
    *head = maior;
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

int main(){
    Node *head = NULL;
    insercao(&head, 2);
    insercao(&head, 5);
    insercao(&head, 10);
    imprimir(head);

    maior(&head);
    imprimir(head);

    return 0;
}
