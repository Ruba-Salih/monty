#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **node, unsigned int line_number)
{
	int as;

	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	as = (*node)->n;
	if (as < 0 || as > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", as);
}

/**
 * print_str - Prints a string.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **node, __attribute__((unused))unsigned int ln)
{
	int as;
	struct stack_s *tmp;

	if (node == NULL || *node == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}

	tmp = *node;
	while (tmp != NULL)
	{
		as = tmp->n;
		if (as <= 0 || as > 127)
			break;
		fprintf(stdout, "%c", as);
		tmp = tmp->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **node, __attribute__((unused))unsigned int line)
{
	struct stack_s *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;
	*node = (*node)->next;
	(*node)->prev->next = NULL;
	(*node)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **node, __attribute__((unused))unsigned int line)
{
	struct stack_s *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *node;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*node)->prev = tmp;
	(*node) = tmp;
}


