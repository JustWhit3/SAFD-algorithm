//STD headers
#include <iostream>
#include <complex>
#include <string>
#include <limits>
using namespace std;

//Extra headers
#include <osmanip/manipulators/csmanip.hpp>
using namespace osm;

//My headers
#include "../include/functions.hpp"
#include "../include/utils.hpp"
using namespace SphArmFuncDev;

//============================================
//     "main" function
//============================================
int main()
 {
  int choice, m, l;
  char letter, letter_r;
  string equation;
  
  cout << endl
       << "//////////////////////////////////////////////////" << endl
       << "///                                            ///" << endl
       << "///" << feat( col, "green" ) << "         _____         ______ _____         " 
       << reset( "color" ) << "///" << endl
       << "///" << feat( col, "green" ) << "        / ____|  /\\   |  ____|  __ \\        " 
       << reset( "color" ) << "///" << endl
       << "///" << feat( col, "green" ) << "       | (___   /  \\  | |__  | |  | |       " 
       << reset( "color" ) << "///" << endl
       << "///" << feat( col, "green" ) << "        \\___ \\ / /\\ \\ |  __| | |  | |       " 
       << reset( "color" ) << "///" << endl
       << "///" << feat( col, "green" ) << "        ____) / ____ \\| |    | |__| |       " 
       << reset( "color" ) << "///" << endl
       << "///" << feat( col, "green" ) << "       |_____/_/    \\_\\_|    |_____/        " 
       << reset( "color" ) << "///" << endl
       << "///                                            ///" << endl
       << "///                                            ///" << endl
       << "//////////////////////////////////////////////////" << endl << endl
       << feat( col, "cyan" ) << feat( sty, "italics" ) 
       << "Welcome to SAFD: a program to compute the coefficients f(m,l) of a " 
       << "function f(th,phi)\ndevelopment in a spherical armonics convergent serie. " 
       << reset( "all" ) << endl << endl;

  while( true )
   {
    cout << "Available options:" << endl
         << "   1. Display the single value of a f(m,l) coefficient." << endl
         << "   2. Display all the values of f(m,l) coefficients from m to 0 and from l to 0." << endl
         << "   3. Quit the program. " << endl << endl
         << "Option choice: ";
  
    cin >> choice;
    cout << endl;
  
    if( choice == 3 ) 
     {
      cout << feat( col, "green" ) << "Program exited successfully." << reset( "color" ) 
           << endl << endl;
      break;
     }
    else if( choice == 1 )
     {
      initializer( equation, m, l );
      cout << "Value of the coefficient is (real + imaginary part):" << endl << endl;
      displayer( equation, m, l );
      cout << endl;

      letter_r = abort_this( letter );
      if ( letter_r == 'n' )
       {
        cout << feat( col, "green" ) << "Program exited successfully." << reset( "color" ) 
             << endl << endl;
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        cerr << feat( col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
             << reset( "color" ) << endl <<endl; 
        break;
       }
     }
    else if( choice == 2 )
     {
      initializer( equation, m, l );
      cout << "Value of the coefficients is (real + imaginary part):" << endl << endl;
      for( int a = 0; a < m + 1; a++ )
       {
        for( int b = 0; b < l + 1; b++ )
         {
          if( a > b ) continue;
          displayer( equation, a, b ); cout << endl;
         }
       }

      letter_r = abort_this( letter );
      if ( letter_r == 'n' )
       {
        cout << feat( col, "green" ) << "Program exited successfully." << reset( "color" ) 
             << endl << endl;
        break;
       }
      else if( letter_r == 'y' ) { continue; }
      else
       {
        cerr << feat( col, "red" ) << "Inserted answer is not correct. Automatically aborting the program!" 
             << reset( "color" ) << endl <<endl; 
        break;
       }
     }
    else
     {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
      cerr << feat( col, "red" ) << "Invalid option!" << reset( "color" ) 
           << endl <<endl;
     }
    }
 }