#include "monty.h"

/**
 * push_ - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void push_(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	struct stack_s *tmp;

	check(new_node);

	if (top == NULL)
	{
		top = *new_node;
		return;
	}

	tmp = top;
	top = *new_node;
	top->next = tmp;
	tmp->prev = top;
}

/**
 * free_node - Frees nodes in the stack.
 */
void free_node(void)
{
	stack_t *tmp;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
}


/**
 * pop_ - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void pop_(stack_t **node, unsigned int line)
{
	struct stack_s *tmp;

	if (node == NULL || *node == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_node();
		exit(EXIT_FAILURE);
	}

	tmp = *node;
	*node = (*node)->next;

	if (*node != NULL)
		(*node)->prev = NULL;

	free(tmp);
}


/**
 * swap - Adds a node to the stack.
 * @node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void swap(stack_t **node, unsigned int line)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_node();
		exit(EXIT_FAILURE);
	}

	tmp = (*node)->next;
	(*node)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *node;

	tmp->next = *node;
	(*node)->prev = tmp;
	tmp->prev = NULL;
	*node = tmp;
}

/**
 * add_queue - Adds a node to the queue.
 * @node: Pointer to the new node.
 * @line: Pointer to the new node.
 */
void add_queue(stack_t **node,  __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	check(node);
	if (top == NULL)
	{
		top = *node;
		return;
	}
	tmp = top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *node;
	(*node)->prev = tmp;
}

