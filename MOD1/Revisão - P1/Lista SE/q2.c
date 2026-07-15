#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void insercao_ordenada(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;

    if(*head == NULL || (*head)->valor >= valor){
        novo->next = *head;
        *head = novo;
    } else{
        Node *atual = *head;
        while (atual->next != NULL && atual->next->valor < valor){
            atual = atual->next;
        }
        novo->next = atual->next;
        atual->next = novo;
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
    insercao_ordenada(&head, 2);
    imprimir(head);
    insercao_ordenada(&head, 5);
    imprimir(head);
    insercao_ordenada(&head, 1);
    imprimir(head);

    return 0;
}
