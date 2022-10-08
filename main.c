#include "monty.h"
/*stack_t *head = NULL;*/
/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array containing the  arguments
 * Return: 0 Always (success)
 */
int main(int argc, char **argv)
{
	ssize_t read = 0;
	size_t n = 0;
	char *lineptr = NULL, *token;
	FILE *file;
	int ln, format = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		printf("Error: Can't open file, %s\n", argv[1]);
	}
	while (read != NULL)
	{
		/* read = getline(&lineptr, &n, file);*/
		read = fgets(str_l, 100, file);
		if (read == NULL)
			break;
                format = input_tokenizer(token, ln, format);
	}
	free(lineptr);
}

/**
 * input_tokenizer - Separate commands and their arguments
 * @str: Commandline with optional arguments
 * Return: Nothing
 */
int input_tokenizer(char *str, int line_number, int format)
{
	char *opcode;
	char *value;

	if (str == NULL)
        {
                printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
        }
        opcode = strtok(str, "\n");
	/* Dealing with blank lines */
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, "\n");

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);
	
	exec_func(opcode, value, line_number, format);
	return (format);
}
