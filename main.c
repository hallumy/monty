#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function
 * @argc: count of arguments fed while running
 * @argv: the arguments themselves
 * Return: 0
 */


int main(int argc, char *argv[])
{
	/* ssize_t read = 1;*/
	char *read;
	/*size_t n;*/
	char *lineptr = NULL, *token, **av;
	FILE *file;
	int x = 0;
	char str_l[100];

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
		token = strtok(lineptr, " ");
		av = input_tokenizer(token);
		if (av == NULL)
		{
			continue;
		}
	x++;
	}
	free(lineptr);
	fclose(file);
	exit(EXIT_SUCCESS);

	return (0);
}

/**
 * input_tokenizer - Separate commands and their arguments
 * @str: Commandline with optional arguments
 * Return: Nothing
 */
char **input_tokenizer(char *str)
{
	int count = 1;
	size_t j = 0;
	char *token = NULL, *ptr = NULL, **argv = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[j])
	{
		if (str[j] != ' ')
			break;
		j++;
	}
	if (j == strlen(str))
	{
		return (argv);
		printf("argv is %s\n", argv[0]);
	}
	else
	{
		token = strtok(ptr, " ");
		while (token)
		{
			token = strtok(NULL, " ");
			count++;
		}
		argv = malloc(sizeof(*argv) * count);
		if (argv == NULL)
		{
			printf("There is an error");
			exit(1);
		}
		token = strtok(str, " ");
		j = 0;
		while (token)
		{
			argv[j] = NULL;
			j++;
			token = strtok(NULL, " ");
		}
		argv[j] = NULL;
		free(ptr);
		return (argv);

}
}


/*
 *
 *
 *
void exec_func(char *op, int ln,
*/
