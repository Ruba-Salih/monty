#include "monty.h"
struct stack_s *top = NULL;

/**
 * main - Creates a node.
 * @argc: Number to go inside the node.
 * @argv: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_node();
		exit(EXIT_FAILURE);
	}
	open_(argv[1]);
	free_node();
	return (0);
}

/**
 * open_ - find the appropriate function for the opcode
 * @file: opcode
 */
void open_(char *file)
{
	FILE *fp;
	unsigned int line_number;
	char *buffer = NULL;
	size_t len = 0;
	int flag = 0;

	fp = fopen(file, "r");
	if (file == NULL || fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		free_node();
		exit(EXIT_FAILURE);
	}
	for (line_number = 1; getline(&buffer, &len, fp) != EOF; line_number++)
	{
		flag = tok(buffer, flag, line_number);
	}
	fclose(fp);
	free(buffer);
}

/**
 * tok - find the appropriate function for the opcode
 * @buffer: opcode
 * @line_number: argument of opcode
 * @flag:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
int tok(char *buffer, int flag, unsigned int line_number)
{
	char *opcode = NULL, *val = NULL;

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	opcode = strtok(buffer, " \n");
	val = strtok(NULL, " \n");

	if (opcode == NULL)
		return (flag);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	fun_(opcode, val, flag, line_number);
	return (flag);
}

/**
 * fun_ - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @line_number: argument of opcode
 * @flag:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void fun_(char *opcode, char *val, int flag, unsigned int line_number)
{
	int i;
	int j;

	instruction_t fun_arr[] = {
		{"push", push_},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop_},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (j = 1, i = 0; fun_arr[i].f != NULL; i++)
	{
		if (strcmp(opcode, fun_arr[i].opcode) == 0)
		{
			find_fun(fun_arr[i].f, opcode, val, flag, line_number);
			j = 0;
		}
	}
	if (j == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_node();
		exit(EXIT_FAILURE);
	}
}

/**
 * find_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @val: string representing a numeric value.
 * @line: string representing a numeric value.
 * @flag: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void find_fun(fun func, char *opcode, char *val, int flag, unsigned int line)
{
	stack_t *node;
	int min;
	int i;

	min = 1;
	if (strcmp(opcode, "push") == 0)
	{
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_node();
			exit(EXIT_FAILURE);
		}
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			min = -1;
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				free_node();
				exit(EXIT_FAILURE);
			}
		}
		i = (atoi(val)) * min;
		node = create_node(i);
		if (flag == 0)
			func(&node, line);
		if (flag == 1)
			add_queue(&node, line);
	}
	else
		func(&top, line);
}


