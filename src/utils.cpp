//My headers
#include "../include/utils.hpp"

//STD headers
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <array>
#include <string>
#include <functional>
#include <limits>
#include <vector>

namespace safd
 {
  //============================================
  //     "h" function definition
  //============================================
  
  //Function used to return the derivative step-size.
  double h( const int& n, const double& x_0 )
   {
    if ( n < 4 && n > 0 ) return STEP_SIZE * x_0;
    else return n * 0.09;
   }
  
  //============================================
  //     "n_derivative" function definition
  //============================================
  
  //Function used to calculate the "n"-th derivative of a function "f" in a point "x_0", which depends on an index "a". 
  //NB: Works well until n = 3/4. 
  double n_derivative( const two_param_func& f, const double& x_0, const int& a, const int& n )
   {
    if( n == 0 ) return f( a, x_0 );
    else if( n < 0 )
     {
      throw std::runtime_error( "\033[31mDerivative cannot be calculated for order less than 0!\033[0m" );
     }
    else 
     {
      if ( fabs( x_0 ) >= __DBL_MIN__ && std::isfinite( x_0 ) )
       {
        const double x_1 = x_0 - h( n, x_0 );
        const double x_2 = x_0 + h( n, x_0 );
        const double first_term = n_derivative( f, x_2, a, n - 1 );
        const double second_term = n_derivative( f, x_1, a, n - 1);
    
        return ( first_term - second_term ) / ( x_2 - x_1 );
       }
      else 
       {
        throw std::runtime_error( "\033[31mDerivative cannot be calculated in this x_0 value (too much small or big)!\033[0m" );
       }
     }
   }
  
  //============================================
  //     "integral" function definition
  //============================================
  
  //Function used to integrate a function f(x,y), depending on two indexes m and l, in x = theta and y = phi.
  double integral( const four_param_func& f, const std::string& expr, const int& m, const int& l )
   {
    //Calculating the number of points in x and y integral:
    const double nx = ( x_fin - x_in ) / h_x + 1;
    const double ny = ( y_fin - y_in ) / h_y + 1;

    //Integral variables:
    double res{};
    std::vector<std::vector<double>> tab( std::ceil( nx ), std::vector<double>( std::ceil( ny ), 0.0 ) );
    std::vector<double> ax( std::ceil( nx ), 0.0 );
  
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

  //============================================
  //     "initializer" function definition
  //============================================
  
  //Function used to initialize values of main program input.
  //NB: used in main program only.
  void initializer( std::string& equation, int& m, int& l)
   {
    std::cout << "Enter the f(th,phi) equation shape (avoid backspaces): ";
    std::cin >> equation;
    std::cout << "Enter the value of m: ";
    std::cin >> m;
    std::cout << "Enter the value of l: ";
    std::cin >> l;
    std::cout << "\n";
   }

  //============================================
  //     "letter" function definition
  //============================================
  
  //Function to modify an input and return it.
  //NB: used in main program only.
  char abort_this( char letter )
   {
    std::cout << "Compute another coefficient (enter \"y\" or \"n\")?: ";
    std::cin >> letter;
    std::cout << "\n";
    return letter;
   }
 }