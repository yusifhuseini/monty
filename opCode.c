#include "monty.h"

/**
 *_push - Pushes an element onto the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *Return: No return value.
 */
void _push(stack_t **doubly, unsigned int cline)
{
	int n;

	if (!gloVar.arg || !is_integer(gloVar.arg))
	{
		dprintf(2, "L%u: usage: push integer\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	n = atoi(gloVar.arg);

	if (gloVar.lifo == 1)
		addNode(doubly, n, 0);
	else
		addNodeEnd(doubly, n);
}

/**
 *_pall - Prints all values on the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: Line number (unused).
 *Return: No return value.
 */
void _pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void) cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 *_pint - Prints the value at the top of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *Return: No return value.
 */
void _pint(stack_t **doubly, unsigned int cline)
{
	(void) cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 *_pop - Removes the top element of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *Return: No return value.
 */
void _pop(stack_t **doubly, unsigned int cline)
{
	if (*doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	popNode(doubly);
}

/**
 *_swap - Swaps the top two elements of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *Return: No return value.
 */
void _swap(stack_t **doubly, unsigned int cline)
{
	if (doubly == NULL || *doubly == NULL || (*doubly)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	swapNodes(doubly);
}
