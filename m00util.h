/*
 *		m00util.h - Utility functions for m00conv
 */

// Compile with -DEBUG to expand debug macros
#ifdef EBUG
	#define debug_print(...) fprintf(stderr, "(DEBUG) " __VA_ARGS__)
#else
	#define debug_print(...)
#endif

// Structures
struct m00data
{
	char* in_file_name;
	char* out_file_name;
};

// Other functions
void show_help();
void terminate(int code);
void check_args(int argc, char* argv[], struct m00data* data);
int file_exists(char* file_name);
