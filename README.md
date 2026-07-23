# cs_theory_hash_table
A minimal hash table implementation in C for learning purposes

## What it does
This is a basic hash table implementation in C, supporting insert, lookup, and delete operations. I built it as a teaching tool to help understand hash table fundamentals.

## Install
To use this project, clone the repository and compile it manually:
```bash
git clone https://github.com/SamyAlderson/cs_theory_hash_table.git
cd cs_theory_hash_table
gcc -o hash_table hash_table.c
```
## Usage
To run the hash table, execute the compiled binary:
```bash
./hash_table
```
You can interact with the hash table by typing `insert key value`, `lookup key`, or `delete key` commands.

## Build from source
You can build the project directly from source using:
```bash
gcc -o hash_table hash_table.c
```
## Project structure
- `hash_table.c`: the main hash table implementation
- `hash_table.h`: the header file for the hash table API
- `test_hash_table.c`: a test suite for the hash table implementation

## License
Copyright (c) 2026 SamyAlderson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.