//============================================
//     Preprocessor directives
//============================================
#ifndef UTILS_HPP
#define UTILS_HPP

//============================================
//     Headers
//============================================

//STD headers
#include <string>
#include <functional>
#include <stdexcept>
#include <cmath>

namespace safd
 {
  //============================================
  //     Type aliases definition
  //============================================
  using two_param_func = std::function<double( const int&, const double& )>;
  using four_param_func = std::function<double( const std::string&, const int&, const int&, const double&, const double& )>;

  //============================================
  //     Global variables declaration
  //============================================

  //Constants:
  inline const double STEP_SIZE = 2 * cbrt( __DBL_EPSILON__ );
  inline constexpr double x_in = 0;
  inline constexpr double x_fin = M_PI;
  inline constexpr double h_x = 0.07;
  inline constexpr double y_in = 0;
  inline constexpr double y_fin = M_PI*2;
  inline constexpr double h_y = 0.15;
  
  //============================================
  //     Functions declaration
  //============================================
  
  //N-th derivative function:
  extern double n_derivative( const two_param_func& f, const double& x_0, const int& a, const int& n );
 
  //Step-size function:
  extern double h( const int& n, const double& x_0 );
  
  //Function to calculate the 2-dim integral:
  extern double integral( const four_param_func& f, const std::string& expr, const int& m, const int& l );

  //Function used to initialize values of main program input:
  extern void initializer( std::string& equation, int& m, int& l);

  //Function to modify an input and return it:
  extern char abort_this( char letter );
 }
  
#endif