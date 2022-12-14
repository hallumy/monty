#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>



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
extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
int main(int argc, char **argv);
int input_tokenizer(char *str, int line_number, int format);
void exec_func(char *opcode, char *value, int ln, int format);
void call_fun(op_func f, char *opcode, char *value, int ln, int format);
int input_tokenizer(char *str, int line_number, int format);
void add_to_stack(stack_t **newP, unsigned int ln);
void print_all(stack_t **stack, unsigned int line_number);
stack_t *create_node(int d);
void add_to_queue(stack_t **newP, unsigned int line_number);
void free_nodes();
#endif
