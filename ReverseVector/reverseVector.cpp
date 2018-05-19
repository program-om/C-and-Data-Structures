//Name: Abdulaziz Alshabibi        Homework5
#include<iostream>
#include<vector>

void split_vector(const vector<ItemType> &mainV ,  //Rec'd: source vector
		  vector<ItemType> &part1,         //P'Back:the first part of the source vector
		  vector<> &part2,                 //P'Back the second part of the source vector
		  ItemType target);                //Rec'd: the element that we want the second
                                                   //       part to begin with.
void reverse_vector(std::vector<int>& ints);

//Quetion 3:
  
int main()
{
  using namespace std;
  
  vector<int> ints;

  for(int i=0; i < 10; i++)
    {
    ints.push_back(i*3);
    cout << ints[i];
    if(i < 9)
      cout << ", ";
    }
    cout << endl;
  
   reverse_vector(ints);
   
   for(int i=0; i < 10; i++)
    {
      cout << ints[i];
    if(i < 9)
      cout << ", ";
    }
   cout << endl;
   
  return 0;
}

void reverse_vector(std::vector<int>& ints)
{
  int temp;
  for(int i=0; i < ints.size()/2; i++)
    {
      temp = ints[i];
      ints[i] = ints[ints.size()-i-1];
      ints[ints.size()-i-1] = temp;
    }
}

//Quetion 4:
//           vvvvvvvvvvvvvvvvvvvvvvvv

//This function will split the main vector into two vectors

void split_vector(const vector<Date> &mainV, vector<Date> &part1,
		  vector<Date> &part2, Date target)
{
  int i=0;
  while(mainV[i] != target)
    part1[i] = mainV[i];
  
  for(int j= i; j < mainV.size(); j++)
    part2[i] = mainV[i];
}
