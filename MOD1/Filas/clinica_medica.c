#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nome[30];
    struct Node *next;
} Node;

void inserir(Node **head, char *nome){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo == NULL){
        return;
    }

    if(*head == NULL){
        strcpy(novo->nome, nome);
        novo->next = NULL;
        *head = novo;
        return;
    }

    strcpy(novo->nome, nome);
    novo->next = NULL;
    Node *aux = *head;

    while(aux->next != NULL) aux = aux->next;

    aux->next = novo;
}

void remover(Node **head){
    if (*head == NULL) return;

    Node *remover = *head;
    *head = remover->next;
    free(remover);
}

int posicao(Node *head, char *nome){
    int pos = 1;
    while(head != NULL){
        if(strcmp(head->nome, nome) == 0){
            return pos;
        }
        head = head->next;
        pos++;   
    }
    return 0;
}

int main(){
    Node *head = NULL;
    int count = 0;

    while(1){

        int acao;
        scanf("%d", &acao);
        char nome[30];

        if(acao > 5 && acao < 1){
            printf("opcao invalida\n");
        }

        if(acao == 1){
            scanf("%s", nome);
            inserir(&head, nome);
        } 
        else if(acao == 2){
            remover(&head);
            count++;
        } 
        else if(acao == 3){
            scanf("%s", nome);
            int resul = posicao(head, nome);
            if(resul == 0){
                printf("Não existe esse paciente.\n");
            } else{
                printf("O paciente é o %d° da fila.\n", resul);
            }
        }
        else if(acao == 4){
            printf("%d pacientes atendidos.\n", count);
        }
        else{
            printf("saindo...\n");
            break;
        }
    }
}