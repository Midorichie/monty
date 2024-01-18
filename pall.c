#include "monty.h"

/**
 * pall - prints all the values in the stack from the
 * top of the stack
 * @stack: A pointer to the stack structure
 * @line_number: The line number of each line in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) stack;
	(void) line_number;

	current = file_ptr->head;

	if (current == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
