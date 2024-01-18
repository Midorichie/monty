#include "monty.h"

/**
 * nop - does nothing
 * @stack: A pointer to the stack structure
 * @line_number: The line number of each line in the file
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
