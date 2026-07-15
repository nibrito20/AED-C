#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparacoes, trocas;
 
void gerar_ordenado(int arr[], int n)  { for (int i=0;i<n;i++) arr[i]=i+1; }
void gerar_invertido(int arr[], int n) { for (int i=0;i<n;i++) arr[i]=n-i; }
void gerar_aleatorio(int arr[], int n) { srand(42); for (int i=0;i<n;i++) arr[i]=rand()%100000; }

void bubble_sort(int arr[], int n) {
    int trocou;
    for (int i=0; i<n-1; i++) {
        trocou = 0;
        for (int j=0; j<n-i-1; j++) {
            comparacoes++;
            if (arr[j] > arr[j+1]) {
                int aux = arr[j]; arr[j] = arr[j+1]; arr[j+1] = aux;
                trocas++; trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

void executar(const char *cenario, int arr[], int n) {
    comparacoes = 0; trocas = 0;
    clock_t ini = clock();
    bubble_sort(arr, n);
    clock_t fim = clock();
    double ms = (double)(fim - ini) / CLOCKS_PER_SEC * 1000.0;
    printf("  [%s]\n", cenario);
    printf("  Tempo: %.3f ms | Comparacoes: %ld | Trocas: %ld\n\n", ms, comparacoes, trocas);
}


int main() {
    int tamanhos[] = {1000, 5000, 10000};
 
    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *arr = malloc(n * sizeof(int));
 
        printf("=== Bubble Sort | N = %d ===\n", n);
 
        gerar_ordenado(arr, n);  executar("Ja ordenado",  arr, n);
        gerar_invertido(arr, n); executar("Invertido",    arr, n);
        gerar_aleatorio(arr, n); executar("Aleatorio",    arr, n);
 
        free(arr);
    }
    return 0;
}