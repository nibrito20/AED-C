//LISTA DUPLAMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>

/*
Como restrições, considere:

● o valor de delimitador01 deve aparecer antes de delimitador02
● deve haver ao menos um nó entre eles para que a remoção seja
realizada.
● a lista não pode estar vazia e ela deve conter mais de dois
elementos.
*/

typedef struct Node{
    int valor;
    struct Node *ant;
    struct Node *next;
} Node;

void excluirIntervalo(Node **head, Node **tail, int delimitador01, int delimitador02){

    if(*head != NULL){

        Node *aux = *head;
        int count = 0;
        while(aux != NULL){
            count++;
            aux = aux->next;
        }

        if(count > 2){

            Node *d1 = NULL;
            Node *d2 = NULL;
            aux = *head;

            while(aux != NULL && aux->valor != delimitador01) aux = aux->next;
            if(aux != NULL){
                d1 = aux;
            } else{
                printf("Delimitador 01 não encontrado\n");
                return;
            }

            aux = d1->next;
            while(aux != NULL && aux->valor != delimitador02) aux = aux->next;
            if(aux != NULL){
                d2 = aux;
            } else{
                printf("Delimitador 02 não encontrado\n");
                return;
            }

            if(d1->next == d2){
                printf("Não há elementos entre os delimitadores.\n");
                return;
            }
            
            Node *temp = d1->next;
            while(temp != d2){
                Node *remover = temp;
                temp = temp->next;
                free(remover);
            }
            d1->next = d2;
            d2->ant = d1;
                    
        } else{
            printf("A lista precisa conter mais de dois elementos.\n");
        }
    } else{
        printf("A lista está vazia.\n");
    }
}

void impresao(Node *head){
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->next;
    }
    printf("\n");
}

void insercao(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;
        novo->next = NULL;

        if(*head == NULL){
            novo->ant = NULL;
            *head = novo;
            *tail = novo;
            return;
        }

        novo->ant = *tail;
        (*tail)->next = novo;
        *tail = novo;
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insercao(&head, &tail, 1);
    insercao(&head, &tail, 2);
    insercao(&head, &tail, 3);
    insercao(&head, &tail, 4);
    insercao(&head, &tail, 5);

    impresao(head);

    excluirIntervalo(&head, &tail, 2, 4);
    impresao(head);

    return 0;
}