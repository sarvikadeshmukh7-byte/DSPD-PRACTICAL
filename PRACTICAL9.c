#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 7

int table[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
}

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

void insertKey(int key) {
    int index = hashFunc(key);
    int startIndex = index;
    while (table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    table[index] = key;
    printf("Inserted key %d at slot %d\n", key, index);
}

void printTable() {
    printf("Slot : Value\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1) {
            printf("%2d   : (empty)\n", i);
        } else {
            printf("%2d   : %d\n", i, table[i]);
        }
    }
}

int main() {
    initTable();
    int keysToInsert[] = {16, 23, 5, 47, 9, 75};
    int numKeys = sizeof(keysToInsert) / sizeof(keysToInsert[0]);
    printf("Inserting keys...\n");
    for (int i = 0; i < numKeys; i++) {
        insertKey(keysToInsert[i]);
    }
    printf("\nFinal state of hash table:\n");
    printTable();
    return 0;
}

