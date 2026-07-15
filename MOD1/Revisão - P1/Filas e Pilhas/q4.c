#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir_fila(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = *head;
    } else{
        (*tail)->next = novo;
        *tail = novo;
    }
}

void remover_fila(Node **head, Node **tail){
    if(*head != NULL){
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else{
            Node *aux = (*head)->next;
            free(*head);
            *head = aux;
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

void inserir_pilha(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    
    if(*head == NULL){
        novo->next = NULL;
        *head = novo;
    } else{
        novo->next = *head;
        *head = novo;
    }
}

void remover_pilha(Node **head){
    if(*head != NULL){
        Node *aux = (*head)->next;
        free(*head);
        *head = aux;
    }
}

int main(){
    Node *headFila = NULL;
    Node *tail = NULL;

    Node *headPilha = NULL;

    inserir_fila(&headFila, &tail, 5);
    inserir_fila(&headFila, &tail, 6);
    inserir_fila(&headFila, &tail, 7);

    printf("Fila\n");
    imprimir(headFila);

    remover_fila(&headFila, &tail);
    printf("Fila andou...\n");
    imprimir(headFila);

    inserir_pilha(&headPilha, 1);
    inserir_pilha(&headPilha, 2);
    inserir_pilha(&headPilha, 3);

    printf("Pilha\n");
    imprimir(headPilha);

    remover_pilha(&headPilha);
    printf("Pilha diminuiu...\n");
    imprimir(headPilha);

    return 0;
}