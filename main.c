#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "my_util.h"
// A = P(1+(r/n))^(nt)
double compound_interest( int debug, double principal, double interest_rate, double time_factor, double num_times ) {
   double exponent = num_times * time_factor;
   HDEBUG_PRINTF( "%s(): Exponent is %f\n", __func__, exponent );
   double adjusted_rate = ( interest_rate / num_times );
   HDEBUG_PRINTF( "%s(): Adjusted rate is %.4f\n", __func__, adjusted_rate );
   
   double overall_factor = pow( ( 1 + adjusted_rate ), exponent );
   HDEBUG_PRINTF( "%s(): Overall Factor = %.4f\n", __func__, overall_factor );

   return ( principal * overall_factor );
}


void usage( const char* prog_name ) {
   printf( "Usage: %s <principal> <interest rate> <time factor> <number of times> <optional 'debug'>\n", prog_name ); 
}


void parse_input( const char* var_name, const char* arg, double* var_val ) {
   char* end_ptr = NULL;
   
   *var_val = strtod( arg, &end_ptr );
   if ( *end_ptr ) {
      printf( "ERROR: '%s' is invalid input for %s\n", arg, var_name ); 
      exit( EXIT_FAILURE );
   }
} 


int main( int argc, char* argv[] ) {

   double principal = 0.0;
   double interest_rate = 0.0;
   double time_factor = 0.0;
   double num_times = 0.0;
   bool debug = false;

   if ( argc < 5 ) {
      printf( "Error: Missing argument.\n" );
      usage( argv[0] );
      exit( EXIT_FAILURE );
   } 
   if ( argc == 6 ) {
      if ( !strncmp( "debug", argv[5], 5 ) ) {
         debug = true;
      } else {
         printf( "Invalid arg: %s. Do you mean 'debug'?\n", argv[5] );
         usage( argv[0] );
         exit( EXIT_FAILURE );
      }
   } // end of if ( argc == 6 )
   
   parse_input( "principal", argv[1], &principal );
   parse_input( "interest_rate", argv[2], &interest_rate );
   parse_input( "time_factor",  argv[3], &time_factor );
   parse_input( "num_times",  argv[4], &num_times );  

   HDEBUG_PRINTF( "Principal is $%.2f\n", principal );
   HDEBUG_PRINTF( "Interest Rate is %.4f\n", interest_rate );
   HDEBUG_PRINTF( "Time Factor is %f\n", time_factor );
   HDEBUG_PRINTF( "Number of Times is %f\n", num_times );

   double future_balance = compound_interest( debug, principal, interest_rate, time_factor, num_times ); 
   
   printf( "The principal of $%.2f had an interest rate of %d %%, over %d periods.\n", 
      principal, (int)(interest_rate * 100), (int)(num_times * time_factor) );   
   printf( "The future balance will be $%.2f\n", future_balance );
   exit( EXIT_SUCCESS ); 
}
