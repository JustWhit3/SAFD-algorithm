//My headers
#include "../include/utils.hpp"
#include "../include/functions.hpp"

//Extra headers
#include <osmanip/manipulators/csmanip.hpp>
#include <exprtk.hpp>

//STD headers
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <complex>
#include <string>

namespace safd
 {
  //============================================
  //     Type aliases definition
  //============================================
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double>     expression_t;
  typedef exprtk::parser<double>             parser_t;

  //============================================
  //     Global variables definition
  //============================================
  exprtk::rtl::io::file::package<double> fileio_package;
  cmplx coefficient;
  
  //============================================
  //     "Leg_pol" function definition
  //============================================
  
  //Function used to calculate Legendre polynomials with index "a" and variable "x".  
  const double Leg_pol( const int a, const double x ) 
   {
    if( a == 0 ) return 1.0;
    else if( a == 1 ) return x;
    else if( a < 0 )
     {
      throw std::runtime_error( "\033[31mLegendre polynomials index should be greater or equal than 0!\033[0m" );
     }
    else 
     {
      const double first_term = ( 2.0 * static_cast<double>( a ) - 1.0) * x * Leg_pol( a-1, x );
      const double second_term = ( static_cast<double>( a ) - 1.0 ) * Leg_pol( a-2, x );
      const double diff = ( first_term - second_term ) / static_cast<double>( a );
  
      return diff;
     }
   }
  
  //============================================
  //     "Leg_func" function definition
  //============================================
  
  //Function used to calculate Legendre associated functions with indexes "a" and "b" and variable "x".
  //NB: works well until m = l and | m - l | = 1.
  const double Leg_func( const int b, const int a, const double x )
   {
    if( x < -1 || x > 1 ) throw std::runtime_error( "\033[31mLegendre associated functions variable should lie in interval [-1,1]!\033[0m" );
    else
     {
      if( a < abs( b ) ) throw std::runtime_error( "\033[31mLegendre associated function indexes a and b should satisfy the relation: a >= b >= 0\033[0m" );
      else
       {
        const double first_term = pow( ( 1 - (x * x) ), static_cast<double>( b ) * 0.5 );
        const double second_term = n_derivative( &Leg_pol, x, a, b );
    
        return pow( -1, b ) * first_term * second_term;
       }
     }
   }
  
  //============================================
  //     "sph_arm" function definition
  //============================================
  
  //Function used to calculate spherical armonics with indexes "m" and "l" and variables "theta" and "phi".
  //NB: in the calculator, pi = 3.14, theta = 180.
  cmplx_const sph_arm( const int m, const int l, const double theta, const double phi )
   {
    if( abs( m ) > l || l < 0 ) throw std::runtime_error( "\033[31mQuantum numbers l and m should satisfy the relation: l >= abs(m) >= 0\033[0m" );
    else
     {
      const double sign_1 = pow( -1, ( m + abs( m ) ) * 0.5 );
      const double dividedFactorial = [ l, m ]
       {
        double result = 1; 
        const int multmin = l - abs( m ) + 1; 
        const int multmax = l + abs( m ); 
        for( int currval = multmin; currval <= multmax ; ++currval ) 
         {
          result *= currval; 
         }; 
        return result;
       }(); 
      const double sign_2 = reciprocalPi * sqrt( ( 2*l + 1 ) / dividedFactorial );
      const double pol = Leg_func( abs( m ), l, cos( theta ) );
      cmplx_const result ( sign_1 * sign_2 * pol * cos( m*( phi + M_PI ) ), sign_1 * sign_2 * pol * sin( m*( phi + M_PI ) ) );
    
      return result;
     }
   }

  //============================================
  //     "parsed_f" function definition
  //============================================
  
  //Function f(theta,phi) obtained with parsing:
  const double parsed_f( const std::string expr, double theta, double phi )
   {
    symbol_table_t symbol_table;
    symbol_table.add_variable( "th", theta );
    symbol_table.add_variable( "phi",phi );
  
    expression_t foo;
    foo.register_symbol_table( symbol_table );
  
    parser_t parser;
    if ( !parser.compile( expr, foo ) )
     {
      throw std::runtime_error( "\033[31mError in the inserted expression!\033[0m" );
     }
    
    return foo.value();
   }
  
  //============================================
  //     "f_theta_phi" function definition
  //============================================
  
  //This function defines: f(theta,phi) * conjugate( sph_arm(m,l,theta,phi) ) * sin(theta).
  const double f_theta_phi_real( const std::string expr, const int m, const int l, const double theta, const double phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * sph_arm( m, l, theta, phi ).real();
   }
  
  const double f_theta_phi_imag( const std::string expr, const int m, const int l, const double theta, const double phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * conj( sph_arm( m, l, theta, phi ) ).imag();
   }
  
  //============================================
  //     "f_m_l" function definition
  //============================================
  
  //This function returns the final f_m_l coefficients.
  cmplx_const f_m_l( const std::string expr, const int m, const int l )
   {  
    const double real_part = integral( &f_theta_phi_real, expr, m, l );
    const double imag_part = integral( &f_theta_phi_imag, expr, m, l );
    coefficient.real( real_part );
    coefficient.imag( imag_part );
  
    return coefficient;
   }

  //============================================
  //     "displayer" function definition
  //============================================
  
  //Function used to display the final result of the main program.
  //NB: used in main program only.
  void displayer( std::string& equation, int& m, int& l )
   {
    try 
     {
      std::cout << "f(" << m << "," << l << ") = "
                << osm::feat( osm::col, "green" ) << f_m_l( equation, m, l ).real() << osm::reset( "color" ) << " + "
                << osm::feat( osm::col, "green" ) << f_m_l( equation, m, l ).imag() << osm::reset( "color" )
                << osm::feat( osm::col, "lt blue" ) << "i" << osm::reset( "color" ) << std::endl;
     }
    catch( std::runtime_error const & exception )
     {
      std::cerr << osm::feat( osm::sty, "italics" ) << osm::feat( osm::col, "red" ) << "not computable!" 
                << osm::reset( "all" ) << std::endl << std::endl << exception.what() << std::endl;
     }
   }
 }