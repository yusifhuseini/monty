#include "monty.h"

/**
 *addNode - add a node to a doubly linked list at the specified position.
 *@head: Pointer to the head of the linked list.
 *@n: Data to store in the new node.
 *@atEnd: If 1, add the node at the end; if 0, add at the beginning.
 *Return: Pointer to the newly added node.
 */
stack_t *addNode(stack_t **head, const int n, int atEnd)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		freeGloVar();
		exit(EXIT_FAILURE);
	}

	temp->n = n;
	if (*head == NULL)
	{
		temp->next = NULL;
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		if (atEnd)
		{
			stack_t *aux = *head;

			while (aux->next)
				aux = aux->next;
			temp->next = aux->next;
			temp->prev = aux;
			aux->next = temp;
		}
		else
		{ (*head)->prev = temp;
			temp->next = *head;
			temp->prev = NULL;
			*head = temp;
		}
	}
	return (temp);
}

/**
 *addNodeEnd - add a node at the end of the doubly linked list.
 *@head: Pointer to the head of the linked list.
 *@n: Data to store.
 *Return: Pointer to the newly added node.
 */
stack_t *addNodeEnd(stack_t **head, const int n)
{
	return (addNode(head, n, 1));
}

/**
 *addNodeBegin - add a node at the beginning of the doubly linked list.
 *@head: Pointer to the head of the linked list.
 *@n: Data to store.
 *Return: Pointer to the newly added node.
 */
stack_t *addNodeBegin(stack_t **head, const int n)
{
	return (addNode(head, n, 0));
}

/**
 *freeDoublyLinkedList - frees the doubly linked list.
 *@head: Pointer to the head of the list.
 *Return: No return.
 */
void freeDoublyLinkedList(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
