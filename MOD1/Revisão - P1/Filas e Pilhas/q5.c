#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserirFila(Node **head, Node **tail, int valor){
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

void excluirIguais(Node *head1, Node *tail1, Node **head2, Node **tail2){

    Node *aux2 = NULL;
    Node *anterior = NULL;

    while(head1 != NULL){

        aux2 = *head2;
        anterior = NULL;

        while(aux2 != NULL){

            if(head1->valor == aux2->valor){
                
                Node *remover = aux2;
                aux2 = remover->next;

                if(anterior == NULL){
                    *head2 = aux2;
                } else{
                    anterior->next = aux2;
                }

                if(remover == *tail2){
                    *tail2 = anterior;
                }

                free(remover);
            } else {
                anterior = aux2;
                aux2 = aux2->next;
            }
        }
        head1 = head1->next;
    }
}

void imprimir(Node *head){
    if(head == NULL){
        printf("Lista vazia.\n");
    } else{
        while(head != NULL){
            printf("%d ", head->valor);
            head = head->next;
        }
        printf("\n");
    }
}

int main(){

    Node *fila1 = NULL, *tail1 = NULL, *fila2 = NULL, *tail2 = NULL;

    inserirFila(&fila1, &tail1, 1);
    inserirFila(&fila1, &tail1, 3);
    inserirFila(&fila1, &tail1, 6);

    inserirFila(&fila2, &tail2, 2);
    inserirFila(&fila2, &tail2, 4);
    inserirFila(&fila2, &tail2, 6);

    printf("FILA 1:\n");
    imprimir(fila1);

    printf("FILA 2:\n");
    imprimir(fila2);

    excluirIguais(fila1, tail1, &fila2, &tail2);

    printf("Pós comparação:\n");
    printf("FILA 1: ");
    imprimir(fila1);
    printf("\nFILA 2: ");
    imprimir(fila2);

    return 0;
}