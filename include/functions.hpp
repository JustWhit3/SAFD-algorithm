#ifndef FUNCTIONS_H
#define FUNCTIONS_h

//============================================
//     Utils objects declarations
//============================================

//N-th derivative function:
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n );


//============================================
//     Functions declarations
//============================================

//Legendre polynomials function:
double Leg_pol( int a, double x );

#endif