#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

//STD headers
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

//Extra headers
#include <doctest.h>

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"
using namespace SphArmFuncDev;

//============================================
//     "Leg_pol" function testing
//============================================
TEST_CASE( "Testing the Leg_pol function" ) // 100% working
 {
  CHECK_EQ( Leg_pol( 2, 0.3 ), -0.365 );
  CHECK_EQ( Leg_pol( 0, 0.6 ), 1 );
  CHECK_EQ( Leg_pol( 1, 0.6 ), 0.6 );
  CHECK_EQ( round_var( Leg_pol( 6, 0.6 ) * 100.0 ) / 100.0, 0.17 );
  CHECK_THROWS_AS( Leg_pol( -2, 3 ), runtime_error );
 }

//============================================
//     "Leg_func" function testing
//============================================
TEST_CASE( "Testing the Leg_func function" ) // 100% working
 {
  SUBCASE( "Testing for b == 0" )
   {
    CHECK_EQ( round_var( Leg_func( 0, 0, 0.3 ) * 100.0 ) / 100.0, 1 );
    CHECK_EQ( round_var( Leg_func( 0, 1, 0.3 ) * 100.0 ) / 100.0, 0.3 );
    CHECK_EQ( round_var( Leg_func( 0, 2, 0.3 ) * 100.0 ) / 100.0, -0.37 );
   }
  SUBCASE( "Testing for 1 <= b <= 3" )
   {
    CHECK_EQ( round_var( Leg_func( 1, 1, 0.5 ) * 100.0 ) / 100.0, -0.87 );
    CHECK_EQ( round_var( Leg_func( 1, 2, -0.3 ) * 100.0 ) / 100.0, 0.86 );
    CHECK_EQ( round_var( Leg_func( 3, 4, 0.9 ) * 100.0 ) / 100.0, -7.83 - 0.01 );
    CHECK_EQ( round_var( Leg_func( 2, 2, 0.5 ) * 100.0 ) / 100.0, 2.25 );
   }
  SUBCASE( "Testing for b >= 4 and |b-a| <= 1" )
   {
    CHECK( IsInBounds( Leg_func( 4, 5, 0.5 ), 260.0, 270.0 ) );
    CHECK( IsInBounds( Leg_func( 6, 6, 0.005 ), 10380.0, 10400.0 ) );
    CHECK( IsInBounds( Leg_func( 7, 8, 0.5 ), -370000.0, -369800.0 ) );
    CHECK( IsInBounds( Leg_func( 10, 11, 0.5 ), 1631080449.0, 1638080449.0 ) );
   }
  SUBCASE( "Testing for b >= 4 and |b-a| > 1" ) //***** TODO ***** 
   {
    //CHECK_EQ( round_var( Leg_func( 4, 6, 0.5 ) * 1.0 ) / 1.0, 465.1 );
    //CHECK_EQ( round_var( Leg_func( 6, 8, 0.5 ) * 1.0 ) / 1.0, 78388.9 );
    //CHECK_EQ( round_var( Leg_func( 7, 11, 0.5 ) * 1.0 ) / 1.0, 295075.9 );
   }
  SUBCASE( "Testing exceptions" )
   {
    CHECK_THROWS_AS( Leg_func( 1, 2, -3 ), runtime_error );
    CHECK_THROWS_AS( Leg_func( 1, 2, 3 ), runtime_error );
    CHECK_THROWS_AS( Leg_func( 3, 2, 0.2 ), runtime_error );
    CHECK_THROWS_AS( Leg_func( -2, 1, 0.2 ), runtime_error );
    CHECK_THROWS_AS( Leg_func( -2, -3, 0.2 ), runtime_error );
   }
 }

