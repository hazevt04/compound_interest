#ifndef MY_UTIL_H
#define MY_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

// Glenn Hazelwood

// Utility functions and macros I like to use
// in my C code

#define NUM_INT_BITS (8*sizeof(int))
#define MAX_NUM_CHARS 80   

#ifndef MALLOC_AND_CHECK_ERROR 
#   define MALLOC_AND_CHECK_ERROR(ptr, type, nbytes) \
      ptr = (type *)malloc(nbytes); \
      if (!ptr) { \
         fprintf(stderr, "In %s on line %d, function %s: " \
            "ERROR: malloc of " #ptr \
            " of type " #type \
            " for %zu bytes failed.\n", \
             __FILE__, __LINE__, __func__, nbytes ); \
         exit(EXIT_FAILURE); \
      }
#endif

#ifndef FREE_AND_NULL_PTR
#   define FREE_AND_NULL_PTR(ptr) \
      free(ptr); \
      ptr = NULL; 
#endif

#ifndef HDEBUG_PRINTF
#  define HDEBUG_PRINTF(fmt, ...) { \
      if ( debug ) { \
         printf(fmt, ##__VA_ARGS__); \
      } \
}
#endif


#ifndef FUNC_AND_CHECK_ERROR
#   define FUNC_AND_CHECK_ERROR(fun) {\
      if ((fun) != EXIT_SUCCESS) { \
         fprintf(stderr, "In %s on line %d, function %s: ERROR " #fun \
              " failed.\n", \
             __FILE__, __LINE__, __func__ ); \
         exit (EXIT_FAILURE); \
      } \
}
#endif

#ifndef CHECK_PTR
#  define CHECK_PTR(ptr) {\
      if (!ptr) { \
         fprintf(stderr, "In %s on line %d, function %s: ERROR " #ptr \
              " is NULL. Malloc failed?\n", \
             __FILE__, __LINE__, __func__ ); \
         exit (EXIT_FAILURE); \
      } \
}
#endif

#endif // MY_UTIL_H
