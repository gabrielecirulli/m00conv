/*
 *		m00convert.c - Conversion functions for m00conv
 */

#include "m00util.h"
#include "m00convert.h"

/* 'private' functions */
void open_files(struct m00data* data);
void close_files(struct m00data* data);
void convert_files(struct m00data* data);

void do_conversion(struct m00data* data)
{
	debug_print("Beginning file conversion.\n");
	open_files(data);
	convert_files(data);
	close_files(data);
}

void open_files(struct m00data* data)
{
	debug_print("Opening files %s and %s\n", data->in_file_name, data->out_file_name);

	data->in_file = fopen(data->in_file_name, "r"); /* Open input file from command line */
	if(data->in_file == NULL)
	{
		fprintf(stderr, "m00conv: error reading file '%s'\n", data->in_file_name);
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

void close_files(struct m00data* data)
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

void convert_files(struct m00data* data)
{

}
