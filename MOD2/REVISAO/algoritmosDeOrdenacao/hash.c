#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define TOMBSTONE -1

typedef struct {
    int key;
    int value;
} Entry;

Entry* hashTable[TABLE_SIZE];

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index] != NULL && hashTable[index]->key != TOMBSTONE && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Table cheia!\n");
            return;
        }
    }

    if (hashTable[index] == NULL || hashTable[index]->key == TOMBSTONE) {
        hashTable[index] = (Entry*) malloc(sizeof(Entry));
    }
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int search(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }

    return -1; // Key not found
}

void delete(int key) {
    int index = hash(key);
    int originalIndex = index;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            hashTable[index]->key = TOMBSTONE;
            hashTable[index]->value = 0;
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }

    printf("Chave não encontrada!\n");
}

void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL && hashTable[i]->key != TOMBSTONE) {
            printf("Index %d: Chave = %d, Valor = %d\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("Index %d: ~\n", i);
        }
    }
}

int main() {
    insert(1, 10);
    insert(2, 20);
    insert(12, 30);  // colisao com chave 2
    insert(22, 40);  // mais colisao

    displayTable();

    printf("\n\nValor na chave 12: %d\n", search(12));

    delete(12);

    displayTable();


    return 0;
}