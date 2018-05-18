#include<iostream>
#include<fstream>
#include<string>
#include<stack>
#include<cstdlib>

double EvaluatePostfix(std::string equation);

int main(int argc, char* argv[])
{
	using namespace std;

	if (argc != 3)
	{
		cout << "Error: The number of command-line arguments is invalid!" << endl;
		exit(1);
	}

	ifstream inFile(argv[1]);
	if (!inFile)
	{
		cout << "Error: Could NOT open the input file!" << endl;
		exit(1);
	}

	ofstream outFile(argv[2]);
	if (!outFile)
	{
		cout << "Error: Could NOT open the output file!" << endl;
		exit(1);
	}

	//Declaring variables
	string equation;
	double final_result;
	// Note: using // !inFile.eof() // efficient
	while ( getline(inFile, equation) )
	{
	  
		try {
			final_result = EvaluatePostfix(equation);
			outFile << final_result << endl;
		}
		catch (const string msg)
		{
			outFile << msg << endl;
		}
			
	}

}


double EvaluatePostfix(std::string equation)
{
	using namespace std;
	//Declaring & Initializing variables
	stack<double> Operand;
	double result, num, operand1, operand2;
	int numOperand=0, numOperator=0;

	// Counting the number of operands and operators
	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] >= '0' && equation[i] <= '9')
			numOperand++;
		else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
			numOperator++;

	}

	cout << numOperator << ", " << numOperand << endl;
	
	// the number of the operators should be less than the number of the operands by one.
	if (!((numOperator + 1) == numOperand))
	  throw string("Invalid input");


	for (int i = 0; i < equation.length(); i++)
	{
	 
		if (equation[i] >= '0' && equation[i] <= '9')
		{
		  num = equation[i] - '0';
			Operand.push(num);
		}

		else if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
		{
			if (Operand.size() < 2)
				throw string("Invalid input");

			operand1 = Operand.top();
			Operand.pop();
			operand2 = Operand.top();
			Operand.pop();

			
		}

		//The program will reach this line in two cases
		// 1. if the character is space >> then the loop will go to the next character
		// 2. if the character is invalid >> then the function will throw a string 
		else if (equation[i] != ' ')
			throw string("Invalid input");


		//---------------------------------------------------------------------------------------

		
		if (equation[i] == '+')
		{
			result = operand1 + operand2;
			Operand.push(result);
		}

		else if (equation[i] == '-')
		{
			result = operand2 - operand1;
			Operand.push(result);
		}

		else if (equation[i] == '*')
		{
			result = operand1 * operand2;
			Operand.push(result);
		}

		else if (equation[i] == '/')
		{
			result = operand2 / operand1;
			Operand.push(result);
		}

		 
	}
	result = Operand.top();
	return result;
}
