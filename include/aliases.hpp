#ifndef ALIASES_HPP
#define ALIASES_HPP

//STD headers
#include <string>
#include <complex>

//Extra headers
#include <exprtk.hpp>

namespace SphArmFuncDev
 {
  //============================================
  //     Aliases for normal types
  //============================================
  using d_const = const double;
  using i_const = const int;
  using ui_const = const unsigned int;
  using c_const = const char;
  
  //============================================
  //     Aliases for STD types
  //============================================
  using s_const = const std::string;
  using cmplx = std::complex<double>;
  using cmplx_const = const std::complex<double>;
  using two_param_func = std::function<d_const( int, double )>;
  using four_param_func = std::function<d_const( std::string, int, int, double, double )>;
  
  //============================================
  //     Typedefs for exprtk library
  //============================================
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double>     expression_t;
  typedef exprtk::parser<double>             parser_t;
 }

#endif