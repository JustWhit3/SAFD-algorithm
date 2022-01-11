#ifndef UTILS_HPP
#define UTILS_HPP

//============================================
//     Global variables declaration
//============================================
extern const double STEP_SIZE;

//============================================
//     Functions declaration
//============================================

//N-th derivative function:
extern double n_derivative( double ( *f )( int, double ), double x_0, int a, int n );

//Function to round double variables:
extern double round_var( double val );

//Function to find factorial of a variable:
extern unsigned int factorial( unsigned int n );

//Function to check if a variable is in a bound:
template <typename T>
extern bool IsInBounds( const T& value, const T& low, const T& high );

#endif