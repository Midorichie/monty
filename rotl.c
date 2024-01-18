#include "monty.h"

/**
 * rotl - It rotates the stack to the top, putting
 * the first element at the rear, leaving the rest
 * the way they are
 *
 * @line_number: The line number of file to execute
 * @stack: The stack of elements
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *current;
	(void) *stack;
	(void) line_number;

	if (count_stacks(file_ptr->head) < 2)
	{
		return;
	}

	temp = file_ptr->head;
	current = temp->next;
	file_ptr->head = current;
	while (current != NULL)
	{
		if (current->next == NULL)
		{
			current->next = temp;
			temp->next = NULL;
			temp->prev = current;
			break;
		}
		current = current->next;
	}
}
