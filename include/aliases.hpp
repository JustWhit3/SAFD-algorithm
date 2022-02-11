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
  //     Aliases for STD types
  //============================================
  using cmplx = std::complex<double>;
  using cmplx_const = const std::complex<double>;
  using two_param_func = std::function<const double( int, double )>;
  using four_param_func = std::function<const double( std::string, int, int, double, double )>;
  
  //============================================
  //     Typedefs for exprtk library
  //============================================
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double>     expression_t;
  typedef exprtk::parser<double>             parser_t;
 }

#endif