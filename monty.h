#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
* struct bus_s - variables -args, file, line content
* @args: value
* @monty_file: pointer to monty file
* @content: contents present in each line
* @extra: flag change stack <-> queue
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *args;
	FILE *monty_file;
	char *content;
	int extra;
} bus_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, bus_t *bus);
} instruction_t;

extern bus_t bus;


int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void print_values_in_stack(stack_t **head, unsigned int counter, bus_t *bus);
void push_into(stack_t **head, unsigned int counter, bus_t *bus);
void add_node(stack_t **head, int n);
void freestack(stack_t *head);
void print_file_name(FILE *file);
void addqueue(stack_t **head, int n);
void pint(stack_t **head, unsigned int counter);





#endif
