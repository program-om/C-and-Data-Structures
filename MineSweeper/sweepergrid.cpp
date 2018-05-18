// Name: Abdulaziz Alshabibi
// Assignment: Project 4
//
//-----------------------------
#include<iostream>
#include<cstdlib> // exit(0), srand()
#include<ctime>
#include"sweepergrid.h"


// default constructor
SweeperGrid::SweeperGrid()
{
  numRows = 8;
  numColumns = 8;
  numBombs = 10;

  make_grid();
}


// explicit-value constructor
SweeperGrid::SweeperGrid(int initialRows, int initialCols, int initialBombs)
{
   
  numRows = initialRows;
  numColumns = initialCols;
  numBombs  = initialBombs;

  make_grid();
}

// destructor
SweeperGrid::~SweeperGrid()
{
  delete [] gridArray;
}

int SweeperGrid::GetRows()const
{
  return numRows;
}

int SweeperGrid::GetColumns()const
{
  return numColumns;
}

int SweeperGrid::GetBombs()const
{
  return numBombs;
}

bool SweeperGrid::GameWon()const
{
  //GameWon ­ returns true if the game has been won; false otherwise
  
  int n = numColumns*numRows;
  bool R;
    
  for(int i=0; i < n; i++)
    {
      // Conditions refer to that the game is won
      // 1. All bombs are marked
      // 2. All cells are uncovered except those have bombs
      if(( ( gridArray[i].IsMarked() && gridArray[i].HasBomb() ) || 
	   ( !gridArray[i].HasBomb() && !gridArray[i].IsCovered()) ) /*||                        
	 
	 ( (!gridArray[i].IsCovered() && !gridArray[i].HasBomb() ) ||  
	 (gridArray[i].HasBomb() && gridArray[i].IsCovered())  )*/ )     
	R = true;
      else
	return false;
    }

  return R;

}

void SweeperGrid::PlaceBomb(int row, int col)
{
  //n is the index of the one-dimential array
  int n = (row * numColumns) + col;
  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    throw std::string("ERROR: PlaceBomb error"); // <<<<<<<< rewrite the error message 
  
  gridArray[n].PlaceBomb();
  Num_AdjBombs(row, col);
}

void SweeperGrid::RemoveBomb(int row, int col)
{
  //n is the index of the one-dimential array
  int n = (row * numColumns) + col;
  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    throw std::string("ERROR: RemoveBomb error");

  
  gridArray[n].RemoveBomb();
  Num_AdjBombs(row, col);

}

bool SweeperGrid::Uncover(int row, int col)
{
  //n is the index of the one-dimential array
  int n = (row * numColumns) + col;
  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    throw std::string("ERROR: Uncover error");
     
  return gridArray[n].Uncover();
     

}

void SweeperGrid::Mark(int row, int col)
{
  //n is the index of the one-dimential array
  int n = (row* numColumns) + col;
  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    throw std::string("ERROR: Mark error");

  
  gridArray[n].Mark();

}

void SweeperGrid::Unmark(int row, int col)
{
  //n is the index of the one-dimential array
  int n = (row* numColumns) + col;
  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    throw std::string("ERROR: Unmark error");

  
  gridArray[n].Unmark();

}

void SweeperGrid::WriteGrid(std::ostream &out)const
{
  //out  << " ";
  for(int i=0; i < numRows; i++)
    {
      for(int j=0; j < numColumns; j++)
	{
	  out << "  " << gridArray[(i* numColumns) + j];
	  // out << operator<<(std::cout, gridArray[(numRows* numColumns) + numColumns]);
	}
      out << std::endl;
    }
  
}
  

void SweeperGrid::Num_AdjBombs(int row, int col)
{
  int n;

  n = (row* numColumns) + col;
  //size_array = numRows * numColumns;

  if(row < 0 || row >= numRows || col < 0 || col >= numColumns)
    {
      std::cout << "Trying to find the number of the adjacent bombs of non-exist cell!" << std::endl;
    exit(1); // exit(1): Exit failure
    }

  //if(row-1 < 0 || row+1 >= numRows || col-1 < 0 || col+1 >= numColumns)
  
  //                                This part to make sure that it don't go out of the edge
  //if( (n-1) >= 0 && ((n-1) < size_array ))


  //  1 2 3
  //  4 n 6
  //  7 8 9


  // 4
  if(!(col-1 < 0))
    {
      if(gridArray[n-1].HasBomb() /* && (n % numColumns!=0)*/)
	gridArray[n].IncrNumAdjacent();
    }
  
  // 6
  if(!(col+1 >= numColumns))
    {
      if(gridArray[n+1].HasBomb() /* && (n % numColumns) != (numColumns-1)*/)
	gridArray[n].IncrNumAdjacent();
    }

  // 1
  if(!(row-1 < 0  || col-1 < 0 ))
    {
      if(gridArray[ (n-numColumns)-1 ].HasBomb() /* && (n % numColumns!=0)*/)
	gridArray[n].IncrNumAdjacent();
    }

  // 2
  if(!(row-1 < 0 ))
    {
      if(gridArray[ (n-numColumns) ].HasBomb() )
	gridArray[n].IncrNumAdjacent();
    }

  // 3
  if(!(row-1 < 0 || col+1 >= numColumns))
    {
      if(gridArray[ (n-numColumns)+1 ].HasBomb() /* &&	(n % numColumns) != (numColumns-1)*/)
	gridArray[n].IncrNumAdjacent();
    }

  // 7
  if(!( row+1 >= numRows || col-1 < 0))
    {
      if(gridArray[ (n+numColumns)-1 ].HasBomb() /* && (n % numColumns!=0)*/)
	gridArray[n].IncrNumAdjacent();
    }

  // 8
  if(!(row+1 >= numRows ))
    {
      if(gridArray[ (n+numColumns) ].HasBomb() )
	gridArray[n].IncrNumAdjacent();
    }

  // 9
  if(!( row+1 >= numRows || col+1 >= numColumns))
    {
      if(gridArray[ (n+numColumns)+1 ].HasBomb() /* &&(n % numColumns) != (numColumns-1)*/)
	gridArray[n].IncrNumAdjacent();
    }


  
}

void SweeperGrid::make_grid()
{
   
  
  int num_cells = numRows * numColumns,
    rand_num;
  
  //mistake made here: Note>> integer divided by interger = integer
  //                              vvv
  double bomb_density = ((double)numBombs / num_cells) * 100 ; //percentage of bomb density
  
  // dynamically-allocated array
  gridArray = new SweeperCell[num_cells];

  if(numRows < 5 || numColumns < 5 || bomb_density < 15 || bomb_density > 50)
    {
      std::cout << "Error: The bomb density must be between 15% and 50%" << std::endl;
      exit(0);
    }
 

  // srand(time(0));
  srand(0);
  int i=0;
  //Placing bombs into cells
  while(i < numBombs)
    {
      rand_num = (rand() % num_cells-1);
      if(!gridArray[rand_num].HasBomb() )
	{
	  PlaceBomb( (rand_num/numColumns) , (rand_num % numColumns) );
	  i++;
	}
    }

  for(int i =0; i < numRows; i++)
    {
      for(int j=0; j < numColumns; j++)
	Num_AdjBombs(i, j);
    }

}


// && !(n % numColumns=0)

// && !(n/numColumns = numRows-1)

// && !(n / numColumns = 0)

// && !(n % numColumns) = (numColumns-1)
