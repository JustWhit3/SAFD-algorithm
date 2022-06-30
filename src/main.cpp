//============================================
//     Headers
//============================================

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"

//Extra headers
#include <osmanip/manipulators/colsty.hpp>
#include <arsenalgear/constants.hpp>
#include <arsenalgear/operators.hpp>

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
  char letter = ' ', letter_r;
  std::string equation;
  const std::string spaces = agr::empty_space<std::string> * 5;
  
  std::cout << "\n"
            << spaces << osm::feat( osm::col, "green" ) << "         _____         ______ _____         " 
            << osm::reset( "color" ) << "\n"
            << spaces  << osm::feat( osm::col, "green" ) << "        / ____|  /\\   |  ____|  __ \\        " 
            << osm::reset( "color" ) << "\n"
            << spaces  << osm::feat( osm::col, "green" ) << "       | (___   /  \\  | |__  | |  | |       " 
            << osm::reset( "color" ) << "\n"
            << spaces  << osm::feat( osm::col, "green" ) << "        \\___ \\ / /\\ \\ |  __| | |  | |       " 
            << osm::reset( "color" ) << "\n"
            << spaces  << osm::feat( osm::col, "green" ) << "        ____) / ____ \\| |    | |__| |       " 
            << osm::reset( "color" ) << "\n"
            << spaces  << osm::feat( osm::col, "green" ) << "       |_____/_/    \\_\\_|    |_____/        " 
            << osm::reset( "color" ) << "\n\n\n"
            << osm::feat( osm::col, "cyan" ) << osm::feat( osm::sty, "italics" ) 
            << "Welcome to SAFD: a program to compute the coefficients f(m,l) of a " 
            << "\nfunction f(th,phi) development in a spherical harmonics convergent series. " 
            << osm::reset( "all" ) << "\n\n";

  while( true )
   {
    std::cout << "Available options:" << "\n"
              << "   1. Display the single value of a f(m,l) coefficient." << "\n"
              << "   2. Display all the values of f(m,l) coefficients from m to 0 and from l to 0." << "\n"
              << "   3. Quit the program. " << "\n\n"
              << "Option choice: ";
  
    std::cin >> choice;
    std::cout << "\n";
  
    if( choice == 3 ) 
     {
      std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                << "\n\n";
      break;
     }
    else if( choice == 1 )
     {
      safd::initializer( equation, m, l );
      std::cout << "Chosen function is: " << osm::feat( osm::col, "orange" ) << "f(th,phi) = " << equation << osm::reset( "color" ) << "\n";
      safd::plotter( equation );
      std::cout << "\nValue of the coefficient is (real + imaginary part):" << "\n\n";
      safd::displayer( equation, m, l );
      std::cout << "\n";

      letter_r = safd::abort_this( letter );
      if ( letter_r == 'n' )
       {
        std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                  << "\n\n";
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        std::cerr << osm::feat( osm::col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
                  << osm::reset( "color" ) << "\n\n"; 
        break;
       }
     }
    else if( choice == 2 )
     {
      safd::initializer( equation, m, l );
      std::cout << "Chosen function is: " << osm::feat( osm::col, "orange" ) << "f(th,phi) = " << equation << osm::reset( "color" ) << "\n\n";
      safd::plotter( equation );
      std::cout << "\nValue of the coefficients is (real + imaginary part):" << "\n\n";
      for( int a = 0; a < m + 1; a++ )
       {
        for( int b = 0; b < l + 1; b++ )
         {
          if( a > b ) continue;
          safd::displayer( equation, a, b ); std::cout << "\n";
         }
       }

      letter_r = safd::abort_this( letter );
      if ( letter_r == 'n' )
       {
        std::cout << osm::feat( osm::col, "green" ) << "Program exited successfully." << osm::reset( "color" ) 
                  << "\n\n";
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        std::cerr << osm::feat( osm::col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
                  << osm::reset( "color" ) << "\n\n"; 
        break;
       }
     }
    else
     {
      std::cin.clear();
      std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
      
      std::cerr << osm::feat( osm::col, "red" ) << "Invalid option!" << osm::reset( "color" ) 
                << "\n\n";
     }
    }
 }