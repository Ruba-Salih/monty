nclude "monty.h"

/**
 * nop - Does nothing.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **node, unsigned int line_number)
{
	(void)node;
	(void)line_number;
}

/**
 * sub - Adds the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub(stack_t **node, unsigned int line_number)
{
	int sum;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	sum = (*node)->n - (*node)->prev->n;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * div_ - Adds the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_(stack_t **node, unsigned int line_number)
{
	int sum;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*node) = (*node)->next;
	sum = (*node)->n / (*node)->prev->n;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}



/**
 * mod - Adds the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod(stack_t **node, unsigned int line_number)
{
	int sum;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}


	if ((*node)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	sum = (*node)->n % (*node)->prev->n;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}

/**
 * mul - Adds the top two elements of the stack.
 * @node: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul(stack_t **node, unsigned int line_number)
{
	int sum;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_node();
		exit(EXIT_FAILURE);
	}

	(*node) = (*node)->next;
	sum = (*node)->n * (*node)->prev->n;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}
