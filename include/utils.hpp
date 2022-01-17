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
  extern d_const STEP_SIZE;
  extern d_const x_in, x_fin, h_x;
  extern d_const y_in, y_fin, y_x;
  extern double h;
  extern double res;
  extern std::array< std::array<double, 50>, 50> tab;
  extern std::array<double, 50> ax;
  
  //============================================
  //     Functions declaration
  //============================================
  //N-th derivative function:
  extern d_const n_derivative( two_param_func f, d_const x_0, i_const a, i_const n );
  
  //Function to round double variables:
  extern d_const round_var( d_const val );
  
  //Function to find factorial of a variable:
  extern ui_const factorial( ui_const n );
  
  //Function to calculate the 2-dim integral:
  extern d_const integral( four_param_func f, s_const expr, i_const m, i_const l );

  //Function used to initialize values of main program input:
  extern void initializer( std::string& equation, int& m, int& l);

  //Function to modify an input and return it:
  extern c_const abort_this( char letter );

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