#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

//============================================
//     Global variables declaration
//============================================
extern const double STEP_SIZE;
extern const double x_in, x_fin, h_x;
extern const double y_in, y_fin, y_x;

//============================================
//     Functions declaration
//============================================

//N-th derivative function:
extern double n_derivative( double ( *f )( int, double ), double x_0, int a, int n );

//Function to round double variables:
extern double round_var( double val );

//Function to find factorial of a variable:
extern unsigned int factorial( unsigned int n );

//Function to calculate the 2-dim integral:
extern double integral( double ( *f )( std::string, int, int, double, double ), std::string expr, int m, int l );

//============================================
//     Template functions declaration
//============================================

//Function to check if a variable is in a bound:
template <typename T>
extern bool IsInBounds( const T& value, const T& low, const T& high );

#endif