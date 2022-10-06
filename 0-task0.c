#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

	if (argc <= 1)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	int fd = open(argv[1], O_RDONLY | O_CREAT);

	else
	{
		if (fd == -1)
		{
			printf("Error: Can't open file, %s\n", argv[1]);
		}
	}
	return (0);
}
