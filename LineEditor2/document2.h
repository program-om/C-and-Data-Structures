// File: document2.h
// This is the header file for the document class using circular doubly linked list
//
//
//
// ------------------------------------------------------------------------
// Class: CS 215                         Instructor: Dr. Deborah Hwang
// Assignment: Project 6                 Date assigned: April 7, 2017
// Programmer: Abdulaziz Alshabibi       Date completed: April 17, 2017

#ifndef DOCUMENT2_H_
#define DOCUMENT2_H_

//Precessors
#include<iostream>
#include<string>  //std::string

template<class ItemType>
struct NodeType{
  ItemType line;                    //            _NODE______________
  NodeType<ItemType>* prev;         //           |prev | line  | next|
  NodeType<ItemType>* next;         // date type |_____|_______|_____|
};                                  //             ^^     ^^     ^^
                                    //           address string address


class Document
{
private:
  NodeType<std::string>* headPtr;  // headPtr points to the header node
  NodeType<std::string>* currentPtr; // currentPtr keep tarcking the current line
  
  //Helper functions, only used inside the class and CAN'T used outside the class
  int GetLength() const; // return the length of the list
  void SetCurrent_backward(int n); // move the currentPtr to the backward direction
  void SetCurrent_forward(int n);  // move the currentPTr to the forward direction
  
public:
        // Constructor
	Document(); // Create an empty document
	
	// Copy constructor
	Document(const Document & source); // Copy the 'source' list into this object
	
	// Destructor
	~Document(); // Deallocate all the nodes including the header node
	
	// Overloaded assignment operator
	Document& operator=(const Document & source); // make a copy of 'source' list

	
	void Load(std::istream &in); // Load what is in the file to document

	void MakeEmpty(); // Make the document empty

	bool IsEmpty()const; // Return true if the document is empty,
                             // return false otherwise.

	void Insert(std::string newLine); // Insert a line in front of the current line

	void Append(std::string newLine); // Insert a line at the end of the document

	void Replace(std::string newLine); // Replace the current line with the new line

	void Erase(); // Erase the current line

	bool Find(std::string target); // Return true if the sub-string found,
                                       // then set the line that contain the sub-string to be 
                                       // current line.
                                       // Return false if the sub-string not found.
                                       

	void SetCurrent(int n); // Set the current line to the n index (i.e. 0 is the first node)

	void MoveCurrent(int n); // Move the current line |n| places 
                                 // if the n value is negative the movement should be backward

	void WriteLine(std::ostream &out)const; // Write the current line to the stream 'out'

	void WriteAll(std::ostream &out)const; // Write the whole document to the stream 'out'

}; // end Document class
#endif
