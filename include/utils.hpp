#ifndef UTILS_HPP
#define UTILS_HPP

//============================================
//     Functions declaration
//============================================

//N-th derivative function:
double n_derivative( double ( *f )( int, double ), double x_0, int a, int n );

//Function to round double variables:
double round_var( double val );

//Function to find factorial of a variable:
unsigned int factorial( unsigned int n );

#endif