#include "monty.h"

/**
 * add_to_stack - Adds a node to the stack
 * @new node: Pointer to the new node
 * @ln: Integer representing the line number of the opcodes
 */
void add_to_stack(stack_t **newP, __attribute__((unused)) unsigned int ln)
{
	stack_t *temp;
	printf("add to stack\n");

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
	printf("end of stack\n");
}
/**
 * print_all - Print a node of the stack
 * @stack: Pointer to pointer toigned int line_number the top node of the stack
 * @line_number: Integer representing the line number of the opcode
 */
void print_all(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp = NULL;
	printf("print_all\n");

	if (stack == NULL)
		/**exit(EXIT_FAILURE)*/
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


void add_to_queue(stack_t **newP, __attribute__((unused))unsigned int line_number)
{
	stack_t *temp;
	printf("Add to queue 1\n");

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
		printf("while loop add to queue\n");
	}
	temp->next = *newP;
	(*newP)->prev = temp;
}









