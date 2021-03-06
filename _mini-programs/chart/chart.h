// File: chart.h
// Skeleton class that models rectangular seating charts using 
// dynamic one-dimensional array of booleans.  
//    - seats[i][j] maps to seatArray[i*numSeats+j]
//    - seats[i][j] == false means seat is unassigned
//    - seats[i][j] == true means seat is assigned
//
// Row numbers are 0 ... numRows-1
// Seat numbers are 0 ... numSeats-1
// ----------------------------------------------------------------------

#ifndef _CHART_H_
#define _CHART_H_

#include <iostream>

class SeatingChart
{
  public:  // No default constructor on purpose
   SeatingChart (int init_rows, int init_seats);
   ~SeatingChart();
   bool IsAssigned(int row, int seatNum)const;


   void Assign (int row, int seatNum);
   void Unassign (int row, int seatNum);
   void Write (std::ostream & out);

  private:
   int numRows,     // number of rows
      numSeats;     // number seats in each row

   bool* seatArray;

   
};

#endif
