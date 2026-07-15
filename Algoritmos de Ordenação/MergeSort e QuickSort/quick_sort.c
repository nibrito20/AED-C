#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparacoes, trocas_count;

void gerar_ordenado(int arr[], int n)  { for (int i=0;i<n;i++) arr[i]=i+1; }
void gerar_invertido(int arr[], int n) { for (int i=0;i<n;i++) arr[i]=n-i; }
void gerar_aleatorio(int arr[], int n) { srand(42); for (int i=0;i<n;i++) arr[i]=rand()%100000; }

void troca(int v[], int i, int j) {
    int aux = v[i]; v[i] = v[j]; v[j] = aux;
    trocas_count++;
}

int particao(int v[], int inicio, int fim) {
    int pivot = inicio, indice = fim;
    for (int i = fim; i > inicio; i--) {
        comparacoes++;
        if (v[i] >= v[pivot]) { troca(v, i, indice); indice--; }
    }
    troca(v, pivot, indice);
    return indice;
}

void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int indice = particao(v, inicio, fim);
        quicksort(v, inicio, indice - 1);
        quicksort(v, indice + 1, fim);
    }
}

void executar(const char *cenario, int arr[], int n) {
    comparacoes = 0; trocas_count = 0;
    clock_t ini = clock();
    quicksort(arr, 0, n-1);
    clock_t fim = clock();
    double ms = (double)(fim - ini) / CLOCKS_PER_SEC * 1000.0;
    printf("  [%s]\n", cenario);
    printf("  Tempo: %.3f ms | Comparacoes: %ld | Trocas: %ld\n\n", ms, comparacoes, trocas_count);
}

int main() {
    int tamanhos[] = {1000, 5000, 10000};

    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *arr = malloc(n * sizeof(int));

        printf("=== Quick Sort | N = %d ===\n", n);

        gerar_ordenado(arr, n);  executar("Ja ordenado", arr, n);
        gerar_invertido(arr, n); executar("Invertido",   arr, n);
        gerar_aleatorio(arr, n); executar("Aleatorio",   arr, n);

        free(arr);
    }
    return 0;
}