/*
 *		m00convert.c - Conversion functions for m00conv
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "m00util.h"
#include "m00convert.h"

/* Data for files */
char file_head[] =
	"%!*\n"
	"    N` G`   X`     Z`   F` H\n"
	"    00 21\n"
	"    01 90\n"
	"    02 92  0000   0000\n";

char file_end[] =
	"    08M30\n"
	"   M\n";

/* 'private' functions */
static void open_files(m00data_t* data);
static void close_files(m00data_t* data);
static void convert_files(m00data_t* data);
static bool parse_line(char* line, int* g, int* x, int* z);

void do_conversion(m00data_t* data)
{
	debug_print("Beginning file conversion.\n");
	open_files(data);

	fputs(file_head, data->out_file);

	convert_files(data);

	fputs(file_end, data->out_file);

	close_files(data);
}

static void open_files(m00data_t* data)
{
	debug_print("Opening files %s and %s\n", data->in_file_name, data->out_file_name);

	data->in_file = fopen(data->in_file_name, "r"); /* Open input file from command line */
	if(data->in_file == NULL)
	{
		fprintf(stderr, "m00conv: error reading file '%s'", data->in_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", data->in_file_name);
	}

	data->out_file = fopen(data->out_file_name, "w");
	if(data->out_file == NULL)
	{
		fprintf(stderr, "m00conv: error writing file '%s'\n", data->out_file_name);
		terminate(1);
	}
	else
	{
		debug_print("File '%s' opened correctly\n", data->out_file_name);
	}
}

static void close_files(m00data_t* data)
{
	debug_print("Closing files %s and %s\n", data->in_file_name, data->out_file_name);

	if(fclose(data->in_file) != 0)
	{
		fprintf(stderr, "m00conv: error closing file '%s'\n", data->in_file_name);
		/* terminate(1); */
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", data->in_file_name);
	}

	if(fclose(data->out_file) != 0)
	{
		fprintf(stderr, "m00conv: error closing file '%s'\n", data->out_file_name);
		/* terminate(1); */
	} 
	else
	{
		debug_print("File '%s' closed correctly\n", data->out_file_name);
	}
}

static void convert_files(m00data_t* data)
{
	debug_print("Starting file conversion\n");
	
	char line[256];
	unsigned long line_a = 0, line_c = 0; /* line_a: count of all lines; line_c: converted lines */
	int g = 0, x = 0, z = 0;
	
	debug_print("Beginning to read the file\n");
	while(fgets(line, 255, data->in_file) != NULL)
	{
		line_a++; /* Increase line count */
		char* stripped = strip_spaces(strip_comments(line));

		if(is_blank(stripped) || !parse_line(stripped, &g, &x, &z))
			continue; /* Skip unuseful lines */

		line_c++;

		debug_print("L%lu A%lu (-%lu): '%s'\n"
			"\tg=%d  x=%d  z=%d\n\n",
			line_a, line_c, line_a-line_c, line,
			g, x, z);

		/*fputs(sprintf("    %02d ", ))*/
	}
	debug_print("Finished reading the file\n");
}

/*
 *		parse_line - Parses g, x and z values from a line
 *		
 *		Arguments:
 *			char* line - A pointer to the line to be parsed
 *			int* g - A pointer to a g value to update
 *			int* x - A pointer to a x value to update
 *			int* z - A pointer to a z value to update
 *		
 *		Returns:
 *			True if the line is valid (lines with G between 0 and 3 or a X or a Z), false otherwise
 */
static bool parse_line(char* line, int* g, int* x, int* z)
{
	char* work_line = calloc(strlen(line)+1, 1);
	strcpy(work_line, line);
	char* token = strtok(work_line, " ");

	bool found = false;

	int temp_g;

	while(token != NULL)
	{		
		char initial = tolower(token[0]);
		token++;

		switch(initial)
		{
			case 'g':
				temp_g = atoi(token);
				if(temp_g > 3)
					return false; /* Line has a bad G value, ignore it completely */
				*g = temp_g;
				found = true;
				break;
			case 'x':
				*x = (int)(atof(token) * 100);
				found = true;
				break;
			case 'z':
				*z = (int)(atof(token) * 100);
				found = true;
		}

		token = strtok(NULL, " ");
	}

	return found;
}
