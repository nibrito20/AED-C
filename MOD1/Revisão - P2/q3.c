//Lista Circular Simplesmente Encadeada
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void insercaoInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->next = novo;
            *head = novo;
            *tail = novo;
        } else{
            novo->next = *head;
            (*tail)->next = novo;
            *head = novo;
        }
    }
}

void insercaoFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->next = novo;
            *head = novo;
            *tail = novo;
        } else{
            novo->next = *head;
            (*tail)->next = novo;
            *tail = novo;
        }
    }
}

void inserirMeio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->next = novo;
            *head = novo;
            *tail = novo;
        } else{

            if((*head)->next == NULL){
                novo->next = *head;
                *head = novo;
                return;
            }

            int qtd = 0;
            Node *aux = *head;
            do {
                qtd++;
                aux = aux->next;
            } while(aux != *head);

            int meio = qtd/2;
            aux = *head;
            int count = 0;
            do{
                count++;
                aux = aux->next;
            } while(aux->next != *head && count+1 != meio);

            if(aux->next != NULL){
                novo->next = aux->next;
                aux->next = novo;
            } else{
                printf("Índice inválido\n");
            }
        }
    }
}

void impressao(Node *head, Node *tail){
    if(head != NULL){
        do{
            printf("%d ", head->valor);
            head = head->next;
        } while(head != tail->next);
    }
    printf("\n");
}

void removerInicio(Node **head, Node **tail){
    if(*head != NULL){

        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else{
            Node *remover = *head;
            *head = (*head)->next;
            (*tail)->next = *head;
            free(remover);
        }
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head != NULL){

        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else{
            Node *remover = *tail;
            Node *aux = *head;
            do{
                aux = aux->next;
            }while(aux->next != *tail);
            aux->next = *head;
            *tail = aux;
            free(remover);
        }
    }
}

void removerMeio(Node **head, Node **tail){
    if(*head != NULL){

        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            *tail = NULL;
        } else{
            int qtd = 0;
            Node *aux = *head;
            do {
                qtd++;
                aux = aux->next;
            } while(aux != *head);

            int meio = qtd/2;
            aux = *head;
            int count = 0;
            while(count < meio - 1){
                aux = aux->next;
                count++;
            }
            Node *remover = aux->next;
            aux->next = remover->next;
            free(remover);
        }
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insercaoFinal(&head, &tail, 2);
    insercaoFinal(&head, &tail, 4);
    insercaoFinal(&head, &tail, 5);

    insercaoInicio(&head, &tail, 1);
    inserirMeio(&head, &tail, 3);

    impressao(head, tail);

    removerInicio(&head, &tail);
    removerFinal(&head, &tail);
    removerMeio(&head, &tail);

    impressao(head, tail);

    return 0;
}