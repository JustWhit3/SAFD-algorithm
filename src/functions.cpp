#include <iostream>
#include <cmath>
#include <stdexcept>
#include <complex>
#include <string>
#include <exprtk.hpp>

#include "../include/utils.hpp"
#include "../include/functions.hpp"

//============================================
//     Aliases definition (exprtk library)
//============================================
typedef exprtk::symbol_table<double> symbol_table_t;
typedef exprtk::expression<double>     expression_t;
typedef exprtk::parser<double>             parser_t;

exprtk::rtl::io::file::package<double> fileio_package;

//============================================
//     "Leg_pol" function definition
//============================================

//Function used to calculate Legendre polynomials with index "a" and variable "x".  
double Leg_pol( int a, double x ) 
 {
  if( a == 0 ) return 1.0;
  else if( a == 1 ) return x;
  else if( a < 0 ) throw std::runtime_error( "Legendre polynomials index should be greater or equal than 0!" );
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
//NB: works well until m = l and | m - l | = 1.
double Leg_func( int b, int a, double x )
 {
  if( x < -1 || x > 1 ) throw std::runtime_error( "Legendre associated functions variable should lie in interval [-1,1]!" );
  else
   {
    if( a < abs( b ) ) throw std::runtime_error( "Legendre associated function indexes a and b should satisfy the relation: a >= b >= 0" );
    //else if( b < 0 ) return pow( -1, b ) * ( factorial( a - b ) / factorial( a + b ) ) * Leg_func( b, a, x );
    //else if( a < 0 ) ...
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
//NB: in the calculator, pi = 3.14, theta = 180.
cmplx sph_arm( int m, int l, double theta, double phi )
 {
  if( ( l < m || l < 0 ) || m < 0 ) throw std::runtime_error( "Quantum numbers l and m should satisfy the relation: l >= abs( m ) >= 0" );
  else
   {
    double sign_1 = pow( -1, ( m + abs( m ) ) / 2 );
    double sign_2 = sqrt( ( ( 2*l + 1 ) * factorial( l - abs( m ) ) ) / ( M_PI*4 * factorial( l + abs( m ) ) ) );
    double pol = Leg_func( abs( m ), l, cos( theta ) );
    cmplx result ( sign_1 * sign_2 * pol * cos( m*( phi + M_PI ) ), sign_1 * sign_2 * pol * sin( m*( phi + M_PI ) ) );
  
    return result;
   }
 }

//============================================
//     "parsed_f" function definition
//============================================

//Function f(theta,phi) obtained with parsing:
double parsed_f( const std::string expr, double theta, double phi )
 {
  symbol_table_t symbol_table;
  symbol_table.add_variable( "th", theta );
  symbol_table.add_variable( "phi",phi );

  expression_t foo;
  foo.register_symbol_table( symbol_table );

  parser_t parser;
  if ( !parser.compile( expr, foo ) )
   {
    throw std::runtime_error( "Error in the inserted expression!" );
   }
  
  return foo.value();
 }

//============================================
//     "f_theta_phi" function definition
//============================================

//This function defines: f(theta,phi) * conjugate( sph_arm(m,l,theta,phi) ) * sin(theta).
cmplx f_theta_phi( std::string expr, int m, int l, double theta, double phi )
 { 
  cmplx result;

  double real_part = parsed_f( expr, theta, phi ) * sin( theta ) * sph_arm( m, l, theta, phi ).real();
  double imag_part = parsed_f( expr, theta, phi ) * sin( theta ) * conj( sph_arm( m, l, theta, phi ) ).imag();
  result.real( real_part );
  result.imag( imag_part );

  return result;
 }