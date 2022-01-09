#include <iostream>
#include <cmath>

//============================================
//     "n_derivative" function definition
//============================================
//Function used to calculate the "n" derivative of a function "f" in a point "x_0", which depends on an index "a".  
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n )
 {
  if( n == 0 ) return f( a, x_0 );
  else if( n < 0 ) throw std::runtime_error( "Derivative cannot be calculated for order less than 0!" );
  else 
   {
    const double h = pow( __DBL_EPSILON__, 1/3 );
    double x_1 = x_0 - h;
    double x_2 = x_0 + h;
    double first_term = n_derivative( f, x_2, a, static_cast<double>( n ) - 1 );
    double second_term = n_derivative( f, x_1, a, static_cast<double>( n ) - 1);

    return ( first_term - second_term ) / ( 2*h );
   }
 }


//============================================
//     "Leg_pol" function definition
//============================================
//Function used to calculate Legendre polynomials with index "a" and variable "x".  
double Leg_pol( int a, double x ) 
 {
  if( a == 0 ) return 1.0;
  else if( a == 1 ) return x;
  else if( a < 0 ) throw std::runtime_error( "Polynomial index should be major or equal to 0!" );
  else 
   {
    double first_term = ( 2.0 * static_cast<double>( a ) - 1.0) * x * Leg_pol( a-1, x );
    double second_term = ( static_cast<double>( a ) - 1.0 ) * Leg_pol( a-2, x );
    double diff = first_term - second_term;
    diff /= static_cast<double>( a );

    return diff;
   }
 }