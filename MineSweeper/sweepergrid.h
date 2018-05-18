#ifndef SWEEPERGRID_H_
#define SWEEPERGRID_H_

#include<iostream>

#include"sweepercell.h"

class SweeperGrid
{
  
private:
  int numRows,  //The number of rows in the grid
      numColumns, //The number of columns in the grid
      numBombs;  //The number of bombs in the grid
  SweeperCell* gridArray; //the pointer to 'gridArry' array

  void Num_AdjBombs(int row, int col); //this is private function ///which will count the number of the bombs around the specified cell
void make_grid();

public:
  //Constructor
  SweeperGrid();
  
  SweeperGrid(int initialRows, int initialCols, int initialBombs);

  //Destructor
  ~SweeperGrid();

  //Accessors
  int GetRows()const;
  
  int GetColumns()const;
  
  int GetBombs()const;
  
  bool GameWon()const;
  
  void PlaceBomb(int row, int col);
  
  void RemoveBomb(int row, int col);
  
  bool Uncover(int row, int col);
  
  void Mark(int row, int col);
  
  void Unmark(int row, int col);
  
  void WriteGrid(std::ostream &out)const;
  
}; //end SweeperGrid

#endif //SWEEPERGRID_H_
