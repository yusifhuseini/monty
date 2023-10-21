#include "monty.h"

/**
 *_add - Adds the top two values of a stack_t linked list.
 *@stack: Pointer to the head of the linked list
 *@line_number: Line number
 *
 *Description: The result is stored in the second value node
 *from the top, and the top value is removed.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *current = *stack;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n += (*stack)->n;
	_pop(stack, line_number);
}

/**
 *_nop - Does nothing.
 *@stack: Pointer to the head of the linked list
 *@line_number: Line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 *_sub - Subtracts the top value from the second value on the stack.
 *@stack: Pointer to the head of the linked list
 *@line_number: Line number
 *
 *Description: The result is stored in the second value node
 *from the top, and the top value is removed.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *current = *stack;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n -= (*stack)->n;
	_pop(stack, line_number);
}

/**
 *_div - Divides the second value from the top by the top value.
 *@stack: Pointer to the head of the linked list
 *@line_number: Line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *current = *stack;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n /= (*stack)->n;
	_pop(stack, line_number);
}

/**
 *_mul - Multiplies the second value from the top by the top value.
 *@stack: Pointer to the head of the linked list
 *@line_number: Line number
 *
 *Description: The result is stored in the second value node
 *from the top, and the top value is removed.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *current = *stack;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	if (count < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	current = (*stack)->next;
	current->n *= (*stack)->n;
	_pop(stack, line_number);
}
