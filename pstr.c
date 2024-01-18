#include "monty.h"

/**
 * pstr - It prints the string from the top of the stack
 * @stack: The stack of ekements
 * @line_number: The line number of the file to execute
 *
 * AUTHOR - Hammed Yakub
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int count;
	(void) *stack;
	(void) line_number;

	temp = file_ptr->head;
	count = 0;
	if (temp == NULL)
	{
		printf("\n");
	}
	else
	{
		while (temp != NULL)
		{
			if (!(temp->n >= 65 && temp->n <= 90)
					&& !(temp->n >= 97 && temp->n <= 122))
			{
				if (count == 0)
					break;
				printf("\n");
				break;
			}
			else
			{
				printf("%c", temp->n);

				if (temp->next == NULL)
					printf("\n");
			}
			temp = temp->next;
			count++;
		}
	}
}
