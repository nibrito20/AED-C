#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir_ordenado(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    
    if(*head == NULL){
        novo->next = NULL;
        *head = novo;
    } else {

        if((*head)->valor > valor){
            novo->next = *head;
            *head = novo;
        } else {
            Node *temp = *head;

            while(temp->next != NULL && temp->next->valor < valor){ // 3 -> 5 // 3 -> 4 -> 5
                temp = temp->next;
            }
            novo->next = temp->next; 
            temp->next = novo; 
        }
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

int main(){
    Node *head = NULL;
    inserir_ordenado(&head, 2);
    imprimir(head);
    inserir_ordenado(&head, 5);
    imprimir(head);
    inserir_ordenado(&head, 1);
    imprimir(head);

    return 0;
}
