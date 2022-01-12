#ifndef UTILS_HPP
#define UTILS_HPP

//============================================
//     Global variables declaration
//============================================
extern const double STEP_SIZE;
extern const double x_0_int, x_1_int, x_2_int, x_3_int, x_4_int, h_x;
extern const double y_0_int, y_1_int, y_2_int, y_3_int, x_4_int, h_y;

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
extern double integral( double ( *f )( int, int, double, double ), int m, int l );

//============================================
//     Template functions declaration
//============================================

//Function to check if a variable is in a bound:
template <typename T>
extern bool IsInBounds( const T& value, const T& low, const T& high );

#endif