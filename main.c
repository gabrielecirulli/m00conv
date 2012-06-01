/*
 *		m00conv.c - Convert M00 files to a format for old PLC machines
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

#include "m00util.h"

/*
 *		int main - Runs the program
 */
int main(int argc, char* argv[])
{
	debug_print_s("m00conv: running in DEBUG mode (debug printing enabled)\n");

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

	return 0;
}

