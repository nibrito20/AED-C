# Rotações em Árvores AVL

## O que é uma AVL?

É uma ABB que se **auto-balanceia**. Ela garante que a diferença de altura entre a subárvore esquerda e direita de qualquer nó seja no máximo **1**.

Chamamos isso de **Fator de Balanceamento (FB)**:

```
FB = altura(esquerda) - altura(direita)
```

- FB entre -1 e 1 → nó **balanceado** ✅
- FB = 2 ou -2 → nó **desbalanceado**, precisa rotacionar ❌

---

## Rotação Simples à Direita

### Quando usar?
Quando o desbalanceamento acontece no **filho esquerdo do esquerdo** (FB = +2 no nó, FB = +1 no filho).

### Exemplo — inserindo 3, 2, 1:

```
Inseriu 3:        Inseriu 2:        Inseriu 1:
    3                 3                 3   ← FB = +2 (desbalanceado!)
                     /                 /
                    2                 2
                                     /
                                    1
```

### Como a rotação funciona:

```
    3  (desbalanceado)           2
   /          →                / \
  2                           1   3
 /
1
```

O **filho esquerdo (2) sobe**, e o **nó desbalanceado (3) desce para a direita**.

### Código:

```c
Arv* rotacaoDireita(Arv *y) {
    Arv *x = y->esq;       // x é o filho esquerdo
    Arv *t = x->dir;       // guarda a subárvore direita de x

    // faz a rotação
    x->dir = y;            // y desce para a direita de x
    y->esq = t;            // a subárvore guardada vai para esquerda de y

    return x;              // x agora é a nova raiz
}
```

### Passo a passo do código:

```
Antes:          Guarda t:       Depois:
    y               y              x
   /               /              / \
  x           →  x          →   ?   y
   \              (t=NULL)          /
    t                              t
```

---

## Rotação Simples à Esquerda

### Quando usar?
Quando o desbalanceamento acontece no **filho direito do direito** (FB = -2 no nó, FB = -1 no filho).

### Exemplo — inserindo 1, 2, 3:

```
Inseriu 1:        Inseriu 2:        Inseriu 3:
    1                 1                 1   ← FB = -2 (desbalanceado!)
                       \                 \
                        2                 2
                                           \
                                            3
```

### Como a rotação funciona:

```
1  (desbalanceado)               2
 \            →                 / \
  2                            1   3
   \
    3
```

O **filho direito (2) sobe**, e o **nó desbalanceado (1) desce para a esquerda**.

### Código:

```c
Arv* rotacaoEsquerda(Arv *x) {
    Arv *y = x->dir;       // y é o filho direito
    Arv *t = y->esq;       // guarda a subárvore esquerda de y

    // faz a rotação
    y->esq = x;            // x desce para a esquerda de y
    x->dir = t;            // a subárvore guardada vai para direita de x

    return y;              // y agora é a nova raiz
}
```

### Passo a passo do código:

```
Antes:          Guarda t:       Depois:
x                   x               y
 \                   \             / \
  y             →     y      →   x   ?
 /              (t=NULL)          \
t                                  t
```

---

## Comparando as duas rotações

| | Rotação Direita | Rotação Esquerda |
|---|---|---|
| **Quando ocorre** | Inserção à esquerda | Inserção à direita |
| **FB do nó** | +2 | -2 |
| **Quem sobe** | Filho esquerdo | Filho direito |
| **Quem desce** | Nó desbalanceado (vai pra direita) | Nó desbalanceado (vai pra esquerda) |

---

## Macete para lembrar

> A rotação sempre vai para o **lado oposto** do desbalanceamento!
- Pesado na **esquerda** → rotaciona para **direita**
- Pesado na **direita** → rotaciona para **esquerda**