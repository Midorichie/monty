#include "monty.h"

/**
 * handle_hash - When # symbol is the initial non-space character,
 * treat that line as a comment
 *
 * AUTHOR - Hammed Yakub
 *
 * Return: void
 */

void handle_hash(void)
{
	file_ptr->opcode_instruction->opcode = "nop";
	file_ptr->opcode_instruction->f = nop;
}
