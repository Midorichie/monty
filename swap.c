#include "monty.h"

/**
 * swap - It swaps the values of the top two elements
 * on the stack, beginning from the top
 *
 * @stack: Apointer to the stack structure
 * @line_number: The line number of each line in the file
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int temp_value;

	(void) *stack;
	if (file_ptr->head == NULL || file_ptr->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't wswap, stack too short\n", line_number);
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	temp = file_ptr->head;
	temp_value = temp->n;
	temp->n = temp->next->n;
	temp->next->n = temp_value;
}
