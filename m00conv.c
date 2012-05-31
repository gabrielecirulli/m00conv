/*
 * Programma convertitore per file M00
 *
 * Utilizzo:
 * convertitore [file input] [file output]

 File input
	> Rendere compatibile
	> Eliminare commenti

	> ignorare righe con g diverso da 0,1,2,3

	>
 File output
	> prima riga %!*
	> campi n, g, x, z, f, h
	> larghezza campi sotto

	> fino a 02 rimangono uguali

	> Righe numerate senso crescente

	> Numero dopo g preso in N
	> Numero X * 100
	> Numeo Z * 100

	> Dove non compare G si copia la G precedente
	> Vengono ignorati se non hanno una g e una x o una z

	> Dove non ci sono nuove X o Z rimane quella sopra

	> Se non c'è una nuova G si ricopia la G precedente

	> 08M30, M chiude il file

 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// http://stackoverflow.com/a/1644898/151377
#define DEBUG 1
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
		fprintf(stderr, "Error opening file '%s'\n", in_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", in_file_name);
	}

	out_file = fopen(out_file_name, "w");
	if(out_file == NULL)
	{
		fprintf(stderr, "Error opening file '%s'\n", out_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", out_file_name);
	}




	// Closing files
	if(fclose(in_file) != 0)
	{
		fprintf(stderr, "Error closing file '%s'\n", in_file_name);
		terminate(1);
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", in_file_name);
	}

	if(fclose(out_file) != 0)
	{
		fprintf(stderr, "Error closing file '%s'\n", out_file_name);
		terminate(1);
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", out_file_name);
	}

	fprintf(stdout, "%s has been written correctly!\n", out_file_name);

	terminate(0);
}

/* 
 *		void show_help - Show usage information for the program
 */
void show_help()
{
	printf(
		"m00conv - M00 file converter\n"
		"\n"
		"Usage: m00conv [input_file] [output_file]\n"
		"\n"
		"input_file: name of the file to be read\n"
		"output_file: name of the file to be written\n"
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
	bool show_help = false;

	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "--help") || strcmp(argv[i], "-h"))
			show_help = true;
	}

	if(show_help)
	{
		debug_print("Not enough arguments (%d), showing help and quitting\n", argc);
		show_help();
	}
	else
	{
		if(argc != 3)
		{
			if(argc == 1)
				fprintf(stderr, "m00conv - missing input_file operand\n");
			else if(argc == 2)
				fprintf(stderr, "m00conv - missing output_file operand\n");
			else
				fprintf(stderr, "m00conv - too many arguments specified\n");

			fprintf(stderr, "Try 'm00conv --help' for more information\n");
			terminate(0);
		}
	}

	
}
