#include "monty.h"

/**
 * push_into - pushes an element onto the stack or queue
 * @head: pointer to the stack or queue head
 * @counter: line_number
 * @bus: bus_t struct with relevant information
 */
void push_into(stack_t **head, unsigned int counter, bus_t *bus)
{
	int naija = 0;
	int i = 0;
	int flag = 0;

	if (!bus->args)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus->monty_file);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	if (bus->args[0] == '-')
		i++;

	for (; bus->args[i] != '\0'; i++)
	{
		if (!isdigit(bus->args[i]))
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus->monty_file);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	naija = atoi(bus->args);

	if (bus->extra == 0)
		add_node(head, naija);
	else
		addqueue(head, naija);
}
