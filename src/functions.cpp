#include <iostream>
#include <cmath>

//============================================
//     Leg_pol function definition
//============================================
//Function used to calculate Legendre polynomials with index "a" and variable "x".  
double Leg_pol( int a, double x ) 
 {
  double diff, first_term, second_term;

  if( a == 0 ) return 1.0;
  else if( a == 1 ) return x;
  else if( a < 0 ) throw std::runtime_error( "Polynomial index should be major or equal to 0!" );
  else 
   {
    first_term = ( 2.0 * static_cast<double>( a ) - 1.0) * x * Leg_pol( a-1, x );
    second_term = ( static_cast<double>( a ) - 1.0 ) * Leg_pol( a-2, x );
    diff = first_term - second_term;
    diff /= static_cast<double>( a );
    
    return diff;
   }
 }