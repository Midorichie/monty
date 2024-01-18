#include "monty.h"

/**
 * push - It prints all the values in the stack from the top
 * @stack: A pointer to the stack structure
 * @line_number: The line number of each line in the file
 */

void push(stack_t **stack, unsigned int line_number)
{
	if (file_ptr->num_tokens <= 1 || !(is_digit_(file_ptr->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose_file();
		free_tokens();
		free_file_ptr();
		exit(EXIT_FAILURE);
	}

	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(file_ptr->tokens[1]);
	if (file_ptr->head != NULL)
	{
		(*stack)->next = file_ptr->head;
		file_ptr->head->prev = *stack;
	}
	file_ptr->head = *stack;
}

/**
 * is_digit_ -  It checks if a string is a digit
 * @str: The string to check
 * Return: Always 0 (Success)
 */

int is_digit_(char *str)
{
	int m = 0;

	while (str[m] != '\0')
	{
		if (m == 0 && str[m] == '-' && str[m + 1])
		{
			m++;
			continue;
		}
		if (str[m] < '0' || str[m] > '9')
		{
			return (0);
		}
		m++;
	}
	return (1);
}

/**
 * free_stack - It helps free all the stacks created
 * @head: A pointer to the head of the node
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

/**
 * free_head - It frees the head pointer
 */

void free_head(void)
{
	if (file_ptr->head)
		free_stack(file_ptr->head);
	file_ptr->head = NULL;
}
