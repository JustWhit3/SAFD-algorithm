#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//STD headers
#include <stdexcept>
#include <string>

//Extra headers
#include <doctest.h>

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"

//Namespaces
using namespace std;
using namespace SphArmFuncDev;

//============================================
//     Global variables
//============================================
#define rda 3.456234         \

//============================================
//     "n_derivative" function testing
//============================================
inline d_const func( int a, double x ) { return sin( x ) - cos( x ); }
inline d_const gunc( int a, double x ) { return 5*pow( x, 5 ) + pow( x, 4 ); }

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
  SUBCASE( "Testing higher orders derivatives" ) //***** TODO ***** 
   {
   CHECK_EQ( round_var( n_derivative( &gunc, 3, 4, 4 ) * 100.0 ) / 100.0, 1823.91 );
   //CHECK_EQ( round_var( n_derivative( &func, M_PI/3, 4, 8 ) * 100.0 ) / 100.0, 0.37 );
   //CHECK_EQ( round_var( n_derivative( &func, M_PI/3, 4, 10 ) * 100.0 ) / 100.0, -0.37 );
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
//     "factorial" function testing
//============================================
TEST_CASE( "Testing the factorial function" ) // 100% working
 {
  CHECK_EQ( factorial( 0 ), 1 );
  CHECK_EQ( factorial( 1 ), 1 );
  CHECK_EQ( factorial( 3 ), 6 );
  CHECK_EQ( factorial( 5 ), 120 );
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
inline d_const huncx( string s, int m, int l, double x, double y ) { return sin( x ) - cos( x ); }
inline d_const huncx_2( string s, int m, int l, double x, double y ) { return pow( sin( x ), 2 ) - cos( x ); }
inline d_const huncx_3( string s, int m, int l, double x, double y ) { return pow( sin( x ), 3 ) - cos( x ); }

inline d_const huncy( string s, int m, int l, double x, double y ) { return sin( y ) - cos( y ); }
inline d_const huncy_2( string s, int m, int l, double x, double y ) { return pow( sin( y ), 2 ) - cos( y ); }
inline d_const huncy_3( string s, int m, int l, double x, double y ) { return pow( sin( y ), 8 ) - pow( cos( y ), 3 ); }
inline d_const huncy_4( string s, int m, int l, double x, double y ) { return pow( sin( y ), 4 ) + pow( cos( y ), 9 ) - pow( cos( y ), 3 ); }

inline d_const hunc( string s, int m, int l, double x, double y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ); }
inline d_const hunc_2( string s, int m, int l, double x, double y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ) + pow( cos( x ), 2 ); }
inline d_const hunc_3( string s, int m, int l, double x, double y ) { return pow( cos( x + y ), 3 ) + cos( x ) * pow( sin( x ), 5 ) + 5 + sin( y - x ); }

//inline d_const spherical( int m, int l, double x, double y ) { return pow( abs( sph_arm( m, l, x, y ) ), 2 ); }

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
  /*SUBCASE( "Testing for spherical armonics function" )
   {
    //CHECK( IsInBounds( integral( &spherical, 0, 0 ), 0.90, 1.00 ) );
    CHECK_EQ( round_var( integral( &spherical, 5, 5 ) * 100.0 ) / 100.0, 0.90 );
   }*/
 }