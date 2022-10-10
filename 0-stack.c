#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack
 * @newP: Pointer to the new node
 * @ln: Integer representing the line number of the opcodes
 */
void add_to_stack(stack_t **newP, __attribute__((unused)) unsigned int ln)
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
 * @stack: Pointer to pointer toigned int line_number the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */
void print_all(stack_t **stack, __attribute__((unused))
		unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	/*	return;*/
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * add_to_queue - Adds a node to the queue
 * @newP: Pointer to the new node
 * @line_number: Integer representing the line number of the opcodes
 */
void add_to_queue(stack_t **newP, __attribute__((unused))
		unsigned int line_number)
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

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *newP;
	(*newP)->prev = temp;
}
