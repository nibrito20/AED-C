#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
} Node;

void inserir(Node **head, Node **tail, int x){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->num = x;
        novo->next = NULL;
        if(*head != NULL){
            *head = *tail = novo;
        } else{
            (*tail)->next = novo;
            *tail = novo;
        }
    }
}

void remover(Node **head, Node **tail){
    if(*head != NULL){
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else{
            Node *aux = *head;
            (*head) = (*head)->next;
            free(aux);
        }
    }
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    return 0;
}