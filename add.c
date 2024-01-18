#include "monty.h"

/**
 * count_stacks - count number of elements in a stack
 * @stack: stack of elements
 *
 * AUTHOR - Hammed Yakub
 *
 * Return: number of elements in a stack
 */

int count_stacks(stack_t *stack)
{
	stack_t *temp = stack;
	int m;

	if (temp == NULL)
		return (0);

	m = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		m++;
	}
	return (m);
}

/**
 * add - adds the top two elements of the stack
 * @stack: stack of elements
 * @line_number: line number of file to execute
 *
 * AUTHOR - Hammed Yakub
 * Return: vOID
 */

void add(stack_t **stack, unsigned int line_number)
{
	int num1, num2;
	stack_t *temp;
	(void) *stack;

	temp = file_ptr->head;
	if (temp == NULL || count_stacks(file_ptr->head) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	num1 = temp->n;
	temp = temp->next;
	num2 = temp->n;
	temp->n = num1 + num2;

	free(file_ptr->head);
	temp->prev = NULL;
	file_ptr->head = temp;
}

