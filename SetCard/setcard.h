//Name:Abdulaziz Alshabibi

#ifndef SETCARD_H
#define SETCARD_H


#include<iostream>

enum ColorType {RED, GREEN, PURPLE};
enum ShadeType {SOLID, STRIPED, OPEN};
enum ShapeType {DIAMOND, SQUIGGLE, OVAL};


class SetCard
{
private:
    int number;
    ShadeType shade;
    ShapeType shape;
    ColorType color;

public:
//constructor
    SetCard();
//member function:
//       Initialize the member variables
    void Initialize(int newNumber,
                             ColorType newColor,
                             ShadeType newShade,
                             ShapeType newShape);

//member function
    int GetNumber()const;

//member function
    ColorType GetColor()const;

//member function
    ShadeType GetShade()const;

//member function
    ShapeType GetShape()const;

//member function: 
//       return 1 if the three sets make up a set
//       return 0 if the three sets don't make up a set
    bool IsSet(SetCard card2, SetCard card3)const;

//member function:
//       Convert the letters that descripe the set to readable words
    std::string ToString()const;


//friend overloaded input operator
    friend std::istream& operator>>(std::istream &in, SetCard &aCard);

//friend overloaded output operator
    friend std::ostream& operator<<(std::ostream &out, SetCard aCard);


};

#endif // SETCARD_H
