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
		{"push", push_into},
		{"pall", print_values_in_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *input;
	char *op;

	input =  strtok(content, " \n\t"); /*This line tokenizes input*/
	if (input && input[0] == '#')
		return (0);

	bus.args = strtok(NULL, " \n\t");


	while (opst[i].opcode)
	{
		op = strtok(NULL, " \n\t");
    		if (!op)
        	break;

		printf("Comparing opcode: %s with %s\n", input, opst[i].opcode);

		if (strcmp(input, opst[i].opcode) == 0)
		{

			printf("Error 4 is here\n");
			opst[i].f(stack, counter, &bus); /*The .f points to the function at opst[i]*/
			return (0);
			printf("Error 5 is here\n");

			
		}
		i++;
	}

	if (input && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, input);
		fclose(file);
		free(content);
		/*free_stack(*stack);*/
		exit(EXIT_FAILURE);
	}

	return (1);
}
