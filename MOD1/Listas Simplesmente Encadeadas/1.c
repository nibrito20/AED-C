/*
Crie uma função que indique se um determinado valor está presente na lista (primeira ocorrência) 
- Retorne 0 se o valor não estiver na lista 
- Retorne 1 se o valor estiver na lista
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir(Node **head, int x){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = x;
        novo->next = *head;
        *head = novo;
    }
}

int procurar(Node *head, int x){
    while(head != NULL){
        if(head->valor == x){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

void inserir_final(Node *head, int x){
    Node *novo_num = (Node*)malloc(sizeof(Node));
    novo_num->valor = x;
    novo_num->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = novo_num;
}

void inserir_posicao(Node **head, int pos, int x){
    Node *novo_num = (Node*)malloc(sizeof(Node));
    novo_num->valor = x;

    if(pos == 0){
        novo_num->next = *head;
        *head = novo_num;
        return;
    }
    int count = 0;
    Node *aux = *head;
    while(aux != NULL && count < pos - 1){
        count++;
        aux = aux->next;
    }
    novo_num->next = aux->next;
    aux->next = novo_num;
}

void remover_final(Node *head){
    while(head->next->next != NULL){
        head = head->next;
    }
    free(head->next);
    head->next = NULL;
}

void remover_posicao(Node **head, int pos){
    if(pos == 0){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    int count = 0;
    Node *aux = *head;
    while(aux != NULL && count < pos - 1){
        count++;
        aux = aux->next;
    }
    Node *remover = aux->next;
    aux->next = remover->next;
    free(remover);
}

int main(){
    Node *head = NULL;
    inserir(&head, 10);
    inserir(&head, 5);
    inserir(&head, 2);
    int num;
    scanf("%d", &num);
    printf("%d\n", procurar(head, num));
    free(head);
    return 0;
}
