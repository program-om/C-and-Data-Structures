// File: timer.cpp
// Definition of the Timer class operations
//
// ----------------------------------------------------------------------
// Class: CS 215
// Assignment: Programming Practical Exam 1, Problem 2
// Programmer: Abdulaziz Alshabibi
// Date: February 14 & 15, 2017 - Modified on 25/7/2020

#include "timer.h"
#include <iostream>

int main() { return 0; }

Timer::Timer()
{
  minutes = 0;
  seconds = 0;
}

int Timer::GetMinutes() const
{
  return minutes;
}

int Timer::GetSeconds() const
{
  return seconds;
}

void Timer::Initialize(int minutes_b, int seconds_b)
{
  minutes = minutes_b;
  seconds = seconds_b;
}

void Timer::Tick()
{
  //when we did not reach the end of the minute continue decrementing the
  //seconds
  if (minutes > 0 && seconds > 0)
  {
    seconds -= 1;
  } else if (minutes > 0 && seconds == 0)
  { //reduce one minute and set seconds to 59 if we reached the end of the minute
    minutes -= 1;
    seconds = 59;
  }
}

RelationType Timer::CompareTo(Timer C)
{
  if (minutes < C.minutes)
    return LESS;
  else if (minutes > C.minutes)
    return GREATER;
  else if (minutes == C.minutes && seconds < C.seconds)
    return LESS;
  else if (minutes == C.minutes && seconds > C.seconds)
    return GREATER;
  else
    return EQUAL;
}

std::ostream &operator<<(std::ostream &out, Timer aTimer)
{
  if (aTimer.GetMinutes() < 10) out << '0';
  out << aTimer.GetMinutes() << ':';
  if (aTimer.GetSeconds() < 10) out << '0';
  out << aTimer.GetSeconds();
  return out;
}