// File: chart.cpp
// Skeleton class that models rectangular seating charts using 
// dynamic one-dimensional array of booleans.  
//    - seats[i][j] maps to seatArray[i*numSeats+j]
//    - seats[i][j] == false means seat is unassigned
//    - seats[i][j] == true means seat is assigned
//
// Row numbers are 0 ... numRows-1
// Seat numbers are 0 ... numSeats-1
// ----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "chart.h"

// Explict-value constructor
// Creates dynamic 2D "array" of seats
SeatingChart::SeatingChart (int initRows, int initSeats)
{
   numRows = initRows;
   numSeats = initSeats;

   int size = initRows * initSeats;

   seatArray = new bool[size];

   for(int i=0; i < size; i++)
     seatArray[i] = false;

}  // end explicit-value constructor


// *** DEFINITIONS FOR DESTRUCTOR AND IsAssigned GO HERE  ***
SeatingChart::~SeatingChart()
{
  delete [] seatArray;
}

bool SeatingChart::IsAssigned(int row, int seatNum)const
{
  //the position of the seat in the one-dimentional array
  int n = row*numSeats+seatNum;

  if( row >= numRows || seatNum >= numSeats )
    throw std::string("ERROR: The number of the row or the seat number is invalid!");

  if(seatArray[n])
    return true;
  else
    return false;
}


// Function: Assign
// Assigns seat numbered seatNum in row numbered row
void SeatingChart::Assign (int row, int seatNum)
{
  if( row >= numRows || seatNum >= numSeats )
    throw std::string("ERROR: The number of the row or the seat number is invalid!");
  
   seatArray[row*numSeats+seatNum] = true;
}  // end Assign


// Function: Unassign
// Unassigns seat numbered seat_num in row numbered row
void SeatingChart::Unassign (int row, int seatNum)
{

  if( row >= numRows || seatNum >= numSeats )
    throw std::string("ERROR: The number of the row or the seat number is invalid!");
  
   seatArray[row*numSeats+seatNum] = false;
}  // end Unassign

// Function: Write
// Prints out X if the seat is assigned, 0 if seat is not assigned
void SeatingChart::Write (std::ostream & out)
{
   for (int i = 0; i < numRows; i++)
   {
      for (int j = 0; j < numSeats; j++)
         if (seatArray[i*numSeats+j])
            out << " X";
         else
            out << " O";
      out << std::endl;
   }  // end for each row
}  // end Write
