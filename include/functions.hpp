#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//STD headers
#include <complex>
#include <string>
#include <cmath>
#include <functional>
#include <exprtk.hpp>

namespace safd
 {
  //============================================
  //     Type aliases definition
  //============================================
  using two_param_func = std::function<double( const int&, const double& )>;
  using four_param_func = std::function<double( const std::string&, const int&, const int&, const double&, const double& )>;

  //============================================
  //     Global variables declaration
  //============================================
  inline const double reciprocalPi = sqrt(1 / ( M_PI*4 ) );

  //============================================
  //     Functions declaration
  //============================================
  
  //Legendre polynomials function:
  extern double Leg_pol( const int& a, const double& x );
  
  //Legendre associated function function:
  extern double Leg_func( const int& b, const int& a, const double& x );
  
  //Spherical harmonics function:
  extern std::complex<double> sph_arm( const int& m, const int& l, const double& theta, const double& phi );

  //Parsed function:
  extern double parsed_f( const std::string& expr, double theta, double phi );
  
  //f(theta,phi) final function (which will be integrated), real part:
  extern double f_theta_phi_real( const std::string& expr, const int& m, const int& l, const double& theta, const double& phi );

  //f(theta,phi) final function (which will be integrated), imaginary part:
  extern double f_theta_phi_imag( const std::string& expr, const int& m, const int& l, const double& theta, const double& phi );
  
  //f_m_l coefficients representation:
  extern std::complex<double> f_m_l( const std::string& expr, const int& m, const int& l );

  //Function used to display the final result of the main program:
  extern void displayer( const std::string& equation, const int& m, const int& l );
 }
  
#endif