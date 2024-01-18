#include "monty.h"

/**
 * sub - It subtracts the first top element of a stack
 * from the second top element
 *
 * @stack: The stack of elements
 * @line_number: The line number of the filw to execute
 *
 * AUTHOR - Hammed Yakub
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	num1 = temp->n;
	temp = temp->next;
	num2 = temp->n;
	temp->n = num2 - num1;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}
