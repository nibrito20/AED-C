#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

void inserir(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    
    if(novo != NULL){
        novo->valor = valor;
        
        if(*head == NULL){
            novo->next = novo;
            *head = novo;
            *tail = novo;
        } else{
            (*tail)->next = novo;
            novo->next = *head;
            *tail = novo;
        }
    }
}

int multiplicacao(Node *head, Node *tail){
    
    if(head != NULL){
        
        int count = 0;
        Node *aux = head;
        
        do{
            count++;
            aux = aux->next;
        } while(aux != tail->next);
        
        if(count >= 2){
            
            int multi = 0;
            aux = head;
            
            do{
                if(aux->next == head){ 
                    multi += aux->valor * aux->valor;
                    break;
                }
            
                multi += aux->valor * aux->next->valor;
                aux = aux->next->next;
            } while(aux != head);
            
            return multi;
        } else{
            printf("Tamanho da lista é insuficiente.\n");
            return 0;
        }
    }
    return 0;//só p sair o warning
}

int main(){
    
    Node *head = NULL;
    Node *tail = NULL;
    
    inserir(&head, &tail, 1);
    inserir(&head, &tail, 2);
    inserir(&head, &tail, 3);
    inserir(&head, &tail, 4);
    inserir(&head, &tail, 5);
    
    printf("Resultado da multiplicação: %d.\n", multiplicacao(head, tail));
    
    return 0;
}