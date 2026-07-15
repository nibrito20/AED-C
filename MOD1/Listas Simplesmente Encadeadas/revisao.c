/* Revisão de Struct e Ponteiros */
#include <stdio.h>

typedef struct Node{
    int valor;
    struct Node *prox;
} Node;

void inserir_inicio(Node **head, int z){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = z;
        novo->prox = *head;
        *head = novo;
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d\n", head->valor);
        head = head->prox;
    }
}

int contar(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->prox;
    }
    return count;
}

void remover(Node **head){
    if(head != NULL){
        Node *aux = *head;
        *head = (*head)->prox;
        free(aux);
    }
}

int main(){
    Node *head = NULL;
    inserir_inicio(&head, 10);
    return 0;
}