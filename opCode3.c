#include "monty.h"

/**
 *_rotl - Rotates the stack to the top
 *@stack: A pointer to the stack
 *@line_number: The line number in the Monty bytecode file
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp1 = *stack;
	temp2 = (*stack)->next;

	while (temp2->next)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	temp1->next = NULL;
	temp2->prev = NULL;
	temp2->next = *stack;
	(*stack)->prev = temp2;
	*stack = temp2;

	(void) line_number;
}

/**
 *_rotr - Rotates the stack to the bottom
 *@stack: A pointer to the stack
 *@line_number: The line number in the Monty bytecode file
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;

	while (temp->next)
		temp = temp->next;

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;

	(void) line_number;
}
