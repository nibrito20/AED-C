#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

Node *intercalar_listas(Node *head1, Node *head2){
    Node *headNovaLista = NULL;
    while(head1 != NULL || head2 != NULL){
        if(head1 != NULL){
            Node *novo = (Node*)malloc(sizeof(Node));
            if(novo != NULL){
                novo->valor = head1->valor;
                novo->prox = NULL;

                if(headNovaLista == NULL){
                    headNovaLista = novo;
                } else{
                    Node *aux = headNovaLista;
                    while(aux->prox != NULL){
                        aux = aux->prox;
                    }
                    aux->prox = novo;
                }
            }
            head1 = head1->prox;
        }
        if(head2 != NULL){
            Node *novo = (Node*)malloc(sizeof(Node));
            if(novo != NULL){
                novo->valor = head2->valor;
                novo->prox = NULL;

                if(headNovaLista == NULL){
                    headNovaLista = novo;
                } else{
                    Node *aux = headNovaLista;
                    while(aux->prox != NULL){
                        aux = aux->prox;
                    }
                    aux->prox = novo;
                }
            }
            head2 = head2->prox;
        }
        
    }
    return headNovaLista;
}