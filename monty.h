#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

extern struct stack_s *top;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef void (*fun)(stack_t **, unsigned int);


void open_(char *file);
int tok(char *buffer, int flag, unsigned int line_number);
void find_fun(fun func, char *opcode, char *val, int flag, unsigned int line);
void fun_(char *opcode, char *val, int flag, unsigned int line_number);
stack_t *create_node(int n);
void free_node(void);
void check(stack_t **node);
void add_queue(stack_t **node, unsigned int line);
void push_(stack_t **new_node, __attribute__((unused))unsigned int line);
void pall(stack_t **node, __attribute__((unused))unsigned int line);
void pop_(stack_t **node, unsigned int line);
void swap(stack_t **node, unsigned int line);
void pint(stack_t **node, unsigned int line);
void add(stack_t **node, unsigned int line);
void mod(stack_t **node, unsigned int line_number);
void div_(stack_t **node, unsigned int line_number);
void sub(stack_t **node, unsigned int line_number);
void nop(stack_t **node, unsigned int line_number);
void mul(stack_t **node, unsigned int line_number);
void print_char(stack_t **node, unsigned int line_number);
void print_str(stack_t **node, __attribute__((unused))unsigned int line);
void rotl(stack_t **node, __attribute__((unused))unsigned int line);
void rotr(stack_t **node, __attribute__((unused))unsigned int line);

#endif
