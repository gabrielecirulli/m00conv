/*
 *		m00util.h - Utility libraries for m00conv
 */

// Debug printing facility
// http://stackoverflow.com/a/1644898/151377
#define DEBUG 0
#define debug_print(fmt, ...) \
	do { \
		if (DEBUG) { \
			fprintf(stderr, "(DEBUG) "); \
			fprintf(stderr, fmt, __VA_ARGS__); \
		} \
	} while(0)

#define debug_print_s(fmt) \
	do { \
		if (DEBUG) { \
			fprintf(stderr, "(DEBUG) "); \
			fprintf(stderr, fmt); \
		} \
	} while(0)

// Other functions
void show_help();
void terminate(int code);
void check_args(int argc, char* argv[]);
