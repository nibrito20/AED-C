#include <stdio.h>
#include <stdlib.h>

/*NÃO PODE USAR ARRAY E NEM STRING*/

typedef struct Node{
    char letra;
    struct Node *prox;
    struct Node *ant;
} Node;

int tamanho(Node *head, Node *tail){
    int count = 0;

    do{
        count++;
        head = head->prox;
    }
    while(head != tail->prox);

    return count;
}

int palindromo(Node *head, Node *tail){
    if(head != NULL){

        int count = tamanho(head, tail);
        
        if(count >= 3){
            /*
            JEITO PROFESSORA
            
            Node *ida = head;
            Node *volta = tail;

            for(int i = 0; i < count/2; i++){

                if(ida->letra != volta->letra) return 0;

                ida = ida->prox;
                volta = volta->ant;
                
            }

            return 1;
            */
    
            while(head != tail && head->ant != tail){ //atencao
    
                if(head->letra != tail->letra){
                    return 0;
                }
                head = head->prox;
                tail = tail->ant;
            }
            return 1;
            
        }
    }
    return 0;
}

void inserir(Node **head, Node **tail, char c){
    Node *novo = (Node*)malloc(sizeof(Node));

    if(novo != NULL){
        novo->letra = c;

        if(*head == NULL){
            novo->ant = novo;
            novo->prox = novo;
            *head = novo;
            *tail = *head;
        } else{
            (*tail)->prox = novo;
            novo->prox = *head;
            novo->ant = *tail;
            *tail = novo;
        }
    }
}

void imprimir(Node *head, Node *tail){
    if(head != NULL){
        do{
            printf("%c ", head->letra);
            head = head->prox;
        } while(head != tail->prox);
        printf("\n");
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    inserir(&head, &tail, 'a');
    inserir(&head, &tail, 'r');
    inserir(&head, &tail, 'a');
    inserir(&head, &tail, 'r');
    inserir(&head, &tail, 'a');

    imprimir(head, tail);

    printf("%d\n", palindromo(head, tail));

    return 0;
}