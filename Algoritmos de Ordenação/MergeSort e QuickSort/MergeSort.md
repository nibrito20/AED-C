# Merge Sort

## Ideia geral

O **Merge Sort** é um algoritmo de ordenação que segue o paradigma **Dividir para Conquistar**.

Ele funciona assim:
- Divide o problema em partes menores
- Resolve cada parte recursivamente
- Junta (intercala) as partes já ordenadas

---

## Como funciona (passo a passo)

1. **Divisão**
   - O array é dividido ao meio
   - Isso continua até que cada subarray tenha **apenas 1 elemento**

2. **Conquista (recursão)**
   - Cada subarray de 1 elemento já está naturalmente ordenado

3. **Combinação (merge)**
   - Os subarrays são **intercalados (merge)** em ordem crescente
   - Esse processo continua até reconstruir o array completo ordenado

---

## Exemplo simples

Array inicial:  
``
[8, 3, 5, 2]
``

Divisão:  
``[8, 3]`` ``[5, 2]``  

``[8]`` ``[3]`` ``[5]`` ``[2]``

Agora começa a junção (merge):  
``[8] + [3] → [3, 8]`` 

``[5] + [2] → [2, 5]``

Última junção:  
``[3, 8] + [2, 5] → [2, 3, 5, 8]``


---

## Características importantes

- ✅ **Recursivo**
- ✅ **Estável**  
  → mantém a ordem de elementos iguais

- ❌ **Não é in-place**  
  → precisa de memória auxiliar

- ⏱️ **Complexidade**
  - Melhor caso: `O(n log n)`
  - Médio caso: `O(n log n)`
  - Pior caso: `O(n log n)`

Consegue ser mais rápido que a melhor caso da versão[0] e da versão[1] do BubbleSort, quando não há a flag de parada.

---
