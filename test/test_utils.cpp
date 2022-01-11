#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include <stdexcept>

#include "../include/functions.hpp"
#include "../include/utils.hpp"

using namespace std;

#define rda 3.456234         \

//============================================
//     "n_derivative" function testing
//============================================
double func( int a, double x ) { return sin( x ) - cos( x ); }
double gunc( int a, double x ) { return 5*pow( x, 5 ) + pow( x, 4 ); }

TEST_CASE( "Testing the n_derivative function" )
 {
  SUBCASE( "Testing the 1-derivative" ) //OK
   {
    CHECK_EQ( round_var( n_derivative( Leg_pol, 1, 1, 1 )  * 100.0 ) / 100.0, 1);
    CHECK_EQ( round_var( n_derivative( Leg_pol, 1, 0, 1 )  * 100.0 ) / 100.0, 0);
   }
  SUBCASE( "Testing the 2-derivative" ) //OK
   {
    CHECK_EQ( round_var( n_derivative( Leg_pol, 2, 3, 2 )  * 100.0 ) / 100.0, 30 );
    CHECK_EQ( round_var( n_derivative( Leg_pol, -2, 3, 2 )  * 100.0 ) / 100.0, -30 );
    CHECK_EQ( round_var( n_derivative( Leg_pol, 0.3, 3, 2 )  * 100.0 ) / 100.0, 4.5 );
   }
  SUBCASE( "Testing the 3-derivative" ) //OK
   {
    CHECK_EQ( round_var( n_derivative( Leg_pol, 1, 3, 3 )  * 1.0 ) / 1.0, 15 );
    CHECK_EQ( round_var( n_derivative( func, M_PI/3, 4, 3 ) * 10.0 ) / 10.0, -1.4 );
    CHECK_EQ( round_var( n_derivative( gunc, 3, 4, 3 ) * 1.0 ) / 1.0, 2772 - 1 );
   }
  SUBCASE( "Testing higher orders derivatives" ) //***** TODO ***** 
   {
   //CHECK_EQ( round_var( n_derivative( gunc, 3, 4, 4 ) * 100.0 ) / 100.0, 1823.91 );
   //CHECK_EQ( round_var( n_derivative( func, M_PI/3, 4, 8 ) * 100.0 ) / 100.0, 0.37 );
   //CHECK_EQ( round_var( n_derivative( func, M_PI/3, 4, 10 ) * 100.0 ) / 100.0, -0.37 );
   }
  SUBCASE( "Testing exceptions" ) //OK
   {
    CHECK_THROWS_AS( round_var( n_derivative( Leg_pol, 1, 1, -1 ) * 100.0 ) / 100.0, runtime_error );
   }
 }

//============================================
//     "round" function testing
//============================================
TEST_CASE( "Testing the round function" )
 {
  CHECK_EQ( round_var( rda * 100.0 ) / 100.0, 3.46 );
 }

//============================================
//     "factorial" function testing
//============================================
TEST_CASE( "Testing the factorial function" )
 {
  CHECK_EQ( factorial( 0 ), 1 );
  CHECK_EQ( factorial( 1 ), 1 );
  CHECK_EQ( factorial( 3 ), 6 );
  CHECK_EQ( factorial( 5 ), 120 );
 }

//============================================
//     "IsInBounds" function testing
//============================================
TEST_CASE( "Testing the IsInBounds function" )
 {
  CHECK( IsInBounds( rda, 3.3, 3.5 ) );
 }