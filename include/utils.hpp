#ifndef UTILS_HPP
#define UTILS_HPP

//STD headers
#include <string>
#include <functional>
#include <stdexcept>

//My headers
#include "aliases.hpp"

namespace SphArmFuncDev
 {
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

  //Other variables:
  extern double res;
  extern std::array< std::array<double, 50>, 50> tab;
  extern std::array<double, 50> ax;
  
  //============================================
  //     Functions declaration
  //============================================
  //N-th derivative function:
  extern const double n_derivative( two_param_func f, const double x_0, const int a, const int n );
 
  //Step-size function:
  extern const double h( const int n, const double x_0 );
  
  //Function to round double variables:
  extern const double round_var( const double val );
  
  //Function to calculate the 2-dim integral:
  extern const double integral( four_param_func f, const std::string expr, const int m, const int l );

  //Function used to initialize values of main program input:
  extern void initializer( std::string& equation, int& m, int& l);

  //Function to modify an input and return it:
  extern const char abort_this( char letter );

  //============================================
  //     Template functions declaration
  //============================================
  
  //Function to check if a variable is in a bound:
  template <typename T>
  extern bool IsInBounds( const T value, const T low, const T high );

  //Function used to return customized runtime error.
  template <typename T>
  std::runtime_error runtime_thrower( T phrase );
 }
  
#endif