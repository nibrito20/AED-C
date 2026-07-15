# Resumo de Recursão em C

## O que é Recursão?
Recursão é quando uma função chama a si mesma para resolver um problema.

- Divide um problema grande em menores
- Precisa de um caso base para parar

---

## Estrutura Básica

```c
int funcao(int n){
    if(n == 0) // caso base
        return 0;

    return funcao(n - 1); // chamada recursiva
}
```

---

## Exemplo 1: Fatorial

Matemática:
5! = 5 * 4 * 3 * 2 * 1

Recursivo:
n! = n * (n-1)!

```c
int fatorial(int n){
    if(n == 0)
        return 1;

    return n * fatorial(n - 1);
}
```

---

## Exemplo 2: Contagem Regressiva

```c
#include <stdio.h>

void contagem(int n){
    if(n == 0){
        printf("Fim!\n");
        return;
    }

    printf("%d\n", n);
    contagem(n - 1);
}
```

Saída esperada:
```
5
4
3
2
1
Fim!
```

---

## Exemplo 3: Soma de 1 até n

```c
int soma(int n){
    if(n == 0)
        return 0;

    return n + soma(n - 1);
}
```

---

## Cuidados

- Sem caso base → loop infinito (stack overflow)
- Muitas chamadas → alto uso de memória

---

## Recursão vs Iteração

| Recursão | Iteração |
|----------|---------|
| Mais elegante | Mais eficiente |
| Mais fácil de escrever | Mais rápido |
| Usa pilha de chamadas | Usa menos memória |

---

## Quando usar recursão?

- Problemas que podem ser divididos em partes iguais
- Árvores
- Listas encadeadas
- Backtracking (caminhos, jogos, etc.)

---
