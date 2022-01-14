//STD headers
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <array>
#include <string>

//My headers
#include "../include/utils.hpp"

namespace safd
 {
  //============================================
  //     Global variables definition
  //============================================
  
  //Derivative constants:
  d_const STEP_SIZE = 2 * cbrt( __DBL_EPSILON__ );
  
  //Integral constants (x):
  d_const x_in = 0;
  d_const x_fin = M_PI;
  d_const h_x = 0.07;
  
  //Integral constants (y):
  d_const y_in = 0;
  d_const y_fin = M_PI*2;
  d_const h_y = 0.15;
  
  //============================================
  //     "n_derivative" function definition
  //============================================
  
  //Function used to calculate the "n"-th derivative of a function "f" in a point "x_0", which depends on an index "a". 
  //NB: Works well until n = 3/4. 
  d_const n_derivative( d_const ( *f )( int, double ), d_const x_0, i_const a, i_const n )
   {
    if( n == 0 ) return f( a, x_0 );
    else if( n < 0 ) throw std::runtime_error( "Derivative cannot be calculated for order less than 0!" );
    else 
     {
      double h;
      if ( n < 4 && n > 0 ) h = STEP_SIZE * x_0;
      else h = n; //Condition for Legendre associated functions.
  
      d_const x_1 = x_0 - h;
      d_const x_2 = x_0 + h;
      d_const first_term = n_derivative( f, x_2, a, n - 1 );
      d_const second_term = n_derivative( f, x_1, a, n - 1);
  
      return ( first_term - second_term ) / ( x_2 - x_1 );
     }
   }
  
  //============================================
  //     "round" function definition
  //============================================
  
  //Function used to round the value of a double variable.
  //NB: used for testing only.
  d_const round_var( d_const val )
   {
    if( val < 0 ) return ceil( val - 0.5 );
    else return floor( val + 0.5 );
   }
  
  //============================================
  //     "factorial" function definition
  //============================================
  
  //Function to find factorial of a variable "n".
  ui_const factorial( ui_const n  )
   {
    if (n == 0) return 1;
    else return n * factorial( n - 1 );
  }
  
  //============================================
  //     "IsInBounds" function definition
  //============================================
  
  //Function to check if a "value" is in bound [low, high].
  //NB: used for testing only.
  template <typename T>
  bool IsInBounds( const T value, const T low, const T high )
   {
    return !( value < low ) && ( value < high );
   } 
  
  template bool IsInBounds <double> ( d_const value, d_const low, d_const high );
  
  //============================================
  //     "integral" function definition
  //============================================
  
  //Function used to integrate a function f(x,y), depending on two indexes m and l, in x = theta and y = phi.
  d_const integral( d_const ( *f )( std::string, int, int, double, double ), s_const expr, i_const m, i_const l )
   {
    double res;
    std::array< std::array<double, 50>, 50> tab; //Stores the table.
    std::array<double, 50> ax;   //Stores the integral wrt y
  
    //Calculating the number of points in x and y integral:
    d_const nx = ( x_fin - x_in ) / h_x + 1;
    d_const ny = ( y_fin - y_in ) / h_y + 1;
  
    //Calculating the values of the table:
    for( int i = 0; i < nx; ++i ) 
     {
      for ( int j = 0; j < ny; ++j ) 
       {
        tab[i][j] = f( expr, m, l, x_in + i * h_x, y_in + j * h_y );
       }
     }
  
    //Calculating the integral value wrt y at each point for x:
    for( int i = 0; i < nx; ++i ) 
     {
      ax[i] = 0;
      for ( int j = 0; j < ny; ++j ) 
       {
        if ( j == 0 || j == ny - 1 ) ax[i] += tab[i][j];
        else if ( j % 2 == 0 ) ax[i] += 2 * tab[i][j];
        else ax[i] += 4 * tab[i][j];
       }
      ax[i] *= ( h_y / 3 );
     }
    res = 0;
  
    //Calculating the final integral value using the integral obtained in the above step:
    for ( int i = 0; i < nx; ++i ) 
     {
      if ( i == 0 || i == nx - 1 ) res += ax[i];
      else if ( i % 2 == 0 ) res += 2 * ax[i];
      else res += 4 * ax[i];
     }
    res *= ( h_x / 3 );
  
    return res;
   } 
 }