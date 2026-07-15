#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void maior(Node **head){
    Node *aux = *head;
    Node *armazenar = NULL;
    Node *ant = NULL;
    Node *antMaior = NULL;

    while(aux != NULL){
        if (armazenar == NULL || armazenar->valor < aux->valor){

            armazenar = aux;
            antMaior = ant;

        }

        ant = aux;
        aux = aux->next;

    }

    if (armazenar == *head){

        printf("O maior valor já se encontra no head!\n");

    }else{

        antMaior->next = armazenar->next;
        armazenar->next = *head;
        *head = armazenar;

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