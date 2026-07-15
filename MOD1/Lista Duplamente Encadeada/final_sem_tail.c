#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void insercaoFinal(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    
    if(novo != NULL){
        
        novo->valor = valor;
        novo->prox = NULL;
        novo->ant = NULL;
        
        if(*head == NULL){
            
            *head = novo;
            
        } else{
            
            Node *aux = *head;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            
            novo->ant = aux;
            aux->prox = novo;
        }
        
    }
}

void remocaoFinal(Node **head){
    if(*head != NULL){
        
        if((*head)->prox == NULL){
            
            free(*head);
            *head = NULL;
            
        } else {
            
            Node *aux = *head;
            while(aux->prox->prox != NULL){
                aux = aux->prox;
            }
            
            free(aux->prox);
            aux->prox = NULL;
            
        }
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d\n", head->valor);
        head = head->prox;
    }
    printf("\n");
}

int main(){
    
    Node *head = NULL;
    
    insercaoFinal(&head, 1);
    insercaoFinal(&head, 2);
    insercaoFinal(&head, 3);

    imprimir(head);
    
    remocaoFinal(&head);
    
    imprimir(head);
    
    return 0;
}
