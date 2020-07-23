// File: < boggle.cpp >
// This program will read a grid of letters and a list of words
// then it will check if the words could be formed on the 5X5 grid
// of letters. Finally it will print out the word and followed with
// the word 'found' if the word could be formed or followed with the
// word 'not found' if the word could not be formed on anothe seperate
// text file.
//
// --------------------------------------------------------------------

#include<iostream>
#include<fstream> // ifstream, ofstream
#include<cstdlib>
#include<string>
#include<cstring> // strlen
#include <unistd.h>  // usleep, system (Unix Standard Library)

const int MAXROW = 7;
const int MAXCOL = 7;
const int MAXWORDS = 40;


struct Tile {
	char letter;
	bool used;
};


/* Function: read_grid
Returned: This function will import the grid each line seperately and will store it
"grid" array. It will store the words that needed to be searched in "words" array.
Additionally, the function will pass back the number of words that needed to be searched.
*/
void read_grid(std::ifstream &infile,     //P'back: passing the input file
	       Tile grid[MAXROW][MAXCOL], //P'back: passing the grid array
	       char words[MAXWORDS][80],  //P'back: passing the list of the words
	       int & word_num);           //P'back: count the number of words needed to be searched

bool search(char words[MAXWORDS][80],  //P'back: passing the list of the words
	    int word_num,              //Rec'd: the number of the word in words' list
	    int i,                     //Rec'd: the number of the letter in the word
	    Tile grid[MAXROW][MAXCOL], //P'back: passing the grid array
	    int n,                     //Rec'd:the number of the row in the gird
	    int m);                    //Rec'd:the number of the column in the grid 

/* Function: print_result
This function will print:the word found if the check value = 1
the word not found if the ckeck value = 0
*/
void print_result(std::ofstream &outfile,   //P'back: passing the output file
		  int k,                    //Rec'd: the number of the word in words' list
		  char words[MAXWORDS][80], //P'back: passing the list of the words
		  int  word_nums,           //Rec'd: the number of words needed to be searched
		  int check);               //Rec'd: 1 if the word found & 0 if the word not found

void print_grid(std::ofstream &outfile,     //P'back: passing the output file
		Tile grid[MAXROW][MAXCOL]); //P'back: passing the grid array


int main(int argc, char *argv[])
{
	using namespace std;
	int word_nums = 0;

	//check the number of input files 
	 if(argc != 3)
	{
	cout << "Usage: " << argc << endl;
	}

	Tile grid[MAXROW][MAXCOL];
	char words[MAXWORDS][80];

	//open the file that we want to read from
	//ifstream: Stream class to read from files
	ifstream infile(argv[1]);
	
	//check if the file opened
	//if not opened then print ERROR message
	if (!infile)
	{
		cout << "Error: unable to open example.dat" << endl;
		exit(1); //exit wiht failure
	}
	
	//open the file taht we want to write to
	//ofstream: Stream class to write on files
	
	ofstream outfile(argv[2]);
	//check if the file opened
	//if not opened then print ERROR message
	  if (!outfile)
	{
		cout << "Error: unable to open output.dat" << endl;
		exit(1);
	}

	  //call 'read_file' to read the grid of letters
	  //and the list of the words
	read_grid(infile, grid, words, word_nums);

	print_grid(outfile, grid);

	bool b;
	//k represent the number of the word in the list
	for (int k = 0; k < word_nums; k++)
	{
		//Checking every letter on the grid and comparing it with the word
		//i : the row of the grid
		for (int i = 1; i <= MAXROW - 2; i++)
		{
			//j : the column of the grid
			for (int j = 1; j <= MAXCOL - 2; j++)
			{
			  //b will be
			  //1:if the word could be formed
			  //0:if the word could not be formed
				b = search(words, k, 0, grid, i, j);
				if (b)
				{
				  print_result(outfile, k, words, word_nums, 1);
					break;
				}
				if (b)
					break;
			}
			if (b)
				break;
		}

		if (!b)
		  print_result(outfile, k, words, word_nums, 0);

		int rowIndex, colIndex;
		//Initializing all letters as not used
		for (rowIndex = 1; rowIndex <= MAXROW - 2; rowIndex++)
		{
			for (colIndex = 1; colIndex <= MAXCOL - 2; colIndex++)
			{
				grid[rowIndex][colIndex].used = false;
			}
		}
	}

    outfile << endl;
        
	//closing all files
	infile.close();
	outfile.close();
	return 0;
}


