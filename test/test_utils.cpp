#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include <stdexcept>

#include "../include/functions.hpp"
#include "../include/utils.hpp"

using namespace std;

//============================================
//     "n_derivative" function testing
//============================================
TEST_CASE( "Testing the n_derivative function " )
 {
  //1-derivative:
  CHECK_EQ( n_derivative( Leg_pol, 1, 1, 1 ), 1);
  CHECK_EQ( n_derivative( Leg_pol, 1, 0, 1 ), 0);

  //n-th derivative:
  CHECK_EQ( n_derivative( Leg_pol, 1, 3, 3 ), 15 );
  CHECK_EQ( n_derivative( Leg_pol, 2, 3, 2 ), 30 );
  CHECK_EQ( n_derivative( Leg_pol, -2, 3, 2 ), -30 );
  CHECK_EQ( n_derivative( Leg_pol, 0.3, 3, 2 ), 4.5 );

  //Exceptions:
  CHECK_THROWS_AS( n_derivative( Leg_pol, 1, 1, -1 ), runtime_error );
 }

//============================================
//     "round" function testing
//============================================
TEST_CASE( "Testing the round function " )
 {
  double a = 3.456234;
  a = round_var( a * 100.0 ) / 100.0;

  CHECK_EQ( a, 3.46 );
 }

//============================================
//     "factorial" function testing
//============================================
TEST_CASE( "Testing the factorial function " )
 {
  CHECK_EQ( factorial( 0 ), 1 );
  CHECK_EQ( factorial( 1 ), 1 );
  CHECK_EQ( factorial( 3 ), 6 );
  CHECK_EQ( factorial( 5 ), 120 );
 }