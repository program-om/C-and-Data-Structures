#include<iostream>
#include"setcard.h" //calling the header of the class
#include<string>
#include<sstream>

SetCard::SetCard()
{
  //Initialize all values
    number = 1;
    color = RED;
    shade = SOLID;
    shape = DIAMOND;
}

void SetCard::Initialize(int newNumber,      //the number that will be assigned to 'number' variable
                         ColorType newColor, //the value that will be assigned to 'color' variable
                         ShadeType newShade, //the value that will be assigned to 'shade' variable
                         ShapeType newShape) //the value that will be assigned to 'shape' variable
{
  //if any value is not valid, then ERROR messeage will be thrown
    if(newNumber < 1 || newNumber > 3)
        throw std::string("The number value is INVALID");
    if(newColor != RED && newColor != GREEN && newColor != PURPLE)
        throw std::string("The color value is INVALID");
    if(newShade != SOLID && newShade != STRIPED && newShade != OPEN)
        throw std::string("The shade value is INVALID");
    if(newShape != DIAMOND && newShape != SQUIGGLE && newShape != OVAL)
        throw std::string("The shape value is INVALID");

    
    number = newNumber;
    color = newColor;
    shade = newShade;
    shape = newShape;


}

int SetCard::GetNumber()const
{
    return number;
}

ColorType SetCard::GetColor()const
{
    return color;
}

ShadeType SetCard::GetShade() const
{
    return shade;
}

ShapeType SetCard::GetShape() const
{
    return shape;
}

//This function will return 1 if the three sets make up a set
//                      and 0 if the three sets don't make up a set
bool SetCard::IsSet(SetCard card2, SetCard card3)const 
{
    //return 1 if this card, card2, and card3

    //otherwise: return 0
    //if two characteristics are the same on two cards
    //then that's mean they can't make up a set
  if( (//check if the number characteristic is same in all three sets
         (number == card2.number &&
       number == card3.number )||
      (
       //check if the number characteristic is unique in all three sets
       number != card2.number &&
       number != card3.number &&
       card2.number != card3.number
       )
         )&&
       (
       (
	//check if the color characteristic is same in all three sets
       (color == card2.color &&
            color == card3.color) ||
            (
	     //check if the color characteristic is unique in all three sets
            color != card2.color &&
            color != card3.color &&
            card2.color != card3.color
            )
       )
        )
       &&
       (
	//check if the shade characteristic is same in all three sets
       (shade == card2.shade &&
            shade == card3.shade) ||
        //check if the shade characteristic is unique in all three sets
       (
            shade != card2.shade &&
            shade != card3.shade &&
            card2.shade != card3.shade
            )
        )
       &&
  (
   //check if the shape characteristic is same in all three sets
     (shape == card2.shape &&
            shape == card3.shape) ||
     //check if the shape characteristic is unique in all three sets
            (
            shape != card2.shape &&
            shape != card3.shape &&
            card2.shape != card3.shape
            )
   )
       )
       return true;


    else
        return false;

}

//This function will convert the combination of one number
//and three letters which is the input from the input file
//to a string
std::string SetCard::ToString() const
{
    std::string str;
    if(number == 1)
         str = " ONE";
    else if(number == 2)
          str = " TWO";
    else if(number == 3)
          str = " THREE";

    if(color == RED)
          str += " RED";
    else if(color == GREEN)
            str += " GREEN";
    else if(color == PURPLE)
        str += " PURPLE";

    if(shade == SOLID)
        str += " SOLID";
    else if(shade == STRIPED)
        str += " STRIPED";
    else if (shade == OPEN)
        str += " OPEN";

    if(shape == DIAMOND)
        str += " DIAMOND";
    else if (shape == SQUIGGLE)
        str += " SQUIGGLE";
    else if (shape == OVAL)
        str += " OVAL";

        return str;

}

std::istream& operator>>(std::istream &in, SetCard &aCard)
{
        std::string str;
        in >> str;

        if(in.fail())
            return in;

        if( (str[0] != '1' && str[0] != '2' && str[0] != '3') ||
            (str[1] != 'R' && str[1] != 'G' && str[1] != 'P') ||
            (str[2] != 'L' && str[2] != 'S' && str[2] != 'O') ||
            (str[3] != 'D' && str[3] != 'S' && str[3] != 'O')    )

        {
            in.setstate (std::ios_base::failbit);
            return in;
        }
        if(str[0] == '1')
            aCard.number = 1;
        else if(str[0] == '2')
            aCard.number = 2;
        else if(str[0] == '3')
            aCard.number = 3;

        if (str[1] == 'R')
            aCard.color = RED;
        else if (str[1] == 'G')
            aCard.color = GREEN;
        else if (str[1] == 'P')
            aCard.color = PURPLE;

        if (str[2] == 'L')
            aCard.shade = SOLID;
        else if (str[2] == 'S')
            aCard.shade = STRIPED;
        else if (str[2] == 'O')
            aCard.shade = OPEN;


        if (str[3] == 'D')
            aCard.shape = DIAMOND;
        else if (str[3] == 'S')
            aCard.shape = SQUIGGLE;
        else if (str[3] == 'O')
            aCard.shape = OVAL;


    return in;
}


//this function will print the whole sentence(readable way of set's characteristics)
std::ostream& operator<<(std::ostream &out, SetCard aCard)
{
    std::string str;

    if(aCard.number == 1)
        str = '1';
    else if(aCard.number == 2)
        str = '2';
    else if(aCard.number == 3)
        str = '3';

    if(aCard.color == RED)
        str += 'R';
    else if (aCard.color == GREEN)
        str += 'G';
    else if (aCard.color == PURPLE)
        str += 'P';

    if(aCard.shade == SOLID)
        str += 'L';
    else if(aCard.shade == STRIPED)
        str += 'S';
    else if(aCard.shade == OPEN)
        str += 'O';

    if(aCard.shape == DIAMOND)
        str += 'D';
    else if(aCard.shape == SQUIGGLE)
        str += 'S';
    else if(aCard.shape == OVAL)
        str += 'O';

 out << str;

    return out;
}
