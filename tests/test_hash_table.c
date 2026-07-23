#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HASH_TABLE_SIZE 1024

// Test hash table implementation
void test_hash_table_insert(void) {
    // Initialize hash table
    HashTable_t *hash_table = hash_table_init(HASH_TABLE_SIZE);

    // Test insert function
    char key[] = "key1";
    char value[] = "value1";
    hash_table_insert(hash_table, key, value);

    // Assert value is correctly inserted
    assert(strcmp(hash_table_lookup(hash_table, key), value) == 0);

    // Clean up
    hash_table_free(hash_table);
}

// Test hash table lookup
void test_hash_table_lookup(void) {
    // Initialize hash table
    HashTable_t *hash_table = hash_table_init(HASH_TABLE_SIZE);

    // Test lookup function
    char key[] = "key1";
    char value[] = "value1";
    hash_table_insert(hash_table, key, value);

    // Assert value is correctly looked up
    assert(strcmp(hash_table_lookup(hash_table, key), value) == 0);

    // Clean up
    hash_table_free(hash_table);
}

// Test hash table delete
void test_hash_table_delete(void) {
    // Initialize hash table
    HashTable_t *hash_table = hash_table_init(HASH_TABLE_SIZE);

    // Insert a value
    char key[] = "key1";
    char value[] = "value1";
    hash_table_insert(hash_table, key, value);

    // Test delete function
    hash_table_delete(hash_table, key);

    // Assert value is correctly deleted
    assert(hash_table_lookup(hash_table, key) == NULL);

    // Clean up
    hash_table_free(hash_table);
}

int main() {
    // Run test cases
    test_hash_table_insert();
    test_hash_table_lookup();
    test_hash_table_delete();

    return 0;
}
```

```c
// Header file for test cases
#ifndef TEST_HASH_TABLE_H
#define TEST_HASH_TABLE_H

void test_hash_table_insert(void);
void test_hash_table_lookup(void);
void test_hash_table_delete(void);

#endif
```

```c
// Hash table implementation
// (Not included in this file, see src/hash_table.c)
```

```c
// Header file for utility functions
#ifndef UTILS_H
#define UTILS_H

typedef struct HashTable {
    // Hash table data structure
} HashTable_t;

HashTable_t *hash_table_init(unsigned int size);
void hash_table_free(HashTable_t *hash_table);
void hash_table_insert(HashTable_t *hash_table, char *key, char *value);
char *hash_table_lookup(HashTable_t *hash_table, char *key);
void hash_table_delete(HashTable_t *hash_table, char *key);

#endif