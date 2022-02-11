#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//STD headers
#include <stdexcept>
#include <string>
using namespace std;

//Extra headers
#include <doctest.h>
#include <osmanip.hpp>
using namespace osm;

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"
using namespace SphArmFuncDev;

//============================================
//     Global variables
//============================================
#define rda 3.456234                            \

#define test_string "This is a test string"     \

//============================================
//     "runtim_thrower" function testing
//============================================
TEST_CASE( "Testing the runtime_thrower function" ) // 100% working
 {
  CHECK_THROWS_AS( throw runtime_thrower( test_string ), runtime_error );
  CHECK_THROWS_MESSAGE( throw runtime_thrower( test_string ), feat( col, "red" ) + test_string + reset( "color" ) );
 }

//============================================
//     "h" function testing
//============================================
TEST_CASE( "Testing the h function" ) // 100% working
 {
  CHECK_EQ( h( 2, 0.5 ), STEP_SIZE * 0.5 );
  CHECK_EQ( h( 7, 0.5 ), 7 * 0.09 );
 }

//============================================
//     "n_derivative" function testing
//============================================
inline double const func( int a, double x ) { return sin( x ) - cos( x ); }
inline double const gunc( int a, double x ) { return 5*pow( x, 5 ) + pow( x, 4 ); }

TEST_CASE( "Testing the n_derivative function" )
 {
  SUBCASE( "Testing the 1-derivative" )
   {
    CHECK_EQ( round_var( n_derivative( &Leg_pol, 1, 1, 1 )  * 100.0 ) / 100.0, 1);
    CHECK_EQ( round_var( n_derivative( &Leg_pol, 1, 0, 1 )  * 100.0 ) / 100.0, 0);
   }
  SUBCASE( "Testing the 2-derivative" )
   {
    CHECK_EQ( round_var( n_derivative( &Leg_pol, 2, 3, 2 )  * 100.0 ) / 100.0, 30 );
    CHECK_EQ( round_var( n_derivative( &Leg_pol, -2, 3, 2 )  * 100.0 ) / 100.0, -30 );
    CHECK_EQ( round_var( n_derivative( &Leg_pol, 0.3, 3, 2 )  * 100.0 ) / 100.0, 4.5 );
   }
  SUBCASE( "Testing the 3-derivative" )
   {
    CHECK_EQ( round_var( n_derivative( &Leg_pol, 1, 3, 3 )  * 1.0 ) / 1.0, 15 );
    CHECK_EQ( round_var( n_derivative( &func, M_PI/3, 4, 3 ) * 10.0 ) / 10.0, -1.4 );
    CHECK_EQ( round_var( n_derivative( &gunc, 3, 4, 3 ) * 1.0 ) / 1.0, 2772 - 1 );
   }
  SUBCASE( "Testing higher orders derivatives" ) 
   {
   CHECK_EQ( round_var( n_derivative( &gunc, 3, 4, 4 ) * 100.0 ) / 100.0, 1825.41 );
   }
  SUBCASE( "Testing exceptions" )
   {
    CHECK_THROWS_AS( round_var( n_derivative( &Leg_pol, 1, 1, -1 ) * 100.0 ) / 100.0, runtime_error );
   }
 }

//============================================
//     "round" function testing
//============================================
TEST_CASE( "Testing the round function" ) // 100% working
 {
  CHECK_EQ( round_var( rda * 100.0 ) / 100.0, 3.46 );
 }

//============================================
//     "IsInBounds" function testing
//============================================
TEST_CASE( "Testing the IsInBounds function" ) // 100% working
 {
  CHECK( IsInBounds( rda, 3.3, 3.5 ) );
 }

//============================================
//     "integral" function testing
//============================================
inline double const huncx( string s, int m, int l, double x, double y ) { return sin( x ) - cos( x ); }
inline double const huncx_2( string s, int m, int l, double x, double y ) { return pow( sin( x ), 2 ) - cos( x ); }
inline double const huncx_3( string s, int m, int l, double x, double y ) { return pow( sin( x ), 3 ) - cos( x ); }

inline double const huncy( string s, int m, int l, double x, double y ) { return sin( y ) - cos( y ); }
inline double const huncy_2( string s, int m, int l, double x, double y ) { return pow( sin( y ), 2 ) - cos( y ); }
inline double const huncy_3( string s, int m, int l, double x, double y ) { return pow( sin( y ), 8 ) - pow( cos( y ), 3 ); }
inline double const huncy_4( string s, int m, int l, double x, double y ) { return pow( sin( y ), 4 ) + pow( cos( y ), 9 ) - pow( cos( y ), 3 ); }

inline double const hunc( string s, int m, int l, double x, double y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ); }
inline double const hunc_2( string s, int m, int l, double x, double y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ) + pow( cos( x ), 2 ); }
inline double const hunc_3( string s, int m, int l, double x, double y ) { return pow( cos( x + y ), 3 ) + cos( x ) * pow( sin( x ), 5 ) + 5 + sin( y - x ); }

TEST_CASE( "Testing the integral function" ) // 100% working
 {
  SUBCASE( "Testing for x variable only" )
   {
    CHECK( IsInBounds( integral( &huncx, "", 0, 0 ), 12.0, 13.1 ) );
    CHECK( IsInBounds( integral( &huncx_2, "", 0, 0 ), 9.2, 10.5 ) );
    CHECK( IsInBounds( integral( &huncx_3, "", 0, 0 ), 8.30, 8.90 ) );
   }
  SUBCASE( "Testing for y variable only" )
   {
    CHECK( IsInBounds( integral( &huncy, "", 0, 0 ), -0.3, 0.3 ) );
    CHECK( IsInBounds( integral( &huncy_2, "", 0, 0 ), 9.80, 9.90 ) );
    CHECK( IsInBounds( integral( &huncy_3, "", 0, 0 ), 5.2, 5.4 ) );
    CHECK( IsInBounds( integral( &huncy_4, "", 0, 0 ), 7.30, 7.60 ) );
   }
  SUBCASE( "Testing for 2 variables" )
   {
    CHECK( IsInBounds( integral( &hunc, "", 0, 0 ), 7.00, 7.20 ) );
    CHECK( IsInBounds( integral( &hunc_2, "", 0, 0 ), 17.2, 17.6 ) );
    CHECK( IsInBounds( integral( &hunc_3, "", 0, 0 ), 96.5, 101.5 ) );
   }
 }