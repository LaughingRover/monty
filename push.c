#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: number of commands
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int value;
	stack_t *new_node = NULL;

	/* Tokenize the line to extract the push argument */
	argument = strtok(NULL, " \t\n");

	/* Check if the argument exists */
	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert argument to an integer using atoi */
	value = atoi(argument);

	/* Create a new stack node */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* Add the new node to the stack */
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

