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

#include "m00util.h"
#include "m00convert.h"

/*
 *		int main - Runs the program
 */
int main(int argc, char* argv[])
{
	debug_print("m00conv: running in DEBUG mode (debug printing enabled)\n");

	/* Create a structure for program data */
	struct m00data data;

	/* Run args check (terminates program if args don't meet requirements) */
	check_args(argc, argv, &data);		

	/* Run conversion */
	do_conversion(&data);

	/* Finished */
	fprintf(stdout, "m00conv: '%s' has been converted correctly and saved as '%s'\n",
		data.in_file_name, data.out_file_name);

	return 0;
}

