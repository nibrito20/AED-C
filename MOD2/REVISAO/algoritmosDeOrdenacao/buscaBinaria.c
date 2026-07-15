#include <stdio.h>

int buscabinaria(int arr[], int tamanho, int elemento) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (arr[meio] == elemento){
            return meio;
        }else if (arr[meio] < elemento){
            inicio = meio + 1;
        }else{
            fim = meio - 1; 
        }

    }
    return -1;
}