#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define TABLE_SIZE 16
#define MAX_KEY_LENGTH 256

typedef struct {
    int key;
    char value[MAX_KEY_LENGTH];
} entry_t;

typedef struct {
    entry_t *entries;
    int size;
} hash_table_t;

hash_table_t *hash_table_create() {
    hash_table_t *table = malloc(sizeof(hash_table_t));
    if (table == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    table->entries = calloc(TABLE_SIZE, sizeof(entry_t));
    if (table->entries == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    table->size = TABLE_SIZE;

    return table;
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}

int hash_table_insert(hash_table_t *table, int key, const char *value) {
    int index = hash_function(key);

    if (table->entries[index].key != 0) {
        for (int i = index + 1; i < TABLE_SIZE; i++) {
            if (table->entries[i].key == 0) {
                index = i;
                break;
            }
        }
    }

    if (index >= TABLE_SIZE) {
        fprintf(stderr, "Hash table is full.\n");
        exit(EXIT_FAILURE);
    }

    if (table->entries[index].key != 0) {
        fprintf(stderr, "Key already exists.\n");
        return -1;
    }

    table->entries[index].key = key;
    strcpy(table->entries[index].value, value);

    return 0;
}

int hash_table_lookup(hash_table_t *table, int key) {
    int index = hash_function(key);

    if (table->entries[index].key == key) {
        return 0; // found
    }

    for (int i = index + 1; i < TABLE_SIZE; i++) {
        if (table->entries[i].key == key) {
            return 0; // found
        }
    }

    return -1; // not found
}

int hash_table_delete(hash_table_t *table, int key) {
    int index = hash_function(key);

    if (table->entries[index].key != key) {
        for (int i = index + 1; i < TABLE_SIZE; i++) {
            if (table->entries[i].key == key) {
                index = i;
                break;
            }
        }
    }

    if (index >= TABLE_SIZE) {
        fprintf(stderr, "Key not found.\n");
        return -1;
    }

    table->entries[index].key = 0;
    table->entries[index].value[0] = '\0';

    return 0;
}

void hash_table_destroy(hash_table_t *table) {
    free(table->entries);
    free(table);
}