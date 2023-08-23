#include "monty.h"

/**
 * divide_top_two - divides the top two elements of the stack.
 * @stack: pointer to the stack head
 * @line_number: line number
 */
void divide_top_two(stack_t **stack, unsigned int line_number, bus_t *bus)
{
	stack_t *current;
	int stack_size = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "l%d: cant div, stack too short\n", line_number);
		fclose(bus->file);
		free(bus->content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "l%d: division by zero\n", line_number);
		fclose(bus->file);
		free(bus->content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
