#include "monty.h"

/**
 * mul - It multiplies the top element with the second
 * top element of the stack
 * #stack: stack of elements
 *
 * AUTHOR - Hammed Yakub
 *
 * @line_number: line number of file to execute
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	num1 = temp->n;
	temp = temp->next;
	num2 = temp->n;
	temp->n = num1 * num2;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}
