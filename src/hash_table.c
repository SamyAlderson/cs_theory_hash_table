// Include the necessary header file for the hash table
#include "utils.h"

// Define the hash table structure
typedef struct HashTable {
    int size;
    int capacity;
    int* keys;
    int* values;
} HashTable;

// Function to create a new hash table
HashTable* createHashTable(int capacity) {
    HashTable* table = malloc(sizeof(HashTable));
    table->size = 0;
    table->capacity = capacity;
    table->keys = malloc(capacity * sizeof(int));
    table->values = malloc(capacity * sizeof(int));
    return table;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* table, int key, int value) {
    // Calculate the index using the hash function
    int index = key % table->capacity;
    // Check if the key already exists in the table
    for (int i = 0; i < table->size; i++) {
        if (table->keys[i] == key) {
            // Update the value if the key already exists
            table->values[i] = value;
            return;
        }
    }
    // If the key does not exist, add it to the table
    table->keys[table->size] = key;
    table->values[table->size] = value;
    table->size++;
}

// Function to get the value associated with a key
int getValue(HashTable* table, int key) {
    // Calculate the index using the hash function
    int index = key % table->capacity;
    // Check if the key exists in the table
    for (int i = 0; i < table->size; i++) {
        if (table->keys[i] == key) {
            // Return the value associated with the key
            return table->values[i];
        }
    }
    // If the key does not exist, return -1
    return -1;
}