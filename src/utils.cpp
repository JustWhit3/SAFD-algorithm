#include <iostream>
#include <cmath>
#include <stdexcept>

#include "../include/utils.hpp"

//============================================
//     "n_derivative" function definition
//============================================
//Function used to calculate the "n"-th derivative of a function "f" in a point "x_0", which depends on an index "a".  
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n )
 {
  if( n == 0 ) return f( a, x_0 );
  else if( n < 0 ) throw std::runtime_error( "Derivative cannot be calculated for order less than 0!" );
  else 
   {
    const double h = pow( __DBL_EPSILON__, 1/3 );
    double x_1 = x_0 - h;
    double x_2 = x_0 + h;
    double first_term = n_derivative( f, x_2, a, n - 1 );
    double second_term = n_derivative( f, x_1, a, n - 1);

    return ( first_term - second_term ) / ( 2*h );
   }
 }

//============================================
//     "round" function definition
//============================================
//Function used to round the value of a double variable.
double round_var( double val )
 {
  if( val < 0 ) return ceil( val - 0.5 );
  else return floor( val + 0.5 );
 }

//============================================
//     "factorial" function definition
//============================================
//Function to find factorial of a variable "n".
unsigned int factorial( unsigned int n  )
 {
  if (n == 0) return 1;
  else return n * factorial( n - 1 );
}