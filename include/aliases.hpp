#ifndef ALIASES_HPP
#define ALIASES_HPP

//STD headers
#include <string>
#include <complex>

//Extra headers
#include <exprtk.hpp>

namespace safd
 {
  //============================================
  //     Aliases for normal types
  //============================================
  using d_const = const double;
  using i_const = const int;
  using ui_const = const unsigned int;
  
  //============================================
  //     Aliases for STD types
  //============================================
  using s_const = const std::string;
  using cmplx = std::complex<double>;
  using cmplx_const = const std::complex<double>;
  
  //============================================
  //     Typedefs for exprtk library
  //============================================
  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double>     expression_t;
  typedef exprtk::parser<double>             parser_t;
 }

#endif