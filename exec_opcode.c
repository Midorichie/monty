#include "monty.h"

/**
 * execute_opcode - handles the execution once a valid command
 * is passed
 * AUTHOR - Hammed Yakub
 */

void execute_opcode(void)
{
	stack_t *stack = NULL;

	if (file_ptr->opcode_instruction->f)
	{
		file_ptr->opcode_instruction->f(&stack,
				file_ptr->line_number);
	}
	else
		invalid_instruction();
}
