// File: editor2.cpp
// This main program will work as editor. It will receive the command
//      from the user then it will call the required functions
//      to do what the user asked.
//
// The document class store a circular doubly linked list of lines that initially loaded from the input file.
// It contains also a set of operations that could be done to the list like insert,
// delete, etc.
//
// ------------------------------------------------------------------------
// Class: CS 215                         Instructor: Dr. Deborah Hwang
// Assignment: Project 6                 Date assigned: April 7, 2017
// Programmer: Abdulaziz Alshabibi       Date completed: April 17, 2017

#include<iostream>
#include<fstream> // ofstream
#include<vector> 
#include<string>
#include<cstdlib> // exit(0)
#include"document2.h" // document class

/* Function: help
   Purpose: The function will display the help menu when it will be called
*/
void help();

int main(int argc, char *argv[])
{
        using namespace std;
  
        //creating an object
	Document d1;
	
	char command; // command letter
	string filename, line;
	int n;

        //Checking if the number of command-line match what is expected
        //which is two.
	if(argc != 2)
	{
		cout << "ERROR: The number of input files is not correct!" << endl;
		exit(1);
	}

	// Open the input file
	ifstream infile(argv[1]);
	// Check if it's openned!
	if (!infile)
	{
		cout << "ERROR: The file is NOT openned!" << endl;
	}

        // Load what is in the file to document
	d1.Load(infile);


        do{
	  
	//recieving the command from the user
	cout << "> ";
        cin >> command; // setting the command character to command variable
	
	cin.ignore(); //cin.igonre by the default ignore just one character
                      //use parameters to extract more than one character

	// Checking what is the command, then doing what should be done based on that
		if (command == 'L' || command == 'l')
		{
			cin >> filename;
			ifstream inFile(filename.c_str());
			d1.Load(inFile);
		}

		else if (command == 'E' || command == 'e')
			d1.MakeEmpty();

		else if (command == 'I' || command == 'i')
		{
			getline(cin, line);
			d1.Insert(line);
		}

		else if (command == 'A' || command == 'a')
		{
			getline(cin, line);
			d1.Append(line);
		}

		else if (command == 'R' || command == 'r')
		{
		  try{
			getline(cin, line);
			d1.Replace(line);
			
		  }catch(const string msg)
		    {
		     cerr << msg << endl;
		    }
		}

		else if (command == 'D' || command == 'd')
		  {
		    try{
			d1.Erase();
			
		    }catch(const string msg)
		    {
		     cerr << msg << endl;
		    }
		  }

		else if (command == 'F' || command == 'f')
		{
			getline(cin, line);
			d1.Find(line);
		}

		else if (command == 'S' || command == 's')
		{
		  try{
			cin >> n;
			d1.SetCurrent(n);
			
		  }catch(const string msg)
		    {
		     cerr << msg << endl;
		    }
		}

		else if (command == 'M' || command == 'm')
		{
		  try{
			cin >> n;
			d1.MoveCurrent(n);

		  }catch(const string msg)
		    {
		     cerr << msg << endl;
		    }
		}

		else if (command == 'C' || command == 'c')
		{
			if (!d1.IsEmpty())
			{
				d1.WriteLine(cout);
			}
			else
				cout << "ERROR: The document is empty!" << endl;
		}

		else if (command == 'P' || command == 'p')
			d1.WriteAll(cout);

		else if (command == 'W' || command == 'w')
		{
			cin >> filename;
			ofstream outFile(filename.c_str());
			if (outFile)
				d1.WriteAll(outFile);
			else
				cout << "ERROR: The File can not be openned!" << endl;
			
			outFile.close();  //Notice that the file should be colsed inside
			                  //the scope that openned in it.
		}

		else if (command == 'H' || command == 'h')
			help();
		
	}while (command != 'Q' && command != 'q'); //when the user hit q or Q, the loop will stop

	
	return 0;
}

// Function: help
// Display the help menu
void help()
{
	using namespace std;
	cout << endl << "This line editor can do the following commands:"       << endl;
	cout << endl << "  L file     load file into this editor"               << endl;
	cout <<         "  E          clear document"                           << endl;
	cout <<         "  I line   - insert line in front of current line"     << endl;
	cout <<         "  A line   - append line to end of document"           << endl;
	cout <<         "  R line   - replace current line"                     << endl;
	cout <<         "  D        - delete the current line"                  << endl;
	cout <<         "  F target - makes line containing target current line"<< endl;
	cout <<         "  S n      - set current line to nth line"             << endl;
	cout <<         "  M n      - move current line n places"               << endl;
	cout <<         "  C        - display current line to screen"           << endl;
	cout <<         "  P        - display entire document to screen"        << endl;
	cout <<         "  W file   - write document to file"                   << endl;
	cout <<         "  H        - display this list of commands"            << endl;
	cout <<         "  Q        - quit the editor (does not save changes)"  << endl << endl;

}
