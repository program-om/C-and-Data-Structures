
#include<iostream>
#include<fstream>
#include<cstdlib> // exit()

int main(int argc, char *argv[])
{

  using namespace std;

  // 1. Check for correct number of arguments
  if(argc != 4){
    cout << "Usage: " << argc << endl;
  }

  //2.open files and check for successs
  
  //ifstream: Stream class to read from files
  ifstream infile(argv[1]);
  if(!infile){
    cout << "Error opening input file: " << argv[1] << endl;
    exit(1);
  }
  //ofstream: Stream class to write on files
  ofstream outfile (argv[2]);
  if(!outfile){
    cout << "Error opening input file: " << argv[1] << endl;
    exit(1);
  }

  //3.copy one character at a time by reading a char until stream
  //fails (usually EOF)
  char ch;
  int shift = atoi(argv[3]);
  while(infile.get(ch))
    {
     
      if(ch  >= 'a' && ch <= 'z')
	{
	  ch = (((ch - 'a') + shift) % 26) + 'a';
	  outfile <<  ch;
	}
      else if(ch >= 'A' &&  ch <='Z')
	{
	  ch = (((ch - 'A') + shift) % 26) + 'A';
	  outfile << ch; 
	 
	}
      else
	outfile <<  ch;
    }

  

  
  infile.close();
  outfile.close();
  
  return 0;
}
