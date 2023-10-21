#include "monty.h"

/**
 *_rotl - Rotates the stack to the left.
 *@doubly: Double-linked list head
 *@cline: Line number
 *
 *Description:
 *The _rotl function rotates the stack to the left, moving the top element to
 *the bottom. It takes a double-linked list head doubly and the current line
 *number cline as parameters. If the stack is empty or has only one element,
 *it does nothing.
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = *doubly;
	(void) cline;

	if (*doubly == NULL || (*doubly)->next == NULL)
		return;

	while (aux->next != NULL)
	{
		aux = aux->next;
	}

	aux->next = *doubly;
	(*doubly)->prev = aux;
	*doubly = (*doubly)->next;
	(*doubly)->prev = NULL;
	aux->next->next = NULL;
}

/**
 *_rotr - Rotates the stack to the right.
 *@doubly: Double-linked list head
 *@cline: Line number
 *
 *Description:
 *The _rotr function rotates the stack to the right, moving the bottom element
 *to the top. It takes a double-linked list head doubly and the current line
 *number cline as parameters. If the stack is empty or has only one element,
 *it does nothing.
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = *doubly;
	(void) cline;

	if (*doubly == NULL || (*doubly)->next == NULL)
		return;

	while (aux->next != NULL)
	{
		aux = aux->next;
	}

	aux->prev->next = NULL;
	aux->prev = NULL;
	aux->next = *doubly;
	(*doubly)->prev = aux;
	*doubly = aux;
}
