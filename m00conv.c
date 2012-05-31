/*
 *		m00conv - Convert M00 files to a format for old PLC machines
 *
 *		Usage: m00conv [OPTION]... INPUT OUTPUT
 *		Convert INPUT and save it to OUTPUT
 *
 *		Mandatory arguments to long options are mandatory for short options too.
 *			-h, --help	display this help and exit
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// http://stackoverflow.com/a/1644898/151377
#define DEBUG 0
#define debug_print(fmt, ...) \
	do { \
		if (DEBUG) { \
			fprintf(stderr, "(DEBUG) "); \
			fprintf(stderr, fmt, __VA_ARGS__); \
		} \
	} while(0)

void show_help();
void terminate(int code);
void check_args(int argc, char* argv[]);

/*
 *		int main - Runs the program
 */
int main(int argc, char* argv[])
{
	debug_print("m00conv: running in DEBUG mode (debug printing enabled)\n", "");

	// Run args check (terminates program if args don't meet requirements)
	check_args(argc, argv);
			

	// Opening files
	char* in_file_name = argv[1]; // Name of input file
	char* out_file_name = argv[2]; // Name of output file

	FILE* in_file; // The file which has to be read
	FILE* out_file; // The file onto which the output will be written

	in_file = fopen(in_file_name, "r"); // Open input file from command line
	if(in_file == NULL)
	{
		fprintf(stderr, "m00conv: error opening file '%s'\n", in_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", in_file_name);
	}

	out_file = fopen(out_file_name, "w");
	if(out_file == NULL)
	{
		fprintf(stderr, "m00conv: error opening file '%s'\n", out_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", out_file_name);
	}




	// Closing files
	if(fclose(in_file) != 0)
	{
		fprintf(stderr, "m00conv: error closing file '%s'\n", in_file_name);
		terminate(1);
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", in_file_name);
	}

	if(fclose(out_file) != 0)
	{
		fprintf(stderr, "m00conv: error closing file '%s'\n", out_file_name);
		terminate(1);
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", out_file_name);
	}

	fprintf(stdout, "'%s' has been converted correctly and saved to '%s'\n", in_file_name, out_file_name);

	terminate(0);
}

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
		debug_print("Program terminated successfully (0)\n", "");
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

	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
			help_request = true;
	}

	if(help_request)
	{
		debug_print("Not enough arguments (%d), showing help and quitting\n", argc);
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
