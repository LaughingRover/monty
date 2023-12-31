#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: doubly linked list representation of a stack (or queue)
 * @line_number: number of commands
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number); /*Remove the top element*/
}

