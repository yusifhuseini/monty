#include "monty.h"

/**
 *is_integer - Checks if a string represents an integer.
 *
 *@str: The string to check.
 *Return: 1 if it's an integer, 0 otherwise.
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0); /*Not an integer. */
	}

	if (*str == '-')
	{
		str++; /*Skip the negative sign if present. */
	}

	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0); /*Not an integer. */
		}

		str++;
	}

	return (1); /*It's an integer. */
}

/**
 *popNode - Removes the top element of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *Return: No return value.
 */
void popNode(stack_t **doubly)
{
	stack_t *temp;

	if (*doubly == NULL)
	{
		fprintf(stderr, "Error: Can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	temp = *doubly;
	*doubly = (*doubly)->next;
	free(temp);
}

/**
 *swapNodes - Swaps the top two elements of the stack.
 *
 *@doubly: A pointer to the head of the linked list.
 *Return: No return value.
 */
void swapNodes(stack_t **doubly)
{
	stack_t *first;
	stack_t *second;

	if (*doubly == NULL || (*doubly)->next == NULL)
	{
		fprintf(stderr, "Error: Can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}

	first = *doubly;
	second = first->next;

	first->next = second->next;
	second->next = first;
	first->prev = second;
	if (first->next)
	{
		first->next->prev = first;
	}

	second->prev = NULL;
	*doubly = second;
}
