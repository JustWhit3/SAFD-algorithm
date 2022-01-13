#include <iostream>
#include <complex>

#include "../include/functions.hpp"
#include "../include/utils.hpp"

using namespace std;

int main()
 {
  cout << parsed_f( "cos( th ) - sin( phi )", M_PI/6, M_PI/4 ) << endl;
  cout << sin( M_PI/6 ) << endl;
  cout << sph_arm( 1, 1, M_PI/6, M_PI/4 ).imag() <<endl;
 }
 