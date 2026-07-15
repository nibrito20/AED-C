#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void inserir_ordenado(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;
        if(*head == NULL){
            *head = novo;
            *tail = *head;
        } else{
            if((*head)->valor > valor){
                novo->prox = *head;
                (*head)->ant = novo;
                *head = novo;
            } else{
                Node *aux = *head;
                while(aux->prox != NULL && aux->prox->valor < valor){
                    aux = aux->prox;
                }
                
                if(aux->prox == NULL){
                    aux->prox = novo;
                    novo->ant = aux;
                    *tail = novo;
                } else{
                    novo->prox = aux->prox;
                    novo->ant = aux;
                    aux->prox->ant = novo;
                    aux->prox = novo;
                }
            }
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
    Node *ant = NULL;

    inserir_ordenado(&head, &tail, 5);
    inserir_ordenado(&head, &tail, 7);
    inserir_ordenado(&head, &tail, 6);

    imprimir(head);

    return 0;
}