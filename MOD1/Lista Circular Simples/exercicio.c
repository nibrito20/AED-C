#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
} Node;

void inserirInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    
    if(novo != NULL){
        
        novo->valor = valor;
        
        if(*head == NULL){
            
            *head = novo;
            *tail = *head;
            
        } else{
            
            novo->prox = *head;
            *head = novo;
        }
        (*tail)->prox = *head;
    }
}

void inserirFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    
    if(novo != NULL){
        
        novo->valor = valor;
        
        if(*head == NULL){
            
            *head = novo;
            *tail = *head;
            
        } else{
            
            (*tail)->prox = novo;
            *tail = novo;
        }
        (*tail)->prox = *head;
    }
}

void removerInicio(Node **head, Node **tail){
    if(*head != NULL){
        
        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;
        }

        Node *remover = *head;
        *head = (*head)->prox;
        (*tail)->prox = *head;
        free(remover);

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

        Node *aux = *head;
        while(aux->prox != *tail){
            aux = aux->prox;
        } 
        
        Node *remover = aux->prox;
        free(remover);
        aux->prox = *head;
        *tail = aux;

    }
}

void imprimir(Node *head, Node *tail){
    if(head != NULL){

        do{
            printf("%d ", head->valor);
            head = head->prox;
        } while(head != tail->prox);
        printf("\n");
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    // inserirInicio(&head, &tail, 1);
    // inserirInicio(&head, &tail, 2);
    // inserirInicio(&head, &tail, 3);
    // imprimir(head, tail);

    // removerInicio(&head, &tail);
    // imprimir(head, tail);

    inserirFinal(&head, &tail, 1);
    inserirFinal(&head, &tail, 2);
    inserirFinal(&head, &tail, 3);
    imprimir(head, tail);

    removerFinal(&head, &tail);
    imprimir(head, tail);

    return 0;
}