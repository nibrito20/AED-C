//LISTA DUPLAMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *ant;
    struct Node *next;
} Node;

//OBS: não use tail!

void insercaoInicio(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){

            novo->ant = NULL;
            novo->next = NULL;
            *head = novo;

        } else{

            novo->ant = NULL;
            novo->next = *head;
            (*head)->ant = novo;
            *head = novo;

        }
    }
}

void insercaoFinal(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){

            novo->ant = NULL;
            novo->next = NULL;
            *head = novo;

        } else{
            
            Node *aux = *head;
            while(aux->next != NULL) aux = aux->next;

            novo->ant = aux;
            novo->next = NULL;
            aux->next = novo;

        }
    }
}

int quantidade(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

void insercaoMeio(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            novo->ant = NULL;
            novo->next = NULL;
            *head = novo;
        } else{
            
            int meio = quantidade(*head) / 2;
            Node *aux = *head;
            int count = 0;

            if(aux->next == NULL){
                novo->ant = aux;
                novo->next = NULL;
                aux->next = novo;
                return;
            }
            
            while(aux->next != NULL && count+1 != meio){
                count++;
                aux = aux->next;
            }

            if(aux->next != NULL){
                novo->ant = aux;
                novo->next = aux->next;
                aux->next->ant = novo;
                aux->next = novo;
            } else{
                printf("Índice inválido\n");
            }
        }
    }
}

void removerInicio(Node **head){
    if(*head != NULL){
        
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
        } else{
            Node *remover = *head;
            *head = (*head)->next;
            (*head)->ant = NULL;
            free(remover);
        }
    }
}

void removerFinal(Node **head){
    if(*head != NULL){

        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
        } else{

            Node *aux = *head;
            while(aux->next->next != NULL) aux = aux->next;

            Node *remover = aux->next;
            aux->next = NULL;
            free(remover);
        }
    }
}

void removerMeio(Node **head){

    if(*head != NULL){
        
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;

        } else{

            int meio = quantidade(*head) / 2;
            Node *aux = *head;
            int count = 0;

            while(aux->next != NULL && count+1 != meio){
                count++;
                aux = aux->next;
            }

            if(aux->next != NULL){
                Node *remover = aux->next;
                aux->next = aux->next->next;
                aux->next->ant = aux;
                free(remover);
            } else{
                printf("Índice inválido\n");
            }
        }
    }
}

void impresao(Node *head){
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->next;
    }
    printf("\n");
}

void impresaoInverso(Node *head){
    while(head->next != NULL) head = head->next;
    while(head != NULL){
        printf("%d ", head->valor);
        head = head->ant;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;

    insercaoFinal(&head, 2);
    insercaoFinal(&head, 4);
    insercaoFinal(&head, 5);

    insercaoInicio(&head, 1);
    insercaoMeio(&head, 3);

    impresao(head);
    impresaoInverso(head);
    
    removerInicio(&head);
    removerFinal(&head);
    removerMeio(&head);
    
    impresao(head);
    impresaoInverso(head);
    return 0;
}