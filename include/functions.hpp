#ifndef FUNCTIONS_H
#define FUNCTIONS_h

//============================================
//     Utils objects declarations
//============================================

//N-th derivative function:
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n );

//Function to round double variables:
double round( double val );

//============================================
//     Functions declarations
//============================================

//Legendre polynomials function:
double Leg_pol( int a, double x );

//Legendre associated function function:
double Leg_func( int b, int a, double x );

#endif