//============================================
//     "sph_arm" function testing
//============================================
TEST_CASE( "Testing the sph_arm function" ) // 100% working
 {
  SUBCASE( "Testing for m == 0 and l == 0" )
   {
    cmplx c( 0.28, 0 );
    CHECK_EQ( round_var( sph_arm( 0, 0, M_PI, M_PI ).real() * 100.0 ) / 100.0, c.real() );
    CHECK_EQ( round_var( sph_arm( 0, 0, M_PI, M_PI ).imag() * 100.0 ) / 100.0, c.imag() );
    CHECK_EQ( round_var( sph_arm( 0, 0, 2*M_PI, M_PI ).real() * 100.0 ) / 100.0, c.real() );
    CHECK_EQ( round_var( sph_arm( 0, 0, 2*M_PI, M_PI ).imag() * 100.0 ) / 100.0, c.imag() );
   }
  SUBCASE( "Testing for m == 0, l == 1 and Theta = 180" )
   {
    cmplx d( -0.49, 0 );
    CHECK_EQ( round_var( sph_arm( 0, 1, M_PI, M_PI ).real() * 100.0 ) / 100.0, d.real() );
    CHECK_EQ( round_var( sph_arm( 0, 1, M_PI, M_PI ).imag() * 100.0 ) / 100.0, d.imag() );
   }
  SUBCASE( "Testing for m == 0, l == 2 and Theta = 180" )
   {
    cmplx e( 0.63, 0 );
    CHECK_EQ( round_var( sph_arm( 0, 2, M_PI, M_PI ).real() * 100.0 ) / 100.0, e.real() );
    CHECK_EQ( round_var( sph_arm( 0, 2, M_PI, M_PI ).imag() * 100.0 ) / 100.0, e.imag() );
   }
  SUBCASE( "Testing for m == 0, l == 2 and Theta = 30" )
   {
    cmplx e_2( 0.39, 0 );
    CHECK_EQ( round_var( sph_arm( 0, 2, M_PI/6, M_PI ).real() * 100.0 ) / 100.0, e_2.real() );
    CHECK_EQ( round_var( sph_arm( 0, 2, M_PI/6, M_PI ).imag() * 100.0 ) / 100.0, e_2.imag() );
   }
  SUBCASE( "Testing for m == 1, l == 1, Theta = 30 and Phi = 60" )
   {
    cmplx f( -0.09, -0.15 );
    CHECK_EQ( round_var( sph_arm( 1, 1, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, f.real() );
    CHECK_EQ( round_var( sph_arm( 1, 1, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, f.imag() );
   }
  SUBCASE( "Testing for m == -1, l == 1, Theta = 30 and Phi = 60" )
   {
    cmplx f_n( 0.09, -0.15 );
    CHECK_EQ( round_var( sph_arm( -1, 1, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, f_n.real() );
    CHECK_EQ( round_var( sph_arm( -1, 1, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, f_n.imag() );
   }
  SUBCASE( "Testing for m == 2, l == 2, Theta = 30 and Phi = 60" )
   {
    cmplx g( -0.05, 0.08 );
    CHECK_EQ( round_var( sph_arm( 2, 2, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, g.real() );
    CHECK_EQ( round_var( sph_arm( 2, 2, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, g.imag() );
   }
  SUBCASE( "Testing for m == 3, l == 4, Theta = 30 and Phi = 60" )
   {
    cmplx h( 0.14, 0 );
    CHECK_EQ( round_var( sph_arm( 3, 4, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, h.real() );
    CHECK_EQ( round_var( sph_arm( 3, 4, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, h.imag() );
   }

  SUBCASE( "Testing for m == 5, l == 5, Theta = 30 and Phi = 60" )
   {
    cmplx i( -0.01, 0.01 );
    CHECK_EQ( round_var( sph_arm( 5, 5, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, i.real() );
    CHECK_EQ( round_var( sph_arm( 5, 5, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, i.imag() );
   }
  SUBCASE( "Testing for m == 4, l == 5, Theta = 30 and Phi = 60" )
   {
    cmplx j( -0.04, -0.07 );
    CHECK_EQ( round_var( sph_arm( 4, 5, M_PI/6, M_PI/3 ).real() * 100.0 ) / 100.0, j.real() );
    CHECK_EQ( round_var( sph_arm( 4, 5, M_PI/6, M_PI/3 ).imag() * 100.0 ) / 100.0, j.imag() );
   }
  SUBCASE( "Testing cases with |m-l|>1" ) //***** TODO ***** 
   {
    //
   }
  SUBCASE( "Testing exceptions" )
   {
    CHECK_THROWS_AS( sph_arm( 7, 2, M_PI/6, M_PI/3), runtime_error );
    CHECK_THROWS_AS( sph_arm( 1, -1, M_PI/6, M_PI/3), runtime_error );
    CHECK_THROWS_AS( sph_arm( -6, 5, M_PI/6, M_PI/3), runtime_error );
   }
 }

//============================================
//     "sph_arm" function testing
//============================================
TEST_CASE( "Testing the parsed_f function" ) // 100% working
 {
  CHECK_EQ( parsed_f( "th + phi", 1, 2 ), 3 );
  CHECK_EQ( parsed_f( "cos( th ) - sin( phi )", M_PI, M_PI/2 ), -2 );
  CHECK_EQ( parsed_f( "3*( cos( th ) - sin( phi ) )", M_PI, M_PI/2 ), -6 );

  double p = parsed_f( "3*( cos( th ) - sin( phi ) )", M_PI, M_PI/2 );
  CHECK_EQ( p, -6 );
 }

//============================================
//     "f_theta_phi" function testing
//============================================
TEST_CASE( "Testing the f_theta_phi function" ) // 100% working
 {
  CHECK_EQ( round_var( f_theta_phi_real( "cos( th ) - sin( phi )", 1, 1, M_PI/6, M_PI/4 ) * 10000.0 ) / 10000.0, -0.0097 );
  CHECK_EQ( round_var( f_theta_phi_imag( "cos( th ) - sin( phi )", 1, 1, M_PI/6, M_PI/4 ) * 10000.0 ) / 10000.0, 0.0097 );

  CHECK_EQ( round_var( f_theta_phi_real( "sin( th ) + cos( phi )", 1, 1, M_PI/6, M_PI/3 ) * 1000.0 ) / 1000.0, -0.043 );
  CHECK_EQ( round_var( f_theta_phi_imag( "sin( th ) + cos( phi )", 1, 1, M_PI/6, M_PI/3 ) * 1000.0 ) / 1000.0, 0.075 );
 }

//============================================
//     "f_m_l" function testing
//============================================
TEST_CASE( "Testing the f_m_l function" )  
 {
  SUBCASE( "Testing for m = 0" ) // ***** TODO ***** 
   {
    CHECK_EQ( round_var( f_m_l( "cos( th )", 0, 0 ).real() * 100.0 ) / 100.0, 0.0 );
    CHECK_EQ( round_var( f_m_l( "cos( th )", 0, 0 ).imag() * 100.0 ) / 100.0, 0.0 );
    
    CHECK( IsInBounds( f_m_l( "cos( th )", 0, 1 ).real(),  2.04, 2.065 ) );
    CHECK_EQ( round_var( f_m_l( "cos( th )", 0, 1 ).imag() * 100.0 ) / 100.0, 0.0 );

    CHECK( IsInBounds( f_m_l( "pow( cos( th ), 3 )", 0, 1 ).real(),  1.21, 1.24 ) );
    CHECK_EQ( round_var( f_m_l( "pow( cos( th ), 3 )", 0, 1 ).imag() * 100.0 ) / 100.0, 0.0 );
   }
  SUBCASE( "Testing for m > 0" ) // ***** TODO ***** 
   {

   }
 }