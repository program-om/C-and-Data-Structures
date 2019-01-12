//
//File: sweeper.cpp
// This is the driver for the mine sweeper game which will ask the user for
// the command then it will call the function that will implement the command
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
// Class: CS 215                               Instructor: Dr. Deborah Hwang
// Assignment: Project 4                       Date assigned: March 17, 2017
// Programmer:Abdulaziz Alshabibi              Date completed: March 27.2017

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "sweepercell.h" //header file of sweepercell file
#include "sweepergrid.h" //header file of sweepergrid file

int main(int argc, char *argv[])
{

    using namespace std;
    //checking the number of the command-line arguments
    if (argc != 4)
    {
        cout << "ERROR: You're missing one or more input values." << endl;
        SweeperGrid grid;
    }
    int cols, rows, bombs, row, col;
    char command;

    //converting the strings to integers
    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    bombs = atoi(argv[3]);

    SweeperGrid grid(rows, cols, bombs);

    // displaying the grid for  the user at beginning of the game
    cout << endl;
    grid.WriteGrid(cout);
    cout << endl;

    cout << "Enter u to uncover, m to mark, k to unmark, q to quit: ";
    cin >> command;

    // since the user did not entered the quit command or he/she has won the game
    while (command != 'q')
    {

        //asking the user for the position of the cell that wanted to uncover
        cout << "Enter a location (row col) to uncover: ";
        cin >> row >> col;

        try
        {
            if (command == 'u')
            {
                if (grid.Uncover(row, col))
                {
                    cout << "You've uncovered a mine!  Game over!!" << endl;
                    break;
                }
            }

            else if (command == 'm')
                grid.Mark(row, col);

            else if (command == 'k')
                grid.Unmark(row, col);
            else{
                cout << "Error: Invalid command!" << endl;
                //flush(cin);
            }

            //end of try's block
        }
        catch (const string msg)
        {
            cout << msg << endl;
        }

        if (grid.GameWon())
        {
            cout << "You won the game!" << endl;
            break;
        }
        cout << endl;
        grid.WriteGrid(cout);
        cout << endl;

        //as long as the user did not quit or has won the game, ask him/her for the command
        cout << "Enter u to uncover, m to mark, k to unmark, q to quit: ";
        cin >> command;

    } //end of the loop

    // uncovering all the cells on the grid
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            grid.Uncover(i, j);
    }

    // display the grid at the end of the game
    cout << endl;
    grid.WriteGrid(cout);
    cout << endl;

    return 0;
}
