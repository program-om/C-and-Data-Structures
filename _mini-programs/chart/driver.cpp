// File: driver.cpp
// Program to test SeatingChart class
// ----------------------------------------------------------------------

#include <iostream>
#include "chart.h"

int main ()
{
   using namespace std;

   // *** DECLARE A 10X4 SEATING CHART NAMED chart1 HERE ***
   SeatingChart chart1(10,4);

   int row, seat;
   char command;

   cout << "Chart 1: (10x4)" << endl;
   chart1.Write(cout);
   
   cout << "Do you want to check assignment (c), assign (a), unassigned (u),"
	<< " or quit (q): ";
   cin >> command;
   command = tolower(command);
   
   while (command != 'q')
   {
      cout << "Enter a row number and a seat number: ";
      cin >> row >> seat;

      try{
	
      if (command == 'a')
      {
	 cout << "Assigning this seat" << endl;
	 chart1.Assign(row, seat);
      }

      else if(command == 'c')
	{
          if(chart1.IsAssigned(row, seat))
	    cout << "The Seat is assigned!" << endl;
	    else
	      cout << "The seat is NOT assigned!" << endl;
	}
      
      else if (command == 'u')
      {
	 cout << "Unassigning this seat" << endl;
	 chart1.Unassign(row, seat);
      }
      
      else
	 cout << "Unknown command.  Try again." << endl;

      }catch(const string msg)
	{
	  cout << endl << msg << endl << endl;
	}

      cout << "Chart 1: (10x4)" << endl;
      chart1.Write(cout);
   
      cout << "Do you want to check assignment (c), assign (a), unassigned (u),"
	<< " or quit (q): ";
      cin >> command;
      command = tolower(command);
   }
   return 0;
}  // end main
