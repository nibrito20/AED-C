#include <stdio.h>
//refazer usando struct e tail

int main(){
    int n, m, k, i, j;
    scanf("%d %d %d", &n, &m, &k);

    int *fila1 = malloc(n * sizeof(int));
    int *fila2 = malloc(m * sizeof(int));

    if(fila1 == NULL || fila2 == NULL){
        return 1;
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &fila1[i]);
    }

    for(int j = 0; j < m; j++){
        scanf("%d", &fila2[j]);
    }

    i = 0;
    j = 0;

    if(k == 1){

        printf("%d\n", fila2[j]);
        printf("%d\n", fila1[i]);
        i++;
        j++;

        while(i < n || j < m){

            if(k < m){
                printf("%d\n", fila2[j]);
                j++;
            }

            if(i < n){
                printf("%d\n", fila1[i]);
                i++;
            }
        }
    } else if(k == 2){

        printf("%d\n", fila1[i]);
        printf("%d\n", fila2[j]);
        i++;
        j++;

        while(i < n || j < m){

            if(i < n){
                printf("%d\n", fila1[i]);
                i++;
            }

            if(k < m){
                printf("%d\n", fila2[j]);
                j++;
            }
        }
    }

    free(fila1);
    free(fila2);
    return 0;
}

