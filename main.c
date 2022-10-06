#include "monty.h"
int main(int argc, char* argv[])
{
	ssize_t read = 0;
	size_t n = 0;
	char *lineptr = NULL, token, **av;
	FILE *file;

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
	while (read > 0)
	{
		read = getline(&lineptr, &n, stdin);
		if (read == -1)
			break;
		token = strtok(lineptr, " ");
                av = input_tokenizer(token);
                if (av == NULL)
                {
                        continue;
                }
	}
	return (0);
}

/**
 * input_tokenizer - Separate commands and their arguments
 * @str: Commandline with optional arguments
 * @delim: Character used to separate the words
 * Return: Nothing
 */
char **input_tokenizer(char *str)
{
	int count = 1, j = 0;
	char *token = NULL;
	char *ptr = NULL;
	char **argv = NULL;

	if (str == NULL)
        {
                return NULL;
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
		ptr = strdup(str);
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
                        argv[j] = strdup(token);
                        j++;
                        token = strtok(NULL, " ");
                }
                argv[j] = NULL;
                free(ptr);
                return (argv);

        }
}


/**
 *
 * 
 *
void exec_func(char *op, int ln,*/
