#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"

//Extra headers
#include <doctest.h>
#include <arsenalgear/math.hpp>

//STD headers
#include <stdexcept>
#include <string>
#include <cmath>

//============================================
//     Global variables
//============================================
inline constexpr double rda = 3.456234;

//============================================
//     "h" function testing
//============================================
TEST_CASE( "Testing the h function" ) // 100% working
 {
  CHECK_EQ( safd::h( 2, 0.5 ), safd::STEP_SIZE * 0.5 );
  CHECK_EQ( safd::h( 7, 0.5 ), 7 * 0.09 );
 }

//============================================
//     "n_derivative" function testing
//============================================
inline double func( const int& a, const double& x ) { return sin( x ) - cos( x ); }
inline double gunc( const int& a, const double& x ) { return 5*pow( x, 5 ) + pow( x, 4 ); }

TEST_CASE( "Testing the n_derivative function" )
 {
  SUBCASE( "Testing the 1-derivative" )
   {
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, 1, 1, 1 )  * 100.0 ) / 100.0, 1);
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, 1, 0, 1 )  * 100.0 ) / 100.0, 0);
   }
  SUBCASE( "Testing the 2-derivative" )
   {
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, 2, 3, 2 )  * 100.0 ) / 100.0, 30 );
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, -2, 3, 2 )  * 100.0 ) / 100.0, -30 );
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, 0.3, 3, 2 )  * 100.0 ) / 100.0, 4.5 );
   }
  SUBCASE( "Testing the 3-derivative" )
   {
    CHECK_EQ( round( safd::n_derivative( safd::Leg_pol, 1, 3, 3 )  * 1.0 ) / 1.0, 15 );
    CHECK_EQ( round( safd::n_derivative( func, M_PI/3, 4, 3 ) * 10.0 ) / 10.0, -1.4 );
    CHECK_EQ( round( safd::n_derivative( gunc, 3, 4, 3 ) * 1.0 ) / 1.0, 2772 - 1 );
   }
  SUBCASE( "Testing higher orders derivatives" ) 
   {
   CHECK_EQ( round( safd::n_derivative( gunc, 3, 4, 4 ) * 100.0 ) / 100.0, 1825.41 );
   }
  SUBCASE( "Testing exceptions" )
   {
    CHECK_THROWS_AS( round( safd::n_derivative( safd::Leg_pol, 1, 1, -1 ) * 100.0 ) / 100.0, std::runtime_error );
   }
 }

//============================================
//     "integral" function testing
//============================================
inline double huncx( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return sin( x ) - cos( x ); }
inline double huncx_2( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( sin( x ), 2 ) - cos( x ); }
inline double huncx_3( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( sin( x ), 3 ) - cos( x ); }

inline double huncy( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return sin( y ) - cos( y ); }
inline double huncy_2( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( sin( y ), 2 ) - cos( y ); }
inline double huncy_3( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( sin( y ), 8 ) - pow( cos( y ), 3 ); }
inline double huncy_4( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( sin( y ), 4 ) + pow( cos( y ), 9 ) - pow( cos( y ), 3 ); }

inline double hunc( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ); }
inline double hunc_2( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( cos( x ), 5 ) + pow( sin( y ), 4 ) + pow( cos( x ), 2 ); }
inline double hunc_3( const std::string& s, const int& m, const int& l, const double& x, const double& y ) { return pow( cos( x + y ), 3 ) + cos( x ) * pow( sin( x ), 5 ) + 5 + sin( y - x ); }

TEST_CASE( "Testing the integral function" ) // 100% working
 {
  SUBCASE( "Testing for x variable only" )
   {
    CHECK( agr::IsInBounds( safd::integral( huncx, "", 0, 0 ), 12.0, 13.1 ) );
    CHECK( agr::IsInBounds( safd::integral( huncx_2, "", 0, 0 ), 9.2, 10.5 ) );
    CHECK( agr::IsInBounds( safd::integral( huncx_3, "", 0, 0 ), 8.30, 8.90 ) );
   }
  SUBCASE( "Testing for y variable only" )
   {
    CHECK( agr::IsInBounds( safd::integral( huncy, "", 0, 0 ), -0.3, 0.3 ) );
    CHECK( agr::IsInBounds( safd::integral( huncy_2, "", 0, 0 ), 9.80, 9.90 ) );
    CHECK( agr::IsInBounds( safd::integral( huncy_3, "", 0, 0 ), 5.2, 5.4 ) );
    CHECK( agr::IsInBounds( safd::integral( huncy_4, "", 0, 0 ), 7.30, 7.60 ) );
   }
  SUBCASE( "Testing for 2 variables" )
   {
    CHECK( agr::IsInBounds( safd::integral( hunc, "", 0, 0 ), 7.00, 7.20 ) );
    CHECK( agr::IsInBounds( safd::integral( hunc_2, "", 0, 0 ), 17.2, 17.6 ) );
    CHECK( agr::IsInBounds( safd::integral( hunc_3, "", 0, 0 ), 96.5, 101.5 ) );
   }
 }