// File: problem1.cpp
// A program that tests ExchangeSort
//
// Class: CS 215                     Instructor: Dr. Deborah Hwang
// Date: March 28 & 30, 2017
// Assignment: Practical Exam 2, Problem 1
// Programmer: *** FILL IN YOUR NAME ***

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void ReadVector(std::vector<int> &v, std::istream &in);
void WriteVector(std::vector<int> &v, std::ostream &out);
void ExchangeSort(std::vector<int> &v);
void swap(int &i, int &j);

int main(int argc, char *argv[])
{
  using namespace std;

  if (argc != 3)
  {
    cout << "ERROR: Invalid number of command-line arguments" << endl;
    exit(0);
  }

  ifstream infile(argv[1]);
  if (!infile)
  {
    cout << "The input file can not be openned!" << endl;
    exit(0);
  }

  ofstream outfile(argv[2]);
  if (!outfile)
  {
    cout << "The input file can not be openned!" << endl;
    exit(0);
  }

  vector<int> theVector;

  // Read in data from file
  ReadVector(theVector, infile);

  // Write the data to the screen
  cout << "The elements of vector v are: " << endl;
  // *** WRITE CALL TO WriteVector TO DISPLAY ON SCREEN HERE ***
  WriteVector(theVector, cout);

  // Sort the data
  // *** WRITE CALL TO ExchangeSort HERE ***
  ExchangeSort(theVector);

  // Write the sorted data to the file
  outfile << "\nAfter sorting, the elements of vector v are: " << endl;
  // *** WRITE CALL TO WriteVector TO WRITE TO OUTPUT FILE HERE ***
  WriteVector(theVector, outfile);

  return 0;
}

void ReadVector(std::vector<int> &v, std::istream &in)
{
  int value;
  v.clear();
  while (in >> value)
    v.push_back(value);
}

// *** WRITE THE WriteVector FUNCTION DEFINITION HERE ***
void WriteVector(std::vector<int> &v, std::ostream &out)
{
  // n is the size of the vector
  int n = v.size();
  int i;

  for (i = 0; i < n - 1; i++)
    out << v[i] << ", ";

  out << v[i] << std::endl;
}

// *** WRITE THE ExchangeSort FUNCTION DEFINITION HERE ***
void ExchangeSort(std::vector<int> &v)
{
  // n is the size of the vector
  int n = v.size();

  for (int i = 0; i <= (n - 2); i++)
  {
    for (int j = (i + 1); j < n; j++)
    {
      if (v[j] < v[i])
        swap(v[i], v[j]);
    }
  }
}

void swap(int &i, int &j)
{
  int temp;
  temp = i;
  i = j;
  j = temp;
}
