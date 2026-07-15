#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparacoes, trocas;

void gerar_ordenado(int arr[], int n)  { for (int i=0;i<n;i++) arr[i]=i+1; }
void gerar_invertido(int arr[], int n) { for (int i=0;i<n;i++) arr[i]=n-i; }
void gerar_aleatorio(int arr[], int n) { srand(42); for (int i=0;i<n;i++) arr[i]=rand()%100000; }

void intercala(int inicio, int meio, int fim, int v[]) {
    int inicio_v01 = inicio, inicio_v02 = meio+1, poslivre = 0;
    int aux[fim - inicio + 1];
    while (inicio_v01 <= meio && inicio_v02 <= fim) {
        comparacoes++;
        if (v[inicio_v01] <= v[inicio_v02]) aux[poslivre++] = v[inicio_v01++];
        else { aux[poslivre++] = v[inicio_v02++]; trocas++; }
    }
    while (inicio_v01 <= meio) aux[poslivre++] = v[inicio_v01++];
    while (inicio_v02 <= fim)  aux[poslivre++] = v[inicio_v02++];
    for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++)
        v[inicio_v01] = aux[inicio_v01 - inicio];
}

void merge_sort(int inicio, int fim, int v[]) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(inicio, meio, v);
        merge_sort(meio+1, fim, v);
        intercala(inicio, meio, fim, v);
    }
}

void executar(const char *cenario, int arr[], int n) {
    comparacoes = 0; trocas = 0;
    clock_t ini = clock();
    merge_sort(0, n-1, arr);
    clock_t fim = clock();
    double ms = (double)(fim - ini) / CLOCKS_PER_SEC * 1000.0;
    printf("  [%s]\n", cenario);
    printf("  Tempo: %.3f ms | Comparacoes: %ld | Trocas*: %ld\n\n", ms, comparacoes, trocas);
}

int main() {
    int tamanhos[] = {1000, 5000, 10000};

    for (int t = 0; t < 3; t++) {
        int n = tamanhos[t];
        int *arr = malloc(n * sizeof(int));

        printf("=== Merge Sort | N = %d ===\n", n);

        gerar_ordenado(arr, n);  executar("Ja ordenado", arr, n);
        gerar_invertido(arr, n); executar("Invertido",   arr, n);
        gerar_aleatorio(arr, n); executar("Aleatorio",   arr, n);

        free(arr);
    }
    printf("(*) Trocas = elementos copiados do vetor direito na intercalacao\n");
    return 0;
}