#include <stdio.h>

int buscalinear(int arr[], int tam, int elemento) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == elemento) {
        return i;
        }
    }
    return -1;
}