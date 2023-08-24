#include "monty.h"

void push_into(stack_t **head, unsigned int counter, bus_t *bus)
{
	int naija = 0;
	int i = 0;
	int flag = 0;

	if (bus->args)
	{
		if (bus->args[0] == '-')
			i++;

		for (; bus->args[i] != '\0'; i++)
		{
			if (bus->args[i] > 57 || bus->args[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus->monty_file);
			freestack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fclose(bus->monty_file);
		free(bus->content);
		freestack(*head);
		exit(EXIT_FAILURE);
	}

	naija = atoi(bus->args);
	if (bus->extra == 0)
		add_node(head, naija);
	/*else
		addqueue(head, naija);*/
}
