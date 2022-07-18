//============================================
//     Headers
//============================================

//My headers
#include "../include/utils.hpp"
#include "../include/functions.hpp"

//Extra headers
#include <osmanip/manipulators/colsty.hpp>
#include <osmanip/graphics/canvas.hpp>
#include <osmanip/graphics/plot_2D.hpp>
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
  //     "Leg_pol" function definition
  //============================================
  /**
   * @brief Function used to calculate Legendre polynomials with index "a" and variable "x".  
   * 
   * @param a Index of Legendre polynomials.
   * @param x The variable of the polynomials.
   * @return double The Legendre polynomial value in point x for an index a.
   */
  double Leg_pol( const int& a, const double& x ) 
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
  /**
   * @brief Function used to calculate Legendre associated functions with indexes "a" and "b" and variable "x". NB: works well until m = l and | m - l | = 1.
   * 
   * @param b Index of Legendre function.
   * @param a Index of Legendre function.
   * @param x Variable value of Legendre function.
   * @return double Legendre function for indexes a and b in a point x.
   */
  double Leg_func( const int& b, const int& a, const double& x )
   {
    if( x < -1 || x > 1 ) throw std::runtime_error( "\033[31mLegendre associated functions variable should lie in interval [-1,1]!\033[0m" );
    else
     {
      if( a < abs( b ) ) throw std::runtime_error( "\033[31mLegendre associated function indexes a and b should satisfy the relation: a >= b >= 0\033[0m" );
      else
       {
        const double first_term = pow( ( 1 - (x * x) ), static_cast<double>( b ) * 0.5 );
        const double second_term = n_derivative( Leg_pol, x, a, b );
    
        return pow( -1, b ) * first_term * second_term;
       }
     }
   }
  
  //============================================
  //     "sph_arm" function definition
  //============================================
  /**
   * @brief Function used to calculate spherical harmonics functions with indexes "m" and "l" and variables "theta" and "phi". NB: in the calculator, pi = 3.14, theta = 180.
   * 
   * @param m Function index.
   * @param l Function index.
   * @param theta Angular variable.
   * @param phi Angular variable.
   * @return std::complex<double> Spherical harmonics value for m and l coefficients in theta and phi values.
   */
  std::complex<double> sph_arm( const int& m, const int& l, const double& theta, const double& phi )
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
      std::complex<double> result ( sign_1 * sign_2 * pol * cos( m*( phi + M_PI ) ), sign_1 * sign_2 * pol * sin( m*( phi + M_PI ) ) );
    
      return result;
     }
   }

  //============================================
  //     "parsed_f" function definition
  //============================================
  /**
   * @brief Function f(theta,phi) obtained with parsing.
   * 
   * @param expr Expression to be parsed into a function.
   * @param theta Variable of the function.
   * @param phi Variable of the function.
   * @return double Parsed function.
   */
  double parsed_f( const std::string& expr, double theta, double phi )
   {
    exprtk::rtl::io::file::package<double> fileio_package;

    exprtk::symbol_table<double> symbol_table;
    symbol_table.add_variable( "th", theta );
    symbol_table.add_variable( "phi", phi );
  
    exprtk::expression<double> expression;
    expression.register_symbol_table( symbol_table );
  
    exprtk::parser<double> parser;
    if ( !parser.compile( expr, expression ) )
     {
      throw std::runtime_error( "\033[31mError in the inserted expression!\033[0m" );
     }
    
    return expression.value();
   }
  
  //============================================
  //     "f_theta_phi" function definition
  //============================================
  /**
   * @brief This function defines: f(theta,phi) * conjugate( sph_arm(m,l,theta,phi) ) * sin(theta).
   * 
   * @param expr Expression to be parsed.
   * @param m Coefficient of the function.
   * @param l Coefficient of the function.
   * @param theta Angular variable of the function.
   * @param phi Angular variable of the function.
   * @return double Expression value.
   */
  double f_theta_phi_real( const std::string& expr, const int& m, const int& l, const double& theta, const double& phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * sph_arm( m, l, theta, phi ).real();
   }
  
  double f_theta_phi_imag( const std::string& expr, const int& m, const int& l, const double& theta, const double& phi )
   { 
    return parsed_f( expr, theta, phi ) * sin( theta ) * conj( sph_arm( m, l, theta, phi ) ).imag();
   }
  
  //============================================
  //     "f_m_l" function definition
  //============================================
  /**
   * @brief This function returns the final f_m_l coefficients.
   * 
   * @param expr Expression to be parsed.
   * @param m Coefficient of the expression.
   * @param l Coefficient of the expression.
   * @return std::complex<double> Coefficient f_m_l value.
   */
  std::complex<double> f_m_l( const std::string& expr, const int& m, const int& l )
   {  
    const double real_part = integral( f_theta_phi_real, expr, m, l );
    const double imag_part = integral( f_theta_phi_imag, expr, m, l );
    std::complex<double> coefficient;
    coefficient.real( real_part );
    coefficient.imag( imag_part );
  
    return coefficient;
   }

  //============================================
  //     "plotter" function definition
  //============================================
  /**
   * @brief Function used to plot the user-inserted function, which development coefficients are computed.
   * 
   * @param func The expression representing the function.
   */
  void plotter( const std::string& func )
   {
    bool is_th = func.find( "th" ) != std::string::npos && func.find( "phi" ) == std::string::npos;
    bool is_phi = func.find( "phi" ) != std::string::npos && func.find( "th" ) == std::string::npos;
    
    if ( is_th || is_phi )
     {
      std::cout << "\n";
      
      // Preparing the canvas     
      osm::Plot2DCanvas plot_2d_canvas( 60, 20 );
      plot_2d_canvas.setBackground( ' ', osm::feat( osm::col, "bg white" ) );
      plot_2d_canvas.enableFrame( true );
      plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
      plot_2d_canvas.enableFrame( true );
      plot_2d_canvas.setFrame( osm::FrameStyle::BOX, osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "black" ) );
      plot_2d_canvas.setScale( 1/3.14, 0.2 );
  
      //Functions settings
      std::string func_th_style = osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "bd red" );
      std::string func_phi_style = osm::feat( osm::col, "bg white" ) + osm::feat( osm::col, "bd blue" );
      char func_th_marker = 'X';
      char func_phi_marker = 'O';
      std::function <double( double )> func_th = [ &func ]( double th ) -> double{ return parsed_f( func, th, M_PI ); };
      std::function <double( double )> func_phi = [ &func ]( double phi ) -> double{ return parsed_f( func, M_PI, phi ); };
  
      //Drawing the functions
      for( float i = 0; i < 70; i++ )
       {
        plot_2d_canvas.setOffset( i/3.14/1.8, -2 );
        plot_2d_canvas.clear();
        if ( is_th ) plot_2d_canvas.draw( func_th, func_th_marker, func_th_style );
        else if ( is_phi ) plot_2d_canvas.draw( func_phi, func_phi_marker, func_phi_style );
        plot_2d_canvas.refresh();
       }
     }
   }

  //============================================
  //     "displayer" function definition
  //============================================
  /**
   * @brief Function used to display the final result of the main program. NB: used in main program only.
   * 
   * @param equation Mathematical equation.
   * @param m Equation coefficient.
   * @param l Equation coefficient.
   */
  void displayer( const std::string& equation, const int& m, const int& l )
   {
    try 
     {
      std::cout << "f(" << m << "," << l << ") = "
                << osm::feat( osm::col, "green" ) << f_m_l( equation, m, l ).real() << osm::feat( osm::rst, "color" ) << " + "
                << osm::feat( osm::col, "green" ) << f_m_l( equation, m, l ).imag() << osm::feat( osm::rst, "color" )
                << osm::feat( osm::col, "lt blue" ) << "i" << osm::feat( osm::rst, "color" ) << "\n";
     }
    catch( std::runtime_error const & exception )
     {
      std::cerr << osm::feat( osm::sty, "italics" ) << osm::feat( osm::col, "red" ) << "not computable!" 
                << osm::feat( osm::rst, "all" ) << "\n\n" << exception.what() << "\n";
     }
   }
 }