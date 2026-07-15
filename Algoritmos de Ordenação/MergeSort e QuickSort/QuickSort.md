# QuickSort

## Ideia geral

O **QuickSort** é um algoritmo de ordenação que segue o paradigma **Dividir para Conquistar**.

Ele funciona assim:
- Escolhe um elemento como **pivot**
- Divide o vetor em duas partes: menores à esquerda, maiores à direita
- Ordena cada parte recursivamente

---

## Como funciona (passo a passo)

1. **Divisão**
   - Um pivot é escolhido (geralmente o primeiro elemento)
   - O vetor é particionado em dois subvetores a partir do pivot

2. **Conquista (recursão)**
   - Cada subvetor é ordenado recursivamente com seu próprio pivot

3. **Combinação (in-place)**
   - Os elementos já são ordenados no vetor original ao longo das chamadas recursivas, sem precisar de um array auxiliar

---

## Exemplo simples

Array inicial:
[3, 8, 2, 5]

Pivot = `3`, particionamento:
[2] [3] [8, 5]

Pivot = `8`, particionamento:
[2] [3] [5] [8]

Resultado:
[2, 3, 5, 8]

---

## Complexidade de Tempo

- **Melhor caso: `O(n log n)`**
  - Ocorre quando em cada particionamento os subvetores possuem metade dos elementos
  - Na função quicksort, os subvetores são particionados na metade para as chamadas recursivas, o restante da função possui O(1)
  - Também é considerada a complexidade da função `particao`, que possui O(n)
  - O caso médio tem a mesma complexidade

- **Pior caso: `O(n²)`**
  - Ocorre quando o pivot escolhido é sempre o maior ou o menor elemento
  - Pode ser evitado com uma boa estratégia de escolha do pivot

---

## Características importantes

- ✅ **Recursivo**
- ✅ **In-place**
  → não precisa de memória auxiliar

- ❌ **Não é estável**
  → não garante a ordem relativa de elementos iguais

- Apesar de ter o mesmo melhor caso que o Merge Sort `O(n log n)`. O QuickSort leva vantagem em uso de memória, já que o Merge Sort utiliza um array auxiliar de mesmo tamanho que o original

---

Melhor caso O(n log n): Acontece quando o pivot escolhido sempre divide o vetor ao meio, resultando em subvetores de tamanho igual a cada divisão. Isso ocorre porque a complexidade da recursão é log(n), e como a função partição percorre todos os n elementos em cada subvetor, a complexidade total é O(n log n).

Pior caso O(n^2): Ocorre quando o pivot é sempre o maior ou o menor elemento, fazendo com que um lado fique com n-1 elementos e o outro com nenhum. Isso faz a recursão ter profundidade n em vez de log n, elevando a complexidade para O(n²). Esse caso pode ser evitado com uma boa estratégia de escolha do pivot.