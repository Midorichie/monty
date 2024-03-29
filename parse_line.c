#include "monty.h"
/**
 * parse_line - It's in charge of the tokenization of the string entered
 */
void parse_line(void)
{
	int m = 0;
	char *line_copy = NULL, *token = NULL;

	line_copy = malloc(sizeof(char) * (strlen(file_ptr->line) + 1));
	if (line_copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_ptr->line);
	file_ptr->num_tokens = 0;
	token = strtok(line_copy, " \n\t");
	while (token)
	{
		file_ptr->num_tokens += 1;
		token = strtok(NULL, " \n\t");
	}
	file_ptr->tokens = malloc(sizeof(char *) *
			(file_ptr->num_tokens + 1));
	if (file_ptr->tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_file_ptr();
		exit(EXIT_FAILURE);
	}
	strcpy(line_copy, file_ptr->line);
	token = strtok(line_copy, " \n\t");
	while (token)
	{
		file_ptr->tokens[m] = malloc(sizeof(char) *
				(strlen(token) + 1));
		if (file_ptr->tokens[m] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(file_ptr->tokens[m], token);
		token = strtok(NULL, " \n\t");
		m++;
	}
	file_ptr->tokens[m] = NULL;
	free(line_copy);
}
