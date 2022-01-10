#include <iostream>
#include <cmath>
#include <stdexcept>

#include "../include/utils.hpp"
#include "../include/functions.hpp"

//============================================
//     "Leg_pol" function definition
//============================================
//Function used to calculate Legendre polynomials with index "a" and variable "x".  
double Leg_pol( int a, double x ) 
 {
  if( a == 0 ) return 1.0;
  else if( a == 1 ) return x;
  else if( a < 0 ) throw std::runtime_error( "Legendre polynomial index should be greater or equal than 0!" );
  else 
   {
    double first_term = ( 2.0 * static_cast<double>( a ) - 1.0) * x * Leg_pol( a-1, x );
    double second_term = ( static_cast<double>( a ) - 1.0 ) * Leg_pol( a-2, x );
    double diff = first_term - second_term;
    diff /= static_cast<double>( a );

    return diff;
   }
 }

//============================================
//     "Leg_func" function definition
//============================================
//Function used to calculate Legendre associated functions with indexes "a" and "b" and variable "x".
double Leg_func( int b, int a, double x )
 {
  if( x < -1 || x > 1 ) throw std::runtime_error( "Legendre associated function variable should stay in interval [-1,1]!" );
  else
   {
    if( a < b || b < 0 ) throw std::runtime_error( "Legendre associated function indexes a and b should satisfy the relation a >= b >= 0" );
    else
     {
      double first_term = pow( ( 1 - pow( x, 2 ) ), static_cast<double>( b ) / 2 );
      double second_term = n_derivative( Leg_pol, x, a, b );
  
      return pow( -1, b ) * first_term * second_term;
     }
   }
 }

//============================================
//     "sph_arm" function definition
//============================================
//Function used to calculate spherical armonics with indexes "m" and "l" and variables "theta" and "phi".
double sph_arm( int m, int l, double theta, double phi )
 {
  int sign_1 = pow( -1, ( m + abs( m ) ) / 2 );
  //int sign_2 = sqrt( ( ( 2*l + 1 ) * factorial( l - abs( m ) ) ) / () );
  
  //return ;
 }