//STD headers
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <complex>
#include <string>

//Extra headers
#include <exprtk.hpp>

//My headers
#include "../include/utils.hpp"
#include "../include/functions.hpp"

namespace safd
 {
  //============================================
  //     Global variables definition
  //============================================
  exprtk::rtl::io::file::package<double> fileio_package;
  
  //============================================
  //     "Leg_pol" function definition
  //============================================
  
  //Function used to calculate Legendre polynomials with index "a" and variable "x".  
  d_const Leg_pol( i_const a, d_const x ) 
   {
    if( a == 0 ) return 1.0;
    else if( a == 1 ) return x;
    else if( a < 0 ) throw std::runtime_error( "Legendre polynomials index should be greater or equal than 0!" );
    else 
     {
      d_const first_term = ( 2.0 * static_cast<double>( a ) - 1.0) * x * Leg_pol( a-1, x );
      d_const second_term = ( static_cast<double>( a ) - 1.0 ) * Leg_pol( a-2, x );
      d_const diff = ( first_term - second_term ) / static_cast<double>( a );
  
      return diff;
     }
   }
  
  //============================================
  //     "Leg_func" function definition
  //============================================
  
  //Function used to calculate Legendre associated functions with indexes "a" and "b" and variable "x".
  //NB: works well until m = l and | m - l | = 1.
  d_const Leg_func( i_const b, i_const a, d_const x )
   {
    if( x < -1 || x > 1 ) throw std::runtime_error( "Legendre associated functions variable should lie in interval [-1,1]!" );
    else
     {
      if( a < abs( b ) ) throw std::runtime_error( "Legendre associated function indexes a and b should satisfy the relation: a >= b >= 0" );
      //else if( b < 0 ) return pow( -1, b ) * ( factorial( a - b ) / factorial( a + b ) ) * Leg_func( b, a, x );
      //else if( a < 0 ) ...
      else
       {
        d_const first_term = pow( ( 1 - pow( x, 2 ) ), static_cast<double>( b ) / 2 );
        d_const second_term = n_derivative( Leg_pol, x, a, b );
    
        return pow( -1, b ) * first_term * second_term;
       }
     }
   }
  
  //============================================
  //     "sph_arm" function definition
  //============================================
  
  //Function used to calculate spherical armonics with indexes "m" and "l" and variables "theta" and "phi".
  //NB: in the calculator, pi = 3.14, theta = 180.
  cmplx_const sph_arm( i_const m, i_const l, d_const theta, d_const phi )
   {
    if( ( l < m || l < 0 ) || m < 0 ) throw std::runtime_error( "Quantum numbers l and m should satisfy the relation: l >= abs( m ) >= 0" );
    else
     {
      d_const sign_1 = pow( -1, ( m + abs( m ) ) / 2 );
      d_const sign_2 = sqrt( ( ( 2*l + 1 ) * factorial( l - abs( m ) ) ) / ( M_PI*4 * factorial( l + abs( m ) ) ) );
      d_const pol = Leg_func( abs( m ), l, cos( theta ) );
      cmplx_const result ( sign_1 * sign_2 * pol * cos( m*( phi + M_PI ) ), sign_1 * sign_2 * pol * sin( m*( phi + M_PI ) ) );
    
      return result;
     }
   }
  
  //============================================
  //     "parsed_f" function definition
  //============================================
  
  //Function f(theta,phi) obtained with parsing:
  d_const parsed_f( s_const expr, double theta, double phi )
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
  d_const f_theta_phi_real( s_const expr, i_const m, i_const l, d_const theta, d_const phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * sph_arm( m, l, theta, phi ).real();
   }
  
  d_const f_theta_phi_imag( s_const expr, i_const m, i_const l, d_const theta, d_const phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * conj( sph_arm( m, l, theta, phi ) ).imag();
   }
  
  //============================================
  //     "f_m_l" function definition
  //============================================
  
  //This function returns the final f_m_l coefficients.
  cmplx_const f_m_l( s_const expr, i_const m, i_const l )
   {
    cmplx coefficient;
  
    d_const real_part = integral( f_theta_phi_real, expr, m, l );
    d_const imag_part = integral( f_theta_phi_imag, expr, m, l );
    coefficient.real( real_part );
    coefficient.imag( imag_part );
  
    return coefficient;
   }
 }