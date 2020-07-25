#include<iostream>
#include<vector>

void FillVector(std::vector<int>&);
void PrintVector(const std::vector<int>&);
void Replace(std::vector<int>&);

int main()
{
  using namespace std;
vector<int> Num;

 FillVector(Num);
 PrintVector(Num);
 Replace(Num);
 PrintVector(Num);


 return 0;
}

void FillVector(std::vector<int>& Num)
{
  using namespace std;
  
  int input;
  cout << "Insert values(0 to 100) to be inserted in the Vector(-1 at the end): ";
  cin >> input;

  while((input >= 0 && input <= 100) && !cin.eof())
    {
      Num.push_back(input);
      cin >> input;

    }
  cout << endl;
}

void PrintVector(const std::vector<int>& Num)
{
  using namespace std;

  cout << "The vector: " << endl;
  for(unsigned int i=0; i < Num.size(); i++)
    {
      cout << Num[i];
      if(i != Num.size() -1)
	cout << " ,";
    }
  cout << endl;
  cout << endl;
}

void Replace(std::vector<int>& Num)
{
  using namespace std;
  int old, new_value;

  cout << endl << "Insert a new element followed by value wanted to be replaced by" << endl;
  cin >> new_value >> old;

  for(unsigned int i=0; i < Num.size();i++)
    {
      if(Num[i] == old)
	Num[i] = new_value;
    }
  cout << endl;

}
