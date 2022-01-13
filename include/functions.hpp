#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <complex>
#include <string>

//============================================
//     Aliases definition
//============================================
using cmplx = std::complex<double>;

//============================================
//     Functions declaration
//============================================

//Legendre polynomials function:
extern double Leg_pol( int a, double x );

//Legendre associated function function:
extern double Leg_func( int b, int a, double x );

//Spherical armonics function:
extern cmplx sph_arm( int m, int l, double theta, double phi );

//Parsed function:
extern double parsed_f( const std::string expr, double theta, double phi );

//f(theta,phi) final function (which will be integrated):
extern cmplx f_theta_phi( std::string expr, int m, int l, double theta, double phi );

#endif