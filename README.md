C - Stacks, Queues - LIFO, FIFO
The Monty Bytecode Interpreter is a program written in C programming language that reads and executes Monty bytecode files. Monty is a simple programming language that uses a stack data structure.

Features
-Reads Monty bytecode files and executes the specified instructions.
-Supports various stack manipulation and arithmetic operations.
-Provides clear error messages for incorrect input or unexpected behavior.

Getting Started

Prerequisites
A C compiler (e.g., GCC)

Installation
Clone the repository:
git clone https://github.com/Midorichie/monty

Compile the source code:
-gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

Usage
-Run the Monty interpreter with the following command:

./monty bytecode_file

Replace bytecode_file with the path to your Monty bytecode file.

Supported Opcodes
The interpreter supports the following opcodes:

Supported Opcodes
The interpreter supports the following opcodes:
0. push
1. pint
2. pop
3. swap
4. add
5. nop
6. sub
7. div
8. mul
9. mod
10. comments
11. pchar
12. pstr
13. rotl
14. rotr
15. stack
16. Brainf*ck
17. Add two digits

Contributor
This project was done by:
- Hammed Yakub hamsohood@gmail.com
