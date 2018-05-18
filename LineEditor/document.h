#ifndef DOCUMENT_H
#define DOCUMENT_H

#include<vector>
#include<iostream>
//No need to include the cpp file!!


class Document
{
 private:
  std::vector<std::string> lines; // vector lines contain the document lines
  int currentPos;  // Current position

 public:
  // Constructor
  Document(); // Create an empty document

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
                                       

  void SetCurrent(int n); // Set the current line to the n value

  void MoveCurrent(int n); // Move the current line |n| places 
  // if the n value is negative the movement should be backward

  void WriteLine(std::ostream &out)const; // Write the current line to the stream 'out'

  void WriteAll(std::ostream &out)const; // Write the whole document to the stream 'out'

}; // end Document

#endif
