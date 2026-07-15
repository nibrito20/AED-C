#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node;

void inserirPos(Node **head, Node **tail, int valor, int pos){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->prox = novo;
            novo->ant = novo;
            *head = novo;
            *tail = *head;

        } else{

            if(pos == 1){
                novo->prox = *head;
                novo->ant = *tail;
                (*head)->ant = novo;
                (*tail)->prox = novo;
                *head = novo;
                return;
            }

            int count = 1;
            Node *aux = *head;
            while(aux != NULL){

                if(count == pos){
                    novo->prox = aux->prox;
                    novo->ant = aux;
                    aux->prox = novo;
                    aux->prox->ant = novo;

                    return;
                }

                count++;
                aux = aux->prox;

                if(aux == *head) break;

            }

            novo->prox = *head;
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }   
}

void removerPos(Node **head, Node **tail, int pos){
   
    if(*head != NULL){

        if((*head)->prox == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;
            return;
        }

        Node *remover = NULL;

        if(pos == 1){
            remover = *head;
            *head = (*head)->prox;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(remover);
            return;
        } 

        int count = 1;
        Node *aux = *head;
        while(aux != NULL){

            if(count == pos){
                remover = aux;
                aux = aux->ant;
                aux->prox = aux->prox->prox;
                aux->prox->ant = aux;
                free(remover);
                return;
            }

            count++;
            aux = aux->prox;

            if(aux == *head) break;
        }

        remover = *tail;
        Node *guardar = (*tail)->ant;
        *tail = (*tail)->ant;
        (*tail)->ant = guardar;
        (*tail)->prox = *head;
        (*head)->ant= *tail;
        free(remover);
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

    inserirPos(&head, &tail, 5, 1);
    inserirPos(&head, &tail, 6, 2);
    inserirPos(&head, &tail, 7, 3);
    inserirPos(&head, &tail, 9, 99);
    inserirPos(&head, &tail, 1, 1); 

    imprimir(head, tail);

    removerPos(&head, &tail, 4);
    imprimir(head, tail);

    return 0;
}