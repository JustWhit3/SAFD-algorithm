#include <iostream>
#include <cmath>
#include <stdexcept>

#include "../include/utils.hpp"

//============================================
//     Global variables definition
//============================================

//Derivative constants:
const double STEP_SIZE = 2 * cbrt( __DBL_EPSILON__ );

//Integral constants (x):
const double x_0_int = 0;
const double x_1_int = M_PI/2;
const double x_2_int = M_PI;
const double x_3_int = M_PI*3/2;
const double x_4_int = M_PI*2;
const double h_x = ( x_4_int - x_0_int ) / 4;

//Integral constants (y):
const double y_0_int = 0;
const double y_1_int = M_PI/4;
const double y_2_int = M_PI/2;
const double y_3_int = M_PI*3/4;
const double y_4_int = M_PI;
const double h_y = ( y_4_int - y_0_int ) / 4;

//============================================
//     "n_derivative" function definition
//============================================

//Function used to calculate the "n"-th derivative of a function "f" in a point "x_0", which depends on an index "a". 
//NB: Works well until n = 3/4. 
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n )
 {
  if( n == 0 ) return f( a, x_0 );
  else if( n < 0 ) throw std::runtime_error( "Derivative cannot be calculated for order less than 0!" );
  else 
   {
    double h;
    if ( n < 4 && n > 0 ) h = STEP_SIZE * x_0;
    else h = n; //Condition for Legendre associated functions.

    double x_1 = x_0 - h;
    double x_2 = x_0 + h;
    double first_term = n_derivative( f, x_2, a, n - 1 );
    double second_term = n_derivative( f, x_1, a, n - 1);

    return ( first_term - second_term ) / ( x_2 - x_1 );
   }
 }

//============================================
//     "round" function definition
//============================================

//Function used to round the value of a double variable.
//NB: used for testing only.
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

//============================================
//     "IsInBounds" function definition
//============================================

//Function to check if a "value" is in bound [low, high].
//NB: used for testing only.
template <typename T>
bool IsInBounds( const T& value, const T& low, const T& high )
 {
  return !( value < low ) && ( value < high );
 } 

template bool IsInBounds <double> ( const double& value, const double& low, const double& high );

//============================================
//     "integral" function definition
//============================================

//Function to integrate a function f(x,y), depending on two indexes m and l.
double integral( double ( *f )( int, int, double, double ), int m, int l )
 {
  double first_term =
  double second_term =
  double third_term =
  double fourth_term =
  double fifth_term =

  return first_term * second_term * third_term + fourth_term + fifth_term;
 }