#include "monty.h"

/*
 * print_stack_values - prints the values of the stack.
 * @stack: stack head
 * @line_number: not used
 * Return: no return
 */
void print_stack_values(stack_t **stack, unsigned int line_number, bus_t *bus)
{
	stack_t *current;
	(void)line_number;
	(void)bus;

	current = *stack;
	if (current == NULL)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
