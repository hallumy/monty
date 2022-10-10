#define _GNU_SOURCE
#include "monty.h"
stack_t *head = NULL;
/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array containing the  arguments
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
	ssize_t read = 1;
	char *res;
	size_t n = 0;
	FILE *file;
	int ln, format = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error:Can't open file%s\n", argv[1]);
	}

	ln = 1;
	while (read > 0)
	{
		res = NULL;
		read = getline(&res, &n, file);
		if (read > 0)
		{
			format = input_tokenizer(res, ln, format);
		}
		ln++;
		free(res);
	}
	free_nodes();
	fclose(file);
return (0);
}

/**
 * input_tokenizer - Separate commands and their arguments
 * @str: Commandline with optional arguments
 * @line_number: Line number of opcode
 * @format:Format specifier. If node is 0 stack, if node is 1 queue
 * Return: Nothing
 */
int input_tokenizer(char *str, int line_number, int format)
{
	char *opcode;
	char *value;

	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(str, "\n ");
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, "\n ");

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	exec_func(opcode, value, line_number, format);
	return (format);
}
