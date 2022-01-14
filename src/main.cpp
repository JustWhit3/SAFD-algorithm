//STD headers
#include <iostream>
#include <complex>

//My headers
#include "../include/functions.hpp"

//Namespaces
using namespace std;
using namespace safd;

//============================================
//     "main" function
//============================================
int main()
 {
  cout << f_m_l( "pow( cos( th ), 3 )", 0, 1 ).real() << endl;
 }
 