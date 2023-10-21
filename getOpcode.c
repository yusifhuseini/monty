#include "monty.h"

/**
 *getOpcode - selects the correct opcode to perform
 *@opc: opcode passed
 *
 *Description:
 *This function searches for the given opcode in a predefined instruction
 *table and returns a pointer to the corresponding function if found.
 *
 *@opc: The opcode to search for.
 *
 *Return: pointer to the function that executes the opcode,
 *or NULL if not found.
 */
void(*getOpcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	/**
	 *instruction_t - Struct to hold opcode and function pointers.
	 *@opcode: The opcode name.
	 *@f: The function to execute for the opcode.
	 */
	instruction_t instruct[] = {
		{ "push",
			_push
		},
		{ "pall",
			_pall
		},
		{ "pint",
			_pint
		},
		{ "pop",
			_pop
		},
		{ "swap",
			_swap
		},
		{ "add",
			_add
		},
		{ "nop",
			_nop
		},
		{ "sub",
			_sub
		},
		{ "div",
			_div
		},
		{ "mul",
			_mul
		},
		{ "mod",
			_mod
		},
		{ "pchar",
			_pchar
		},
		{ "pstr",
			_pstr
		},
		{ "rotl",
			_rotl
		},
		{ "rotr",
			_rotr
		},
		{ "stack",
			_stack
		},
		{ "queue",
			_queue
		},
		{
			NULL,
			NULL
		}
	};

	int i;

	/*Loop through the instruction table to find the opcode. */
	for (i = 0; instruct[i].opcode; i++)
	{
		if (_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	/*Return the corresponding function or NULL if not found. */
	return (instruct[i].f);
}
