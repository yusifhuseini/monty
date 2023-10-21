#include "monty.h"

/**
 *_queue - Set the format of data to queue (FIFO/LILO).
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *
 *Description: This function is used to set the format of data to queue.
 *In this format, elements are removed from the front
 *(FIFO - First In, First Out).
 */
void _queue(stack_t **doubly, unsigned int cline)
{
	(void) doubly;
	(void) cline;

	gloVar.lifo = 0;
}

/**
 *_stack - Set the format of data to stack (LIFO/FILO).
 *@doubly: A pointer to the head of the linked list.
 *@cline: The line number.
 *
 *Description: This function is used to set the format of data to stack.
 *In this format, elements are removed from the top
 *(LIFO - Last In, First Out).
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void) doubly;
	(void) cline;

	gloVar.lifo = 1;
}
