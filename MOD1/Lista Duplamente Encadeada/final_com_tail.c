#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void insercaoFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    
    if(novo != NULL){
        
        novo->valor = valor;
        novo->prox = NULL;
        
        if(*head == NULL){
            
            *head = novo;
            *tail = *head;
            
        } else{
            
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
        
    }
}

void remocaoFinal(Node **head, Node **tail){
    if(*head != NULL){
        
        if((*head)->prox == NULL){
            
            free(*head);
            *head = NULL;
            *tail = NULL;
            
        } else {
            
            Node *temp = *tail;
            *tail = temp->ant;
            (*tail)->prox = NULL;
            free(temp);
            
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
    Node *tail = NULL;
    
    insercaoFinal(&head, &tail, 1);
    insercaoFinal(&head, &tail, 2);
    insercaoFinal(&head, &tail, 3);

    imprimir(head);
    
    remocaoFinal(&head, &tail);
    
    imprimir(head);
    
    return 0;
}
