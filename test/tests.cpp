#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS

#include <doctest.h>
#include "../include/functions.hpp"

using namespace std;

//============================================
//     Leg_pol function testing
//============================================
TEST_CASE( "Testing the Leg_pol function " )
 {
  CHECK_EQ( Leg_pol( 2, 8 ), 95.5 );
  CHECK_EQ( Leg_pol( 0, 8 ), 1 );
  CHECK_EQ( Leg_pol( 1, 8 ), 8 );
  CHECK_THROWS_AS( Leg_pol( -2, 3 ), runtime_error );
  CHECK_THROWS_MESSAGE( Leg_pol( -2, 3 ), "Polynomial index should be major or equal to 0!" );
 }