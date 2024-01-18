#include "monty.h"

/**
 * pint - It prints the value at the top of the stack
 * @stack: The stack of elements
 * @line_number: The line number of each line in the file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) *stack;

	current = file_ptr->head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
