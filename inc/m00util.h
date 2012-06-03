#ifndef M00UTIL_H
#define M00UTIL_H

/*
 *		m00util.h - Utility functions for m00conv
 */

#include <stdio.h>
#include <stdbool.h>

/* Compile with -DEBUG to expand debug macros */
#ifdef EBUG
	#define debug_print(...) fprintf(stderr, "[DEBUG] " __VA_ARGS__)
#else
	#define debug_print(...)
#endif

/* Define m00data structure */
typedef struct m00data
{
	char* in_file_name;
	char* out_file_name;
	FILE* in_file;
	FILE* out_file;
} m00data_t;

/* Other functions */
void terminate(int code);
void check_args(int argc, char* argv[], struct m00data* data);

char* strip_spaces(char* line);
char* strip_comments(char* line);
bool is_comment(char* line);

#endif
