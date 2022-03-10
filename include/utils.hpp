#ifndef UTILS_HPP
#define UTILS_HPP

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
  using two_param_func = std::function<const double( int, double )>;
  using four_param_func = std::function<const double( std::string, int, int, double, double )>;

  //============================================
  //     Global variables declaration
  //============================================

  //Constants:
  inline constexpr double STEP_SIZE = 2 * cbrt( __DBL_EPSILON__ );
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
  extern const double n_derivative( two_param_func f, const double x_0, const int a, const int n );
 
  //Step-size function:
  extern const double h( const int n, const double x_0 );
  
  //Function to calculate the 2-dim integral:
  extern const double integral( four_param_func f, const std::string expr, const int m, const int l );

  //Function used to initialize values of main program input:
  extern void initializer( std::string& equation, int& m, int& l);

  //Function to modify an input and return it:
  extern const char abort_this( char letter );
 }
  
#endif