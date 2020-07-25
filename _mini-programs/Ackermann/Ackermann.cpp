//Name: Abdulaziz Alshabib

int Ackermann(int m, int n);

#include<iostream>
#include<fstream>

int main(int avc, char*avg[]) {

  using namespace std;

  if(avc != 3) {
    cout << "The number of command-line files is not correct" << endl;
    exit(1);
  }

  ifstream infile(avg[1]);
  if(!infile) {
    cout << "The input file could not be opened" << endl;
    exit(1);
  }

  ofstream outfile(avg[2]);
  if(!outfile) {
    cout << "The output file could not be opened" << endl;
    exit(1);
  }

  int m,n;
  while(infile >> m >> n) {
    outfile << "Ackermann(" << m << "," << n << ") is " << Ackermann(m,n) << endl;
  }

  infile.close();
  outfile.close();

  return 0;
}

int Ackermann(int m, int n) {
  if(m == 0) {
    return n + 1;
  } else if (m > 0 && n == 0) {
    return Ackermann(m - 1, 1);
  } 
  return Ackermann(m - 1, Ackermann(m, n - 1));
}
