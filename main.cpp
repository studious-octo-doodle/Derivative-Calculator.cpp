#include <iostream>
#include <string>
#include "equComponent.h"
#include "arithmetic.h"

using namespace std;

int main()
{
	cout << "Welcome to the Derivative Calculator!" << endl;
	cout << "\nRULES:" << endl;
	cout << "  -  This calculator finds derivatives of y with respect to a single other variable that is not y. Any variable can be used but they must all be the same." << endl;
	cout << "  -  Enter all equations in the formats specified" << endl;
	cout << "  -  When inputting values with coefficients and exponents, use the following format: ax^n" << endl;
	cout << "  -  If a coefficient or exponent does not exist, they do not need to be inputted" << endl;
	cout << "  -  The Addition and Subtraction Rule can take as many values as desired" << endl;
	cout << "  -  The Product and Quotient Rules can only take two values each, as shown in their designated formats" << endl;

	string equation;
	char choice;
	bool valid;

	do
	{
		valid = true;

		cout << "\nPlease select the rule you would like to use:" << endl;
		cout << "[1] Addition and Subtraction Rule" << endl;
		cout << "[2] Product Rule" << endl;
		cout << "[3] Quotient Rule" << endl;
		cout << "[4] Exit the program." << endl;
		cin >> choice;
		cin.ignore();

		switch (choice) 
		{
			case '1':
			{
				cout << "\nEnter the equation in the following format: n1 + n2 - n3" << endl;
				cout << "y = ";
				getline(cin, equation);
				arithmetic derive(equation);
				cout << "You entered: " << derive.returnEquation(derive.original_comps) << endl;
				//derive.add_sub();

				break;
			}

			case '2':
			{
				cout << "Enter the equation in the following format: n1 * n2" << endl;
				cout << "f(x) = ";
				getline(cin, equation);
				arithmetic derive(equation);
				cout << "You entered: " << derive.returnEquation(derive.original_comps) << endl;
				derive.productRule();
				cout << "\nf'(x) = " << derive.returnEquation(derive.new_comps) << endl;

				break;
			}

			case '3':
			{
				cout << "Enter the equation in the following format: n1 / n2" << endl;
				cout << "y = ";
				getline(cin, equation);
				arithmetic derive(equation);
				//derive.quotientRule();

				break;
			}

			case '4':
			{
				cout << "\nGoodbye!" << endl;
				break;
			}

			default:
			{
				cout << "\nInvalid input." << endl;
				valid = false;
			}
		}
	} while (!valid);

	return  0;
}