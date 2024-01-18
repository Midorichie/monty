#include "monty.h"

/**
 * pop - It prints all the values in the stack from top
 * @stack: A pointer to the stack structure
 * @line_number: The line number of each line in the file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	file_ptr->head = temp->next;
	if (file_ptr->head != NULL)
	{
		file_ptr->head->prev = NULL;
	}
	free(temp);
}
