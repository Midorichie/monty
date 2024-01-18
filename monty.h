#ifndef _MONTY_H
#define _MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* DATA STRUCTURES */
/**
 * struct stack_s - doubly linked list representation of a stack/queue
 * @n: Integer
 * @prev: points to the previous element of the queue/stack
 * @next: points to the next element of the queue/stack
 *
 * Desc: doubly linked list node structure for queue,stack, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function that will handle the opcode
 *
 * Desc: opcode and its function
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct File_content - a struct that contains the item of a line
 * @file: pointer to the file
 * @line: a pointer to the line read by getline
 * @line_number: the line number beed read
 * @num_tokens: number of tokens passed
 * @tokens: contains the tokenized string
 * @opcode_instruction: list holding an instruction_t structure
 * @head: A pointer to the head
 */

typedef struct File_content
{
	FILE *file;
	char *line;
	unsigned int line_number;
	int num_tokens;
	char **tokens;
	instruction_t *opcode_instruction;
	stack_t *head;
} File_content;

extern File_content *file_ptr;

/* FUNCTION PROTOTYPES */

void push(stack_t **stack, unsigned int line_number);
void free_head(void);
void count_arguments(int argc);
void parse_line(void);
void get_opcode_func(void);
int main(int argc, char **argv);
void handle_file_opening(const char *name_of_file, FILE **file);
File_content *allocated_file_content(void);
void invalid_instruction(void);
void free_stack(stack_t *head);
void fclose_file(void);
void free_tokens(void);
void execute_opcode(void);
void free_file_ptr(void);
void sub(stack_t **stack, unsigned int line_number);
int is_digit_(char *str);
void pall(stack_t **stack, unsigned int line_number);
int count_stacks(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void handle_hash(void);

void _div(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H */
