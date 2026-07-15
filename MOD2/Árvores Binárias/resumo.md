# Árvores Binárias


## Árvores

As árvores são estruturas mais adequadas para representar **dados de forma hierárquica**. Ex: árvore genealógica e hierarquia de diretórios de um servidor.

### Características

- São um conjunto finito de elementos que possuem um **elemento raíz** (head) e **várias vértices** da árvore que são ligados pelas arestas.
- Cada vértice (nó), execeto a raíz, tem exetamente um **antecessor/pai**.
- Cada vértice tem nós sucessores: filhos. Vértices sem filhos são chamados de **folha**. E vétices de um mesmo pai são **irmãos**.
- Os vértices de uma árvore estão classificados em **níveis**, que corresponde ao número de nós no caminho entre o vértice e a raíz.
- A **altura de uma árvore** correponde ao **maior nível**, ou seja, a maior distância entre a raíz e qualquer vértice.

---

## Árvores Binárias

Conjunto finito de zero ou mais nós, onde se a quantidade de
nós for maior que zero:
- Um nó é a raíz da árvore
- Os demais formam dois conjuntos, que representam duas sub-árvores: esquerda e direita (**máximo grau 2**).

### Conceitos

- **Árvore estritamente binária**: Quando todos os nós têm zero OU dois filhos.

- **Árvore cheia**: Acontece quando as sub-árvores são folhas apenas no último nível.

### Percurso

Tendo em vista a árvore:

```
      A           ← Nível 0 (Raíz)
    /   \
   B     C        ← Nível 1
  / \   / \
 E   F G   H     ← Nível 2 (Folhas)
```

#### Pré-ordem (RED - RAÍZ, ESQUERDA, DIREITA)

Saída: **A**, B, E, F, C, G, H


#### In-ordem (ERD - ESQUERDA, RAÍZ, DIREITA)

Saída: E, B, F, **A**, G, C, H

#### Pós-ordem (EDR - ESQUERDA, DIREITA, RAÍZ)

Saída: E, F, B, G, H, C, **A**

---

## Árvores Binárias de Busca (ABB)

### Critérios

- A chave de cada nó da subárvore _**esquerda**_ da raiz é _**menor**_ do que a chave da própria raiz.
- A chave de cada nó da subárvore _**direita**_ da raiz é _**maior**_ do que a chave da própria raiz.

### Estrutura

```c
typedef struct Arv {
    int chave;
    struct Arv *esq;
    struct Arv *dir;
} Arv;
```

Obs: Mais campos geralmente são adicionados dependendo do problema em questão.

---