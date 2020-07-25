// File: timer.h
// Definition of the Timer class
//
// ----------------------------------------------------------------------
// Class: CS 215                      
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: FILL IN YOUR NAME HERE!!
// Date: February 14 & 15, 2017 - Modified on 25/7/2020

#ifndef TIMER_H_
#define TIMER_H_

#include <iostream>

enum RelationType {LESS, EQUAL, GREATER};

class Timer
{
   public:
      // Default constructor
      Timer ();  // sets value to 00:00
      // Accessors
      int GetMinutes() const;  // returns minutes attribute
      int GetSeconds() const;  // returns seconds attribute

      void Initialize(int minutes_b, int seconds_b);
      void Tick();
      RelationType CompareTo(Timer C);
      friend std::ostream & operator<<(std::ostream &output, Timer &C);

   private:
      int minutes, seconds;  // Represents MM:SS 

};  // end Timer class

#endif // TIMER_H_
