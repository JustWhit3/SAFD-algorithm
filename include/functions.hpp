#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <complex>

//============================================
//     Aliases definition
//============================================
using cmplx = std::complex<double>;

//============================================
//     Functions declaration
//============================================

//Legendre polynomials function:
double Leg_pol( int a, double x );

//Legendre associated function function:
double Leg_func( int b, int a, double x );

//Spherical armonics function:
std::complex<double> sph_arm( int m, int l, double theta, double phi );

#endif