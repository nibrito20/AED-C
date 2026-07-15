#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparacoes, trocas;

void gerar_ordenado(int arr[], int n)  { for (int i=0;i<n;i++) arr[i]=i+1; }
void gerar_invertido(int arr[], int n) { for (int i=0;i<n;i++) arr[i]=n-i; }
void gerar_aleatorio(int arr[], int n) { srand(42); for (int i=0;i<n;i++) arr[i]=rand()%100000; }

void cocktail_sort(int arr[], int n) {
    int lo = 0, hi = n-1, trocou;
    while (lo < hi) {
        trocou = 0;
        /* Passe da esquerda → direita
           Empurra o maior elemento solto para a posição correta à direita */
        for (int i=lo; i<hi; i++) {
            comparacoes++;
            if (arr[i] > arr[i+1]) {
                int tmp = arr[i]; arr[i] = arr[i+1]; arr[i+1] = tmp;
                trocas++; trocou = 1;
            }
        }
        hi--;
        if (!trocou) break;
        trocou = 0;
        /* Passe da direita → esquerda
           Empurra o menor elemento solto para a posição correta à esquerda */
        for (int i=hi; i>lo; i--) {
            comparacoes++;
            if (arr[i] < arr[i-1]) {
                int tmp = arr[i]; arr[i] = arr[i-1]; arr[i-1] = tmp;
                trocas++; trocou = 1;
            }
        }
        lo++;
        if (!trocou) break;
    }
}

void executar(const char *cenario, int arr[], int n) {
    comparacoes = 0; trocas = 0;
    clock_t ini = clock();
    cocktail_sort(arr, n);
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

        printf("=== Cocktail Sort | N = %d ===\n", n);

        gerar_ordenado(arr, n);  executar("Ja ordenado", arr, n);
        gerar_invertido(arr, n); executar("Invertido",   arr, n);
        gerar_aleatorio(arr, n); executar("Aleatorio",   arr, n);

        free(arr);
    }
    return 0;
}