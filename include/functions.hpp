#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//STD headers
#include <complex>
#include <string>
#include <cmath>

//Extra headers
#include <exprtk.hpp>

namespace SphArmFuncDev
 {
  //============================================
  //     Type aliases definition
  //============================================
  using cmplx = std::complex<double>;
  using cmplx_const = const std::complex<double>;
  using two_param_func = std::function<const double( int, double )>;
  using four_param_func = std::function<const double( std::string, int, int, double, double )>;

  //============================================
  //     Global variables declaration
  //============================================
  extern cmplx coefficient;
  inline constexpr double reciprocalPi = sqrt(1 / (M_PI*4));

  //============================================
  //     Functions declaration
  //============================================
  
  //Legendre polynomials function:
  extern const double Leg_pol( const int a, const double x );
  
  //Legendre associated function function:
  extern const double Leg_func( const int b, const int a, const double x );
  
  //Spherical harmonics function:
  extern cmplx_const sph_arm( const int m, const int l, const double theta, const double phi );
  
  //Parsed function:
  extern const double parsed_f( const std::string expr, double theta, double phi );
  
  //f(theta,phi) final function (which will be integrated), real part:
  extern const double f_theta_phi_real( const std::string expr, const int m, const int l, const double theta, const double phi );

  //f(theta,phi) final function (which will be integrated), imaginary part:
  extern const double f_theta_phi_imag( const std::string expr, const int m, const int l, const double theta, const double phi );
  
  //f_m_l coefficients representation:
  extern cmplx_const f_m_l( const std::string expr, const int m, const int l );

  //Function used to display the final result of the main program:
  extern void displayer( std::string& equation, int& m, int& l );
 }
  
#endif