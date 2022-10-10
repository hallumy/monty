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
/*	char *lineptr = NULL;*/
	FILE *file;
	int ln, format = 0;
/*	char str_l[100];*/


/*	res = malloc(sizprintf("Error: Can't open file, %s\n", argv[1]eof(char));*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		printf("Error: Can't open file, %s\n", argv[1]);
	}

	/*printf("while loop\n");*/
	/*res = fgets(str_l, 100, file);*/
	ln = 1;
	while (read > 0)
	{	
		/*res = fgets(str_l, 100, file);*/
		res = NULL;
	 	read = getline(&res, &n, file);
			
		if (read > 0)
		{
			format = input_tokenizer(res, ln, format);
		/*	printf("format is %d, res is %s", format, res);*/
		}
		ln++;
		free(res);
	}
	fclose(file);
return (0);
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
	/**char *res;*/

	/*printf("start of tokenizer\n");*/
	if (str == NULL)
        {
                printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
        }
        opcode = strtok(str, "\n ");
	/*printf("opcode is %s ", opcode);*/
	/*opcode = strtok(res, " ");*/
	/* Dealing with blank lines */
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, "\n ");
	/*printf("value is \n");*/

	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);

	exec_func(opcode, value, line_number, format);
	/*printf("format is this from okenizer, %d\n", format);*/
	return (format);
}
