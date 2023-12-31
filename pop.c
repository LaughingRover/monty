#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: number of commands
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

