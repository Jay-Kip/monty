#include "monty.h"

void freestack(stack_t *head)
{
	stack_t *cab;

	cab = head;

	while (head)
	{
		cab = head->next;
		free(head);
		head = cab;
	}
}
