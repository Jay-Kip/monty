#define _GNU_SOURCE
#include "monty.h"
<<<<<<< HEAD
=======
bus_t bus = {NULL, NULL, NULL, 0};
>>>>>>> 266d2a4f31f15bc9ceb550861c20ed9ff53b9d22

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	bus_t bus = {NULL, NULL, NULL, 0};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	bus.monty_file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		content = NULL;
		read = getline(&content, &size, bus.monty_file);
		bus.content = content;
		counter++;
		if (read > 0)
		{
			execute(content, &stack, counter, file, &bus);
		}
		free(content);
	}
	/*free_stack(stack);*/
	fclose(file);
return (0);
}
