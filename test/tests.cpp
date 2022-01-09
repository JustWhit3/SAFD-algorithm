#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include "../include/functions.hpp"

using namespace std;

//============================================
//     "Leg_pol" function testing
//============================================
TEST_CASE( "Testing the Leg_pol function " )
 {
  CHECK_EQ( Leg_pol( 2, 8 ), 95.5 );
  CHECK_EQ( Leg_pol( 0, 8 ), 1 );
  CHECK_EQ( Leg_pol( 1, 8 ), 8 );
  CHECK_THROWS_AS( Leg_pol( -2, 3 ), runtime_error );
  CHECK_THROWS_MESSAGE( Leg_pol( -2, 3 ), "Polynomial index should be major or equal to 0!" );
 }

//============================================
//     "n_derivative" function testing
//============================================
double f( int a, double x ) { return x*x*a; }

TEST_CASE( "Testing the n_derivative function " )
 {
  CHECK_EQ( n_derivative( f, 1, 1, 1 ), 2);
  CHECK_EQ( n_derivative( f, 5, 1, 1 ), 10);
  CHECK_EQ( n_derivative( f, 1, 3, 1 ), 6);
  CHECK_EQ( n_derivative( f, 1, 1, 2 ), 2);
  CHECK_EQ( n_derivative( f, 1, 1, 3 ), 0);

  CHECK_EQ( n_derivative( Leg_pol, 1, 1, 1 ), 1);
  CHECK_EQ( n_derivative( Leg_pol, 1, 0, 1 ), 0);
  CHECK_EQ( n_derivative( Leg_pol, 1, 2, 1 ), 3);
  CHECK_EQ( n_derivative( Leg_pol, 1, 2, 2 ), 3);
  CHECK_EQ( n_derivative( Leg_pol, 1, 2, 3 ), 0);
  CHECK_EQ( n_derivative( Leg_pol, 1, 3, 2 ), 15);  
  CHECK_EQ( n_derivative( Leg_pol, 2, 3, 2 ), 30);  

  CHECK_THROWS_AS( n_derivative( Leg_pol, 1, 1, -1 ), runtime_error );
  CHECK_THROWS_MESSAGE( n_derivative( Leg_pol, 1, 1, -1 ), "Derivative cannot be calculated for order less than 0!" );
 }