#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//STD headers
#include <complex>
#include <string>

//Extra headers
#include <exprtk.hpp>

//My headers
#include "aliases.hpp"

namespace SphArmFuncDev
 {
  //============================================
  //     Global variables declaration
  //============================================
  extern symbol_table_t symbol_table;
  extern expression_t foo;
  extern parser_t parser;
  extern exprtk::rtl::io::file::package<double> fileio_package;
  extern cmplx coefficient;

  //============================================
  //     Functions declaration
  //============================================
  
  //Legendre polynomials function:
  extern d_const Leg_pol( i_const a, d_const x );
  
  //Legendre associated function function:
  extern d_const Leg_func( i_const b, i_const a, d_const x );
  
  //Spherical armonics function:
  extern cmplx_const sph_arm( i_const m, i_const l, d_const theta, d_const phi );
  
  //Parsed function:
  extern d_const parsed_f( s_const expr, double theta, double phi );
  
  //f(theta,phi) final function (which will be integrated), real part:
  extern d_const f_theta_phi_real( s_const expr, i_const m, i_const l, d_const theta, d_const phi );

  //f(theta,phi) final function (which will be integrated), imaginary part:
  extern d_const f_theta_phi_imag( s_const expr, i_const m, i_const l, d_const theta, d_const phi );
  
  //f_m_l coefficients representation:
  extern cmplx_const f_m_l( s_const expr, i_const m, i_const l );

  //Function used to display the final result of the main program:
  extern void displayer( std::string& equation, int& m, int& l );
 }
  
#endif