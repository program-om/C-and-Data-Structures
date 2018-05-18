// File: huffman.cpp
//
// This is huffman class driver, the program will receive the codetree file
// Initially the program will display the tree.
// Then it will ask the user whether he/she would like to encode or decode.
// Then it will ask the user for the names of the input file and output file.
//
// ------------------------------------------------------------------------
// Class: CS 215                         Instructor: Dr. Deborah Hwang
// Assignment: Project 7                 Date assigned: April 19, 2017
// Programmer: Abdulaziz Alshabibi       Date completed: April 29, 2017

#include<iostream>
#include<string>  // .c_str() , string
#include<fstream> // ifstream, ofstream
#include<cstdlib> // exit(1);
#include<cctype> // tolower
#include"huffman.h" // header of the class 'HuffmanTree'


int main(int argc, char *argv[])
{
  using namespace std;

  // creating an object of 'HuffmanTree' class
  HuffmanTree tree;
  char command;
  string plaintext_file, output_file, compressed_file;

  // checking the number of the command-line argument
  if(argc != 2)
    {
      cout << "Invalid number of command-line arguments!" << endl;
      exit(1);
    }

  // opening the codetree file
  ifstream treeFile(argv[1]);
  if(!treeFile)
    {
      cout << "Error: unable to open codetree file" << endl;
      exit(1);
    }
 
  tree.Load(treeFile);

  // this line is commented out because it cause an error
  // that i can't figure out how to fix it.
  //VVVVVVVVVVVVVVVV
  //tree.Write(cout);

  do{

  cout << "Please choose one of:" << endl << endl << endl;
  cout << "   E - Encode a message" << endl;
  cout << "   D - Decode a message" << endl;
  cout << "   Q - Quit the program" << endl << endl;

  cout << "Enter your choice: " ;
  cin >> command;
  tolower(command);

  if(command == 'e')
    {
      cout << "Enter the name of a plaintext message file: " ;
      cin >> plaintext_file;
      cout << "Enter name of output file: " ;
      cin >> output_file;

      //opening the input and output files
      ifstream inFile(plaintext_file.c_str());
      ofstream outFile(output_file.c_str());
std::cout << "1- i was here" << std::endl;
      // calling encode function to encode the inFile
      tree.Encode(inFile, outFile);

  
    }

  else if(command == 'd')
    {
      cout << "Enter the name of a compressed message file: " ;
      cin >> compressed_file;
      cout << "Enter name of output file: " ;
      cin >> output_file;

      //opening the input and output files
      ifstream inFile(compressed_file.c_str());
      ofstream outFile(output_file.c_str());

      tree.Decode(inFile, outFile);
    }
  
  else if(command != 'q')
    cout << "Invalid command"<< endl;

  }while(command != 'q');

  return 0;
} // end of main
