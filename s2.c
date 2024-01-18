nclude "monty.h"

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *new_nod;

	new_nod = malloc(sizeof(stack_t));
	if (new_nod == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_nod);
		exit(EXIT_FAILURE);
	}
	new_nod->next = NULL;
	new_nod->prev = NULL;
	new_nod->n = n;
	return (new_nod);
}
/**
 * pall - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void pall(stack_t **node, __attribute__((unused))unsigned int line)
{
	struct stack_s *tmp;

	tmp = *node;

	check(node);
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}


/**
 * check - Adds a node to the queue.
 * @node: Pointer to the new node.
 */
void check(stack_t **node)
{
	if (node == NULL || *node == NULL)
		exit(EXIT_FAILURE);
}


/**
 * pint - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void pint(stack_t **node, unsigned int line)
{
	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_node();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*node)->n);
}


/**
 * add - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void add(stack_t **node, unsigned int line)
{
	int sum = 0;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_node();
		exit(EXIT_FAILURE);
	}
	sum = ((*node)->n) + ((*node)->next->n);
	*node = (*node)->next;
	(*node)->n = sum;
	free((*node)->prev);
	(*node)->prev = NULL;
}
