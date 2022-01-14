#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//STD headers
#include <complex>
#include <string>

//Extra headers
#include <exprtk.hpp>

//My headers
#include "aliases.hpp"

namespace safd
 {
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
 }
  
#endif