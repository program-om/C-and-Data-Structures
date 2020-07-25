// File: main.cpp
// A program to test the Timer class
//
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: Abdulaziz Alshabibi
// Date: February 14 & 15, 2017

#include <iostream>      // <<, >>, endl;
#include "timer.h"       // Timer class

int main(int argc, char *argv[])  // no command line arguments
{
   using namespace std;

   Timer t1, t2;       // Default constructed: 00:00

   cout << "Default constructed t1" << endl;
   cout << "   minutes: " << t1.GetMinutes() << endl;
   cout << "   seconds: " << t1.GetSeconds() << endl;

   t1.Initialize(0,5);
   cout << t1 << endl;
   t1.Tick();
   cout << t1 << endl;

   t1.CompareTo(t2);
   return 0;
}  // end main
