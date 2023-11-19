#include "monty.h"

instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop}
};

/**
 * main - program entry point
 * @argc: argument counts
 * @argv: argument variable
 *
 * Return: always 0 (Success)
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	unsigned int line_number = 1;

	char *line = NULL;
	size_t len = 0;
	int read;

	FILE *file;
	int i = 0;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, file)) != -1)
	{
		/* Extract the opcode (first word) from the line*/
		char *token = strtok(line, " \t\n");

		if (token != NULL)
		{
			/*perfom a search on the array structure*/
			for (; i < (int)sizeof(ops) / (int)sizeof(ops[0]); i++)
			{
				/*if op is found in the array invoke func*/
				if (strcmp(token, ops[i].opcode) == 0)
				{
					ops[i].f(&stack, line_number);
					break;
				}
			}
		}
		line_number++;
	}
	free(line), fclose(file), exit(EXIT_SUCCESS);
	return (0);
}