void read_grid(std::ifstream & infile, Tile grid[MAXROW][MAXCOL], char words[MAXWORDS][80], int &word_num)
{
	using namespace std;
	int rowIndex, colIndex;
	string str;

	//Filling 2D array will the grid letters
	//Begin with the first row
	for (rowIndex = 1; rowIndex <= MAXROW - 2; rowIndex++)
	{
		//getting a line of string which is combination of the letters
		infile >> str;
		//Filling the first column with 0s which is the border
		grid[rowIndex][0].letter = '0';

		
		for (colIndex = 1; colIndex <= MAXCOL - 2; colIndex++)
		{
			grid[rowIndex][colIndex].letter = str[colIndex - 1];
			grid[rowIndex][colIndex].used = false;
		}

		grid[rowIndex][MAXCOL - 1].letter = '0';

	}

	for (colIndex = 0; colIndex <= MAXCOL - 1; colIndex++)
	{
		grid[0][colIndex].letter = '0';
		grid[MAXROW - 1][colIndex].letter = '0';
	}




	int i;

	//Storing the words that we need to check if they could be formed 
	//in the grid.
	while (infile >> str)
	{
		for (i = 0; i < str.length(); i++)
		{
			words[word_num][i] = str[i];
		}
		words[word_num][i] = '\0';
		word_num++;
	}
}


bool search(char words[MAXWORDS][80], int word_num, int i, Tile grid[MAXROW][MAXCOL], int n, int m)
{
	using namespace std;
	
	//find what the last index in the word
	int len = strlen(words[word_num]) - 1;


	//if the letter is not what we're looking for
	if (words[word_num][i] != grid[n][m].letter)
		return 0;
	//if the current letter ot compare is the same
	//as the last letter in the word...then return true
	else if (i == len)
		return 1;

	//if the current letter is the same as the letter what we're looking for
	//then check if the next letter is around 
	//the previous one.
	else if (words[word_num][i] == grid[n][m].letter && grid[n][m].used == false)
	{
		grid[n][m].used = true;
		//is the next letter located on the right to the current letter
		if (search(words, word_num, i + 1, grid, n, m + 1))
			return 1;
		//is the next letter located on the left to the current letter
		else if (search(words, word_num, i + 1, grid, n, m - 1))
			return 1;
		//is the next letter located under the current letter
		else if (search(words, word_num, i + 1, grid, n - 1, m))
			return 1;
		//is the next letter located right down diagonally to the current  letter
		//Hopefully that will make sence :)
		else if (search(words, word_num, i + 1, grid, n - 1, m + 1))
			return 1;
		//is the next letter located left down diagonally to the current letter
		else if (search(words, word_num, i + 1, grid, n - 1, m - 1))
			return 1;
		//is the next letter located above the current letter
		else if (search(words, word_num, i + 1, grid, n + 1, m))
			return 1;
		//is the next letter located right up diagonally to the current letter
		else if (search(words, word_num, i + 1, grid, n + 1, m + 1))
			return 1;
		//is the next letter located left up diagonally to the current letter
		else if (search(words, word_num, i + 1, grid, n + 1, m - 1))
			return 1;
	        

	}
	return 0;
}


void print_result(std::ofstream &outfile, int k, char words[MAXWORDS][80], int  word_nums, int check)
{
	using namespace std;
	// len: the length of the word that we want to print
	int f, len = strlen(words[k]);

	//Case 1: the word found(check = 1)
	if (check == 1)
	{
		for (f = 0; f < len; f++)
		{
			outfile << words[k][f];
		}
		outfile << " found" << endl;
	}
	//Case 2: the word not found(check = 0)
	else if (check == 0)
	{
		for (f = 0; f < len; f++)
		{
			outfile << words[k][f];
		}
		outfile << " not found" << endl;
	}
}

void print_grid(std::ofstream &outfile, Tile grid[MAXROW][MAXCOL])
{
  using namespace std;

  int rowIndex, colIndex;

  for(rowIndex =1; rowIndex <= MAXROW-2; rowIndex++)
    {
      for(colIndex=1; colIndex <= MAXCOL-2; colIndex++)
	{
	  outfile << grid[rowIndex][colIndex].letter;
	}
      outfile << endl;
    }
}
