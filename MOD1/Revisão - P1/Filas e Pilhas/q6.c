#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;
    if(novo != NULL){
        if(*head != NULL){
        novo->next = *head;
        *head = novo;
        } else{
            *head = novo;
        }
    }
}

void troca(Node **head1, Node **head2){
    if(*head1 != NULL && *head2 != NULL){
        Node *guardarCabeca = *head1;
        Node *guardarNext1 = (*head1)->next;
        Node *guardarNext2 = (*head2)->next;
        *head1 = *head2;
        (*head1)->next = guardarNext1;
        *head2 = guardarCabeca;
        (*head2)->next = guardarNext2;
    }
}

void imprimir(Node *head){
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node *pilha1 = NULL, *pilha2 = NULL;
    inserir(&pilha1, 1);
    inserir(&pilha1, 2);
    inserir(&pilha2, 3);
    inserir(&pilha2, 4);
    printf("Pilha 1: ");
    imprimir(pilha1);
    printf("\nPilha 2: ");
    imprimir(pilha2);
    printf("\nTroca:\n");
    troca(&pilha1, &pilha2);
    printf("Pilha 1: ");
    imprimir(pilha1);
    printf("\nPilha 2: ");
    imprimir(pilha2);
    return 0;
}
