#ifndef UTILS_HPP
#define UTILS_HPP

//STD headers
#include <string>

//My headers
#include "aliases.hpp"

namespace safd
 {
  //============================================
  //     Global variables declaration
  //============================================
  extern d_const STEP_SIZE;
  extern d_const x_in, x_fin, h_x;
  extern d_const y_in, y_fin, y_x;
  
  //============================================
  //     Functions declaration
  //============================================
  
  //N-th derivative function:
  extern d_const n_derivative( d_const ( *f )( int, double ), d_const x_0, i_const a, i_const n );
  
  //Function to round double variables:
  extern d_const round_var( d_const val );
  
  //Function to find factorial of a variable:
  extern ui_const factorial( ui_const n );
  
  //Function to calculate the 2-dim integral:
  extern d_const integral( d_const ( *f )( std::string, int, int, double, double ), s_const expr, i_const m, i_const l );
  
  //============================================
  //     Template functions declaration
  //============================================
  
  //Function to check if a variable is in a bound:
  template <typename T>
  extern bool IsInBounds( const T value, const T low, const T high );
 }
  
#endif