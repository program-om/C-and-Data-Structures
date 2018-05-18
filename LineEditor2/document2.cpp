// File: document2.cpp
// This file contains document class operations which will be called in the main
// program to excute the user commands. Some of them will be used only inside the class.
//
// ------------------------------------------------------------------------
// Class: CS 215                         Instructor: Dr. Deborah Hwang
// Assignment: Project 6                 Date assigned: April 7, 2017
// Programmer: Abdulaziz Alshabibi       Date completed: April 17, 2017

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include"document2.h"



Document::Document()
{
  headPtr = new NodeType<std::string>; // creating the header node
  // make the header node points to itself
  headPtr->next = headPtr; 
  headPtr->prev = headPtr;
  // set the current line to the header node
  currentPtr = headPtr;
}

Document::Document(const Document &source)
{
  // Create the header node
  headPtr = new NodeType<std::string>;
  headPtr->next = headPtr;
  headPtr->prev = headPtr;

   // Copy data nodes
   // Start at first data node of original
   NodeType<std::string> *scanPtr = source.headPtr->next;  
   while (scanPtr != source.headPtr)  // stop at original's header node
   {
      // Create copy node
     NodeType<std::string> *newNode = new NodeType<std::string>;
      newNode->line = scanPtr->line;
      // Insert between the last node and the header node
      newNode->prev = headPtr->prev;  
      newNode->next = headPtr;        
      headPtr->prev->next = newNode;  // headPtr->prev->next is 'next' of the Node that will be before the newNode
      headPtr->prev = newNode;        // headPtr->prev is the  

      if(source.currentPtr == scanPtr)
	currentPtr = newNode;
      
      // Increment scanPtr
      scanPtr = scanPtr->next;

      
   }
   
}

// Destructor
Document::~Document()
{
  NodeType<std::string>* tempPtr;
  NodeType<std::string>* headerNode = headPtr;
  headPtr = headPtr->next;

  while(headPtr != headerNode)
    {
      tempPtr = headPtr;
      headPtr = headPtr->next; 
      delete tempPtr;
    }
  delete headerNode;
}

Document& Document::operator=(const Document & source)
{
  // Make a copy of the original
   Document theCopy(source);
   // Swap contents of this object with the copy
   // Using std::swap from the STL <algorithm> library
   std::swap(theCopy.headPtr, headPtr);
   std::swap(theCopy.currentPtr, currentPtr);
   // Return this object -- upon return, theCopy containing the
   //                       original data will be destroyed
   return *this;  // 'this' is a pointer, so need to dereference.
}


void Document::Load(std::istream &in)
{
	//replace any lines that already exist
	MakeEmpty();
	std::string tempString;
	NodeType<std::string>* location; //location is the input line from the file
	NodeType<std::string>* current_line; //temporary pointer which will store the first line

	//the first line
	std::getline(in, tempString);
	location = new NodeType<std::string>;
	location->line = tempString;

	location->prev = currentPtr;
	location->next = currentPtr;

	currentPtr->prev = location;
	currentPtr->next = location;
	currentPtr = location;

	//storing the first line in a temporary pointer
	current_line = location;

	// while there is NO lines in the input file, the loop will STOP.
	while (std::getline(in, tempString))
	{
	  
	  location = new NodeType<std::string>;
	  location->line = tempString;

	  location->prev = currentPtr;
	  location->next = currentPtr->next;

	  currentPtr->next->prev = location;
	  currentPtr->next = location;

	  currentPtr = location;
	}
	//setting the current line to the first line
	currentPtr = current_line;
}


void Document::MakeEmpty()
{
  NodeType<std::string>* tempPtr;
  NodeType<std::string>* deletePtr = headPtr->next;

  while(deletePtr != headPtr)
    {
      tempPtr = deletePtr;
      deletePtr = deletePtr->next;
      delete tempPtr;
    }

  headPtr->prev = headPtr;
  headPtr->next = headPtr;
  
  currentPtr = headPtr;
}


bool Document::IsEmpty() const
{
  // The list will be empty when the header node points to itself
  if (headPtr->prev == headPtr && headPtr->next == headPtr)
	   return true;
        else return false;
	
}


void Document::Insert(std::string newLine)
{
  NodeType<std::string>* NewNode = new NodeType<std::string>;
  NewNode->line = newLine;

  //set new node links to predecessor and successor
  NewNode->prev = currentPtr->prev;
  NewNode->next = currentPtr;

  currentPtr->prev->next = NewNode;
  currentPtr->prev = NewNode;

  //setting th currentPtr to the new node
  currentPtr = NewNode;
	
}


