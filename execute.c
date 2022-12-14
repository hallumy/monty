#include "monty.h"
#include <ctype.h>
/**
 * exec_func - Finds and executes the appropite function to run
 * the opcode instructions.
 * @opcode: The operation code, It could be push, pint, ...
 * @value: The possible value for the operation.
 * @ln: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void exec_func(char *opcode, char *value, int ln, int format)
{
	int index;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_all},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	/*Iterate through list to find the right function*/
	for (flag = 1, index = 0; func_list[index].opcode != NULL; index++)
	{
		/*When 0 found the right opcode*/
		if (strcmp(opcode, func_list[index].opcode) == 0)
		{
			call_fun(func_list[index].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		exit(EXIT_FAILURE);
	}
}
/**
 * call_fun - Calls the required function.
 * @f: Pointer to the function that is about to be called.
 * @opcode: string representing the opcode.
 * @value: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func f, char *opcode, char *value, int ln, int format)
{
	stack_t *node;
	int flag;
	int index;

	flag = 1;
	if (strcmp(opcode, "push") == 0)
	{
		/*Checks if the number is negative and moves the val ptr*/
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		/*val is not a digit is the return value is 0*/
		if (value == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		for (index = 0; value[index] != '\0'; index++)
		{
			if (isdigit(value[index]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			f(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		f(&head, ln);
}

/**
 * create_node - Creates a node
 * @n: Data to go in the node
 * Return: Pointer to node on sucess. Otherwise NULL
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		fprintf(stderr, "Error: malloc failed\n");
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * free_nodes - Frees nodes in the stack
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
