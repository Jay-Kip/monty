#include "monty.h"


void print_values_in_stack(stack_t **head, unsigned int counter, bus_t *bus)
{
	stack_t *head_of_stack;
	(void)counter; /*Void shows it wont be used*/
	(void)bus;

	head_of_stack = *head;

	if (head_of_stack == NULL)
		return;

	while (head_of_stack)
	{
		printf("%d\n", head_of_stack->n); /*Prints value int the current position*/
		head_of_stack = head_of_stack->next;
	}
}
