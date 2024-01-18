#include "monty.h"

/**
 * rotr - It rotates the stack to the bottom,
 * with thr last element becoming the first, and
 * the rest intact
 *
 * @stack: The stack of elements
 * @line_number: The line number of the file to execute
 *
 * Return: Void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) *stack;
	(void) line_number;

	temp = file_ptr->head;
	if (count_stacks(file_ptr->head) < 2)
	{
		return;
	}

	while (temp != NULL)
	{
		if (temp->next == NULL)
		{
			current = temp;
			break;
		}
		temp = temp->next;
	}
	current->prev->next = NULL;
	current->next = file_ptr->head;
	current->prev = NULL;
	file_ptr->head = current;
}
