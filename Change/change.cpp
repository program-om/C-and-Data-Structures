// File: change.cpp
// Name: Abdulaziz Alshabibi

#include<iostream>
#include<fstream>
#include<cstdlib> // exit()
#include<iomanip>


void compute_change(int amount, int &dol, int &qua, int &dim, int &pen);

// command-line argument parameters
//         argc - count of the "words" on the command line
//         argv - array of the "words"
//                argv[0] is the program name
int main(int argc, char *argv[])
{

  using namespace std;
  int amount = 0, dollars = 0, quarters = 0, dimes=0, pennies = 0;
  // 1. Check for correct number of arguments
  if(argc != 3)
{
  cout << "Usage: " << argc << endl;
 }

  //2.open files and check for successs
  
  //ifstream: Stream class to read from files
  ifstream infile(argv[1]);
  if(!infile)
    {
      cout << "Error opening input file: " << argv[1] << endl;
      exit(1);
    }
  //ofstream: Stream class to write on files
   ofstream outfile (argv[2]);
   if(!outfile)
{
 cout << "Error opening output file: " << argv[2] << endl;
      exit(1);
}

  //3.copy one character at a time by reading a char until stream
  //fails (usually EOF)
   outfile << right;
      outfile << setw(10) << "Amount"  ;
      outfile << setw(10) << "Dollars" ;
      outfile << setw(10) << "Quarters" ;
      outfile << setw(10) << "Dimes";
      outfile << setw(10) << "Pennies";
      outfile << "\n" << endl;
      
   while(infile >>  amount)
    {
      //3.1 write table  to output file
      compute_change(amount, dollars, quarters, dimes, pennies);
      

      
	
	outfile << setw(10) << amount;
	outfile << setw(10) << dollars;
	outfile << setw(10) << quarters;
	outfile << setw(10) << dimes;
	outfile << setw(10) << pennies;
	outfile << endl;
    }

  
  infile.close();
  outfile.close();
  
  return 0;
}

void compute_change(int amount, int &dol, int &qua, int &dim, int &pen)
{
  dol=0, qua=0, dim=0,pen=0;
  
  dol = amount / 100;
  amount %= 100;

  qua = amount / 25;
  amount %= 25;

  dim = amount / 10;
  amount %= 10;

  pen = amount;
  
}


