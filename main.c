#include "monty.h"

void (*f)(stack_t **stack, unsigned int line_number);
global_t gloVar;

/**
 *freeGloVar - Frees the global variables.
 */
void freeGloVar(void)
{
	freeDoublyLinkedList(gloVar.head);
	free(gloVar.buffer);
	fclose(gloVar.fd);
}

/**
 *startGloVar - Initializes the global variables.
 *@fd: File descriptor.
 */
void startGloVar(FILE *fd)
{
	gloVar.lifo = 1;
	gloVar.cont = 1;
	gloVar.arg = NULL;
	gloVar.head = NULL;
	gloVar.fd = fd;
	gloVar.buffer = NULL;
}

/**
 *checkInput - Checks if the file exists and can be opened.
 *@argc: Argument count.
 *@argv: Argument vector.
 *Return: File struct.
 */
FILE *checkInput(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 *main - Entry point.
 *@argc: Argument count.
 *@argv: Argument vector.
 *Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	size_t size = 256;
	ssize_t nlines;
	char *line = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = checkInput(argc, argv);
	startGloVar(fd);

	while ((nlines = getline(&line, &size, fd)) != -1)
	{
		char *opcode = strtok(line, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			f = getOpcode(opcode);

			if (!f)
			{
				dprintf(2, "L%u: unknown instruction %s\n", gloVar.cont, opcode);
				freeGloVar();
				exit(EXIT_FAILURE);
			}

			gloVar.arg = strtok(NULL, " \t\n");
			f(&gloVar.head, gloVar.cont);
		}

		gloVar.cont++;
	}

	free(line);
	freeGloVar();

	return (0);
}