void Document::Append(std::string newLine)
{
  NodeType<std::string>* NewNode = new NodeType<std::string>;
  NewNode->line = newLine;

  NewNode->prev = headPtr->prev;
  NewNode->next = headPtr;

  headPtr->prev->next = NewNode;
  headPtr->prev = NewNode;
  currentPtr = NewNode;
  
}


void Document::Replace(std::string newLine)
{
  if (IsEmpty())
	{
	  throw std::string( "ERROR: Replacment command could not be done because the document is Empty!!");
	}

	currentPtr->line = newLine;
}


void Document::Erase()
{
	if (IsEmpty())
	  throw std::string("ERROR: Deletion command could not be done because the document is Empty!!");

	NodeType<std::string>* tempPtr = currentPtr;
	//NodeType<ItemType>* deletePtr = headPtr->next;

	if(currentPtr->next != headPtr)
	  {
	    currentPtr->prev->next = currentPtr->next;
	    currentPtr->next->prev = currentPtr->prev;
	    // setting the current pointer to the next node
	    currentPtr = currentPtr->next;
	    delete tempPtr;
	  }
	else
	  {
	    currentPtr->prev->next = currentPtr->next;
	    currentPtr->next->prev = currentPtr->prev;
	    // setting the current pointer to the previous node
	    currentPtr = currentPtr->prev;
	    delete tempPtr;
	  }
		

}


bool Document::Find(std::string target)
{
  NodeType<std::string>* location = headPtr->next;
  std::string line;
  
  while(location != headPtr)
	{
	  line = location->line;
		if (line.find(target) != std::string::npos)
		{
			currentPtr = location;
			return true;
		}
		location = location->next;
	}
	
  std::cout << "The target string is NOT found and the current line remain the same" << std::endl;
	return false;

}


void Document::SetCurrent(int n)
{
  // NodeType<std::string>* location = currentPtr->next;
  // int i=1;
  // bool done = false;
  
  // 	 while(location != headPtr && i <= n && done != true)
  // 	{
  // 	  if(i == n)
  // 	    {
  // 	      currentPtr = location;
  // 	      done = true;
  // 	    }
	  
  // 	  location = location->next;
  // 	  i++;
  // 	}

  // 	 if(done == false)
  // 	   throw std::string ("ERROR: The value of n is invalid!");

  /*
    NOTE: There is an easier way to do this!!!!
          Anyway this way works too :)
   */

  if(n >= GetLength() || n < 0)
    throw std::string("ERROR: The value of n in invalid!");

	//locating the position of the current line
	NodeType<std::string>* location = currentPtr;
	int i =-1;
	while(location != headPtr)
	  {
	    i++;
	    location = location->prev;
	  }
	//finding the difference between the current line and target line
	//so i will know hom many nodes do i need to reach the target node
	int diff = n - i;

	if(diff > 0)
	  SetCurrent_forward(diff);
	else if(diff < 0)
	  SetCurrent_backward(diff*-1);
}


void Document::MoveCurrent(int n)
{
	if (n > 0)
	  SetCurrent_forward(n);
	else if (n < 0)
	  SetCurrent_backward(n*(-1)); // changing the sign of n

}

// Displaying the current line in the list
void Document::WriteLine(std::ostream &out) const
{
  if(!IsEmpty())
    out << currentPtr->line << std::endl;
}

// Displaying the list
void Document::WriteAll(std::ostream &out) const
{
  NodeType<std::string>* location = headPtr->next; // the first node in the list
  
	for(int i=0; i < GetLength(); i++)
	  {
	   out << location->line << std::endl;
	   
	   location = location->next;
	  }
}

//----------------------------------------------------|
// Additional Functions  - Private section            |
//----------------------------------------------------|


int Document::GetLength() const
{
  // The length exclude the header node
  NodeType<std::string>* location = headPtr->next; //pointing 'location' to the first node
   int size = 0;
  
   while(location != headPtr) // while it did not reach the end of the list
	{
	  size++; // increment the size by one
	  location = location->next; // move to the next node
	}
  return size;
}

void Document::SetCurrent_forward(int n)
{
NodeType<std::string>* location = currentPtr->next;
  int i=1;
  bool done = false;
  
	 while(location != headPtr && i <= n)
	{
	  if(i == n)
	    {
	      currentPtr = location;
	      done = true;
	    }
	  
	  location = location->next;
	  i++;
	}

	 if(done == false)
	   throw std::string ("ERROR: The value of n is invalid!");
}

void Document::SetCurrent_backward(int n)
{
  NodeType<std::string>* location = currentPtr->prev;
  int i=1;
  bool done = false;
  
	 while(location != headPtr && i <= n)
	{
	  if(i == n)
	    {
	      currentPtr = location;
	      done = true;
	    }
	  
	  location = location->prev;
	  i++;
	}

	 if(done == false)
	   throw std::string ("ERROR: The value of n is invalid!");
}

