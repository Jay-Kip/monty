#include "monty.h"

void addqueue(stack_t **head, int n)
{
	stack_t *new;
	stack_t *cab;

	cab = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
		printf("Error\n");

	new->n = n;
	new->next = NULL;

	if (cab)
	{
		while (cab->next)
			cab = cab->next;
	}

	if (!cab)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		cab->next = new;
		new->prev = cab;
	}
}
