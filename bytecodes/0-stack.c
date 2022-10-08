#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack
 * @new node: Pointer to the new node
 * @ln: Integer representing the line number of the opcodes
 */
void add_to_stack(stack_t **newP, unsigned int ln __attribute__((unused)))
{
	stack_t *temp;

	if (newP == NULL || *newP == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newP;
		return;
	}
	temp = head;
	head = *newP;
	head->next = temp;
	temp->prev = head;
}
/**
 * print_all - Print a node of the stack
 * @stack: Pointer to pointer to the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		print("%d\n", temp->n);
		temp = temp->next;
	}
}
