// File: settester.cpp
// < Description of what is in this file.>
//
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
//Class: CS 215                     Instructor: Dr. Deborah Hwang
//Assignment:Project 2              Date assigned: Feb  , 2017
//Programmer:Abdulaziz Alshabibi    Date completed: Feb 15, 2017
#include <iostream>
#include<sstream>
#include<string>
#include<fstream> // ifstream, ofstream
#include "setcard.h"



int  main(int argc, char *argv[])
{
    using namespace std;
    //Checking if the number of command-line match what is expected
    //which two.
    if(argc != 2)
    {
        cout << "ERROR: The number of command-line arguments must two"
             << endl;
    }
    //open the input and output files then check if they are opened or NOT.
    //if they're not opened, then ERROR message will be displayed

    //First: the input file
    ifstream infile(argv[1]);
    if(!infile)
    {
        cout << "The argv[1] can't be opened" << endl;
    }
    //Second: the output file
    ofstream outfile(argv[2]);
    if(!infile)
    {
        cout << "The argv[2] can't be opened" << endl;
    }


    SetCard Card, Card2, Card3;
    int sets;
    string str, set1, set2, set3;

    infile >> sets;

    outfile << "SET TESTER" << endl;
    outfile  << endl;

    for(int i=0; i < sets; i++)
    {
        Card.Initialize( Card.GetNumber(), Card.GetColor(), Card.GetShade(), Card.GetShape() );
        //this one will read from the file
        infile >> Card;
        outfile << Card ;
        //and this one will print out on the screen
        outfile << " : " << Card.ToString() << endl;

        infile >> Card2;
        outfile << Card2 ;
        outfile << " : " << Card2.ToString() << endl;

        infile >> Card3;
        outfile << Card3;
        outfile << " : " << Card3.ToString() << endl;

	//if the three sets do make up a set
        if(Card.IsSet(Card2, Card3))
            outfile << "make up a set" << endl;
        //if they don't make up a set
        else
            outfile << "do not make up a set" << endl;

        outfile << endl;
    }

    infile.close();
    outfile.close();
    return 0;

}
