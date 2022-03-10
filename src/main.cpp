//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"

//Extra headers
#include <osmanip/manipulators/csmanip.hpp>

//STD headers
#include <iostream>
#include <complex>
#include <string>
#include <limits>

//============================================
//     "main" function
//============================================
int main()
 {
  int choice, m, l;
  char letter, letter_r;
  std::string equation;
  
  std::cout << std::endl
            << "//////////////////////////////////////////////////" << std::endl
            << "///                                            ///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "         _____         ______ _____         " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "        / ____|  /\\   |  ____|  __ \\        " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "       | (___   /  \\  | |__  | |  | |       " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "        \\___ \\ / /\\ \\ |  __| | |  | |       " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "        ____) / ____ \\| |    | |__| |       " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///" << osm::feat( osm::col, "green" ) << "       |_____/_/    \\_\\_|    |_____/        " 
            << osm::reset( "color" ) << "///" << std::endl
            << "///                                            ///" << std::endl
            << "///                                            ///" << std::endl
            << "//////////////////////////////////////////////////" << std::endl << std::endl
            << osm::feat( osm::col, "cyan" ) << osm::feat( osm::sty, "italics" ) 
            << "Welcome to SAFD: a program to compute the coefficients f(m,l) of a " 
            << "function f(th,phi)\ndevelopment in a spherical harmonics convergent series. " 
            << osm::reset( "all" ) << std::endl << std::endl;

  while( true )
   {
    std::cout << "Available options:" << std::endl
              << "   1. Display the single value of a f(m,l) coefficient." << std::endl
              << "   2. Display all the values of f(m,l) coefficients from m to 0 and from l to 0." << std::endl
              << "   3. Quit the program. " << std::endl << std::endl
              << "Option choice: ";
  
    std::cin >> choice;
    std::cout << std::endl;
  
    if( choice == 3 ) 
     {
      std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                << std::endl << std::endl;
      break;
     }
    else if( choice == 1 )
     {
      safd::initializer( equation, m, l );
      std::cout << "Value of the coefficient is (real + imaginary part):" << std::endl << std::endl;
      safd::displayer( equation, m, l );
      std::cout << std::endl;

      letter_r = safd::abort_this( letter );
      if ( letter_r == 'n' )
       {
        std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                  << std::endl << std::endl;
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        std::cerr << osm::feat( osm::col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
                  << osm::reset( "color" ) << std::endl << std::endl; 
        break;
       }
     }
    else if( choice == 2 )
     {
      safd::initializer( equation, m, l );
      std::cout << "Value of the coefficients is (real + imaginary part):" << std::endl << std::endl;
      for( int a = 0; a < m + 1; a++ )
       {
        for( int b = 0; b < l + 1; b++ )
         {
          if( a > b ) continue;
          safd::displayer( equation, a, b ); std::cout << std::endl;
         }
       }

      letter_r = safd::abort_this( letter );
      if ( letter_r == 'n' )
       {
        std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                  << std::endl << std::endl;
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        std::cerr << osm::feat( osm::col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
                  << osm::reset( "color" ) << std::endl << std::endl; 
        break;
       }
     }
    else
     {
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
      
      std::cerr << osm::feat( osm::col, "red" ) << "Invalid option!" << osm::reset( "color" ) 
                << std::endl << std::endl;
     }
    }
 }