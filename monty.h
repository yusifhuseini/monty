#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809 L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 *struct stack_s - Doubly linked list representation of a stack (or queue).
 *@n: Integer value stored in the node.
 *@prev: Pointer to the previous element of the stack (or queue).
 *@next: Pointer to the next element of the stack (or queue).
 *
 *Description: This structure defines a doubly linked list node
 *for stack and queue operations in the Monty project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}

stack_t;

/**
 *struct globals - Global structure used by Monty functions.
 *@lifo: Flag indicating if it's a stack (0) or queue (1).
 *@cont: Current line number in the script.
 *@arg: Second parameter inside the current line.
 *@head: Doubly linked list representing the stack/queue.
 *@fd: File descriptor for the Monty script file.
 *@buffer: Input text buffer.
 *
 *Description: This structure holds global information used by various
 *functions in the Monty project.
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
}

global_t;

/**
 *struct bus_s - Structure for carrying values through the program.
 *@arg: Value.
 *@file: Pointer to the Monty file.
 *@content: Line content.
 *@lifi: Flag to change between stack and queue (0/1).
 *
 *Description: This structure is used to pass values through various
 *parts of the Monty program.
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}

bus_t;

/*Declare the bus_t global variable */
extern bus_t bus;

/**
 *struct instruction_s - Opcode and its associated function.
 *@opcode: The opcode (e.g., "push", "pall").
 *@f: Function to handle the opcode.
 *
 *Description: This structure associates an opcode string with its
 *corresponding function for the Monty project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
}

instruction_t;

/*Declare the global_t global variable */
extern global_t gloVar;

/*Opcode instructions functions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _swap(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);

/*Function to get an opcode function based on the opcode string */
void(*getOpcode(char *opcode))(stack_t **stack, unsigned int line_number);

/*Imported functions */
char *_strtoky(char *s, char *delimiters);
int _sch(char *s, char c);
int _strcmp(const char *s1, const char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*Doubly linked list functions */
stack_t *addNode(stack_t **head, const int n, int atEnd);
stack_t *addNodeEnd(stack_t **head, const int n);
stack_t *addNodeBegin(stack_t **head, const int n);
void freeDoublyLinkedList(stack_t *head);

/*Main function to free global variables */
void freeGloVar(void);

/*Function to check if a string represents an integer */
int is_integer(const char *str);

/*Function to pop a node from the doubly linked list */
void popNode(stack_t **doubly);

/*Function to swap two nodes in the doubly linked list */
void swapNodes(stack_t **doubly);


#endif /*MONTY_H */
