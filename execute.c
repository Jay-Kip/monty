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
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"pall", print_values_in_stack},
		{"push", push_into},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus.args = strtok(NULL, " \n\t");


	while (opst[i].opcode && op)
	{

		/*printf("Comparing opcode: %s with %s\n", op, opst[i].opcode);*/

		if (strcmp(op, opst[i].opcode) == 0)
		{

			/*printf("Error 4 is here\n");*/
			opst[i].f(stack, counter, &bus);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		/*free_stack(*stack);*/
		exit(EXIT_FAILURE);
	}

	return (1);
}
