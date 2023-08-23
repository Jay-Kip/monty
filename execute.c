#include "monty.h"

/**
 * execute - executes the opcode
 * @content: line content
 * @stack: pointer to the stack head
 * @counter: line counter
 * @file: pointer to monty file
 *
 * Return: 0 on success
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file, bus_t *bus)
{
	instruction_t opst[] = {
		{"pall", print_stack_values},
		{"div", divide_top_two},
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus->arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter, bus);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
