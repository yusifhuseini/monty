#include "monty.h"

/**
 *_mod - Computes the remainder of the division of the second element
 *       by the top element of the stack.
 *@doubly: A pointer to the head of the linked list.
 *@cline: The current line number.
 *
 *Return: No return value.
 *
 *Description: The result is stored in the second value node from the top,
 *             and the top value is removed.
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	int stack_length = 0;

	aux = *doubly;

	/*Calculate the length of the stack */
	while (aux != NULL)
	{
		stack_length++;
		aux = aux->next;
	}

	if (stack_length < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	/*Perform the modulo operation */
	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;

	/*Remove the top element */
	_pop(doubly, cline);
}

/**
 *_pstr - Prints the string of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The current line number.
 *
 *Return: No return value.
 */
void _pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void) cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}

/**
 *_pchar - Prints the character value of the first element.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The current line number.
 *
 *Return: No return value.
 */
void _pchar(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*doubly)->n);
}
