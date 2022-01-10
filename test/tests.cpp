#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include "../include/functions.hpp"

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
  a = round( a * 100.0 ) / 100.0;

  CHECK_EQ( a, 3.46 );
 }

//============================================
//     "Leg_pol" function testing
//============================================
TEST_CASE( "Testing the Leg_pol function " )
 {
  CHECK_EQ( Leg_pol( 2, 0.3 ), -0.365 );
  CHECK_EQ( Leg_pol( 0, 0.6 ), 1 );
  CHECK_EQ( Leg_pol( 1, 0.6 ), 0.6 );
  CHECK_THROWS_AS( Leg_pol( -2, 3 ), runtime_error );
 }

//============================================
//     "Leg_func" function testing
//============================================
TEST_CASE( "Testing the Leg_func function " )
 {
  //b = 0:
  CHECK_EQ( Leg_func( 0, 0, 0.3 ), 1 );
  CHECK_EQ( Leg_func( 0, 1, 0.3 ), 0.3 );
  CHECK_EQ( Leg_func( 0, 2, 0.3 ), -0.365 );

  //b > 0:
  CHECK_EQ( round( Leg_func( 1, 1, 0.5 ) * 100.0 ) / 100.0, -0.87 );
  CHECK_EQ( round( Leg_func( 1, 2, -0.3 ) * 100.0 ) / 100.0, 0.86 );
  CHECK_EQ( round( Leg_func( 3, 4, 0.9 ) * 100.0 ) / 100.0, -7.83 );

  //Exceptions:
  CHECK_THROWS_AS( Leg_func( 1, 2, -3 ), runtime_error );
  CHECK_THROWS_AS( Leg_func( 1, 2, 3 ), runtime_error );
  CHECK_THROWS_AS( Leg_func( 3, 2, 0.2 ), runtime_error );
  CHECK_THROWS_AS( Leg_func( -2, 1, 0.2 ), runtime_error );
  CHECK_THROWS_AS( Leg_func( -2, -3, 0.2 ), runtime_error );
 }