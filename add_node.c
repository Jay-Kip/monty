#include "monty.h"

/**
 * add_node - Adds a new node at the beginning of a stack_t list.
 * @head: Pointer to the head of the stack.
 * @n: The value to store in the new node.
 */

void add_node(stack_t **head, int n)
{
	stack_t *new;
	stack_t *cab;

	cab = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (cab)
	{
		cab->prev = new;
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
