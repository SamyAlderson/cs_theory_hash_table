#ifndef UTILS_H
#define UTILS_H

#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the hash of a string
unsigned int str_hash(const char* str);

// Function to check if a string is empty
bool is_empty(const char* str);

// Function to get the length of a string
size_t str_len(const char* str);

// Function to copy a string
char* str_copy(const char* src);

// Function to free a dynamically allocated string
void str_free(char* str);

// Function to check if two integers are equal
bool int_eq(int a, int b);

// Function to print an error message and exit the program
void error(const char* message);

// Function to print a success message and exit the program
void success(const char* message);

#endif  // UTILS_H