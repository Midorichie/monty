#include "monty.h"

/**
 * _div - divides second top element of the stack
 * by the top element of the stack
 * @stack: stack of the elements
 * @line_number: line number of file to execute
 *
 * AUTHOR - Hammed Yakub
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	num1 = temp->n;
	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	temp = temp->next;
	num2 = temp->n;
	temp->n = num2 / num1;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}
