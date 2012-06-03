/*
 *		m00util.c - Utility functions for m00conv
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>

#include "m00util.h"

/* 'private' functions */
static void show_help();
static int file_exists(char* file_name);

/* 
 *		void show_help - Show usage information for the program
 */
static void show_help()
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
		debug_print("Program terminated successfully (0)\n");
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
void check_args(int argc, char* argv[], m00data_t* data)
{
	/*
	 * We're ignoring any possible race conditions that might arise
	 * from checking for file existance and file creation in a non-atomical way
	 * because of the low-security purposes of this program.
	 */

	data->in_file_name = NULL;
	data->out_file_name = NULL;

	/* Check for terminating arguments */
	for(int i = 0; i < argc; i++)
	{
		debug_print("Checking argument %d: %s\n", i, argv[i]);
		if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) 
		{
			debug_print("argv[%d] = '%s', help_request\n", i, argv[i]);
			
			debug_print("Showing help and quitting\n");
			show_help();
		}
	}

	/* Check argument count */
	if(argc < 3)
	{
		fprintf(stderr, "m00conv: too few arguments specified\n");
		fprintf(stderr, "Try 'm00conv --help' for more information\n");
		terminate(0);
	}
		
	/* Check for input file existence */
	if(file_exists(argv[argc - 2]))
	{
		debug_print("File '%s' found.\n", argv[argc - 2]);
		data->in_file_name = argv[argc - 2];		
	}
	else
	{
		fprintf(stderr, "m00conv: cannot stat '%s': No such file or directory\n", argv[argc - 2]);
		terminate(1);
	}
	
	/* Check output file */
	if(!file_exists(argv[argc - 1])) /* If the file doesn't exist, everything's OK */
	{
		debug_print("File '%s' not found, OK.\n", argv[argc - 1]);
		data->out_file_name = argv[argc - 1];
	}
	else
	{
		printf("File '%s' already exists; overwrite? y/n: ", argv[argc - 1]);
		char choice = tolower(getchar());
		if(choice == 'y')
		{
			data->out_file_name = argv[argc - 1];
		}
		else
		{
			fprintf(stderr, "m00conv: file '%s' already exists; terminating\n", argv[argc - 1]);
			terminate(1);
		}
	}

	/* Final checks */
	if(!data->in_file_name || !data->out_file_name)
	{
		if(data->in_file_name == NULL)
			fprintf(stderr, "m00conv: missing INPUT operand\n");

		if(data->out_file_name == NULL)
			fprintf(stderr, "m00conv: missing OUTPUT operand\n");

		fprintf(stderr, "Try 'm00conv --help' for more information\n");
		terminate(0);
	}

	/* Everything OK, execution can continue */
}

/*
 *		check_file - Checks the specified file
 *		
 *		Arguments:
 *			int argc - The number of arguments
 *			char* argv[] - The arguments vector
 *		
 *		Returns:
 *			1 if file exists, 0 otherwise
 */
static int file_exists(char* file_name)
{
	struct stat buffer;
	/* If the buffer remains empty, the file doesn't exist */
	return (stat(file_name, &buffer) == 0);
}

/*
 *		strip_spaces - Strips any leading or trailing spaces from the line
 *		
 *		Arguments:
 *			char* line - A pointer to the line to modify
 *		
 *		Returns:
 *			A pointer to the beginning of the modified souce line
 */
char* strip_spaces(char* line)
{
	while(isspace(*line)) line++;

	if(*line == 0) return line;

	char* end; /* Pointer to the last character of the new line */
	end = line + strlen(line) - 1;

	while(end > line && isspace(*end)) end--;

	*(end + 1) = 0;

	return line;
}

char* strip_comments(char* line)
{
	/* debug_print("Stripping comments from '%s'\n", line); */
	for(int i = 0; i < strlen(line); i++)
	{
		if(line[i] == '(' && line[i+1] == '*')
		{
			line[i] = 0;
			break;
		}	
	}
	/* debug_print("Comments stripped: '%s'\n", line); */
	return line;
}

bool is_blank(char* line)
{
	if(!strlen(line))
		return true;
	return false;
}
