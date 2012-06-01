/*
 *		m00util.c - Utility libraries for m00conv
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "m00util.h"

/* 
 *		void show_help - Show usage information for the program
 */
void show_help()
{
	printf(
		"Usage: m00conv [OPTION]... INPUT OUTPUT\n"
		"Convert INPUT and save it to OUTPUT\n"
		"\n"
		"Mandatory arguments to long options are mandatory for short options too.\n"
		"  -h, --help\tdisplay this help and exit\n"
		);
	terminate(0);
}

/* 
 *		void terminate - Terminate the program (wraps around exit())
 *		
 *		Arguments:
 *			int code - The code to exit with
 */
void terminate(int code)
{
	if(code == 0)
		debug_print_s("Program terminated successfully (0)\n");
	else
		debug_print("Program terminated with error (%d)\n", code);
	exit(code);
}

/*
 *		check_args - Perform a check on the command-line arguments and execute actions accordingly
 *		
 *		Arguments:
 *			int argc - The number of arguments
 *			char* argv[] - The arguments vector
 */
void check_args(int argc, char* argv[])
{
	bool help_request = false;

	int i;
	for(i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) 
		{
			debug_print("argv[%d] = '%s', help_request\n", i, argv[i]);
			help_request = true;
		}
	}

	if(help_request)
	{
		debug_print_s("Showing help and quitting\n");
		show_help();
	}
	else
	{
		if(argc != 3)
		{
			if(argc == 1)
				fprintf(stderr, "m00conv: missing INPUT operand\n");
			else if(argc == 2)
				fprintf(stderr, "m00conv: missing OUTPUT operand\n");
			else
				fprintf(stderr, "m00conv: too many arguments specified\n");

			fprintf(stderr, "Try 'm00conv --help' for more information\n");
			terminate(0);
		}
	}

	
}
