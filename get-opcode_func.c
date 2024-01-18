#include "monty.h"

/**
 * get_opcode_func - it handles the opcode function that's passed
 * desc: checks if the opcode string is valid
 *
 * AUTHOR - Hammed Yakub
 */

void get_opcode_func(void)
{
	size_t m;

	static instruction_t opcodes[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"swap", swap},
		{"nop", nop},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (file_ptr->num_tokens == 0)
		return;
	if (file_ptr->tokens[0][0] == '#')
	{
		handle_hash();
		return;
	}
	for (m = 0; opcodes[m].opcode != NULL; m++)
	{
		if (strcmp(opcodes[m].opcode, file_ptr->tokens[0]) == 0)
		{
			file_ptr->opcode_instruction->opcode = opcodes[m].opcode;
			file_ptr->opcode_instruction->f = opcodes[m].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * invalid_instruction - handles the error message
 *
 * AUTHOR - Hammed Yakub
 *
 * desc: To free invalid functions
 */

void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			file_ptr->line_number, file_ptr->tokens[0]);
	fclose_file();
	free_tokens();
	free_file_ptr();
	exit(EXIT_FAILURE);
}

/**
 * fclose_file - closes the file
 */

void fclose_file(void)
{
	if (file_ptr->file != NULL)
	{
		fclose(file_ptr->file);
	}
	file_ptr->file = NULL;
}

/**
 * free_tokens - frees all the tokenized string
 */

void free_tokens(void)
{
	int m = 0;

	if (file_ptr->tokens == NULL)
		return;
	while (file_ptr->tokens[m])
	{
		free(file_ptr->tokens[m]);
		m++;
	}
	free(file_ptr->tokens);
	file_ptr->tokens = NULL;
}

/**
 * free_file_ptr - free the file_ptr, the pointer to the struct
 */

void free_file_ptr(void)
{
	if (file_ptr == NULL)
		return;
	if (file_ptr->opcode_instruction)
	{
		free(file_ptr->opcode_instruction);
		file_ptr->opcode_instruction = NULL;
	}
	free_head();
	if (file_ptr->line)
	{
		free(file_ptr->line);
		file_ptr->line = NULL;
	}
	free(file_ptr);
}
