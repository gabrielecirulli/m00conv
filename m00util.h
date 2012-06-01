/*
 *		m00util.h - Utility libraries for m00conv
 */


// Compile with -DEBUG to expand debug macros
#ifdef EBUG
	#define debug_print(...) fprintf(stderr, "(DEBUG) " __VA_ARGS__)
#else
	#define debug_print(...)
#endif


// Other functions
void show_help();
void terminate(int code);
void check_args(int argc, char* argv[]);
