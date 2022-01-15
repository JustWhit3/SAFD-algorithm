//STD headers
#include <iostream>
#include <complex>
#include <string>
using namespace std;

//Extra headers
#include <osmanip.h>
using namespace osm;

//My headers
#include "../include/functions.hpp"
using namespace SphArmFuncDev;

void initializer( string& equation, int& m, int& l)
 {
  cout << "Enter the f(th,phi) equation shape (avoid backspaces): ";
  cin >> equation;
  cout << "Enter the value of m: ";
  cin >> m;
  cout << "Enter the value of l: ";
  cin >> l;
  cout << endl;
 }

void displayer( string& equation, int& m, int& l )
 {
  cout << "f(" << m << "," << l << ") = "
       << feat( col, "green" ) << f_m_l( equation, m, l ).real() << reset( "color" ) << " + "
       << feat( col, "green" ) << f_m_l( equation, m, l ).imag() << reset( "color" )
       << feat( col, "lt blue" ) << "i" << reset( "color" ) << endl;
 }

char abort_this( char letter )
 {
  cout << "Compute another coefficient (enter \"y\" or \"n\")?: ";
  cin >> letter;
  cout << endl;
  return letter;
 }

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
       << "///         _____         ______ _____         ///" << endl
       << "///        / ____|  /\\   |  ____|  __ \\        ///" << endl
       << "///       | (___   /  \\  | |__  | |  | |       ///" << endl
       << "///        \\___ \\ / /\\ \\ |  __| | |  | |       ///" << endl
       << "///        ____) / ____ \\| |    | |__| |       ///" << endl
       << "///       |_____/_/    \\_\\_|    |_____/        ///" << endl
       << "///                                            ///" << endl
       << "///                                            ///" << endl
       << "//////////////////////////////////////////////////" << endl << endl;

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
      cerr << feat( col, "red" ) << "Invalid option!" << reset( "color" ) 
           << endl <<endl;
     }
   }
 }