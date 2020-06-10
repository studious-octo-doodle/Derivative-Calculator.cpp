#include "arithmetic.h"
#include "equComponent.h"
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

void arithmetic::setMul(bool mul) { _mul = mul; }
bool arithmetic::getMul() { return _mul; }
void arithmetic::setDiv(bool div) { _div = div; }
bool arithmetic::getDiv() { return _div; }

// Constructor to separate the equation into multiple parts
arithmetic::arithmetic(string equation)
{
	equComponent temp;
	string temp_substr = "";
	float temp_num;

	// Checking if multiplication or division occurs in the user's equation
	for (char c : equation)
	{
		if (c == '*')
		{
			setMul(true);
			break;
		}
		else if (c == '/')
		{
			setDiv(true);
			break;
		}
	}

	for (unsigned int i = 0; i < equation.length(); i++)
	{
		// Checking if value is negative
		if (equation[i] == '-')
			temp_substr = equation[i];

		if (equation[i] != ' ' && equation[i] != '-' && equation[i] != '+' && equation[i] != '*' && equation[i] != '/')
		{
			// FINDING COEFFICIENT

			// Checking if coefficient is 1 or -1
			if (isalpha(equation[i]) || (equation[i] == '-' && isalpha(equation[i + 1])))
			{
				if (temp_substr == "-")
					temp.setCoefficient(-1);
				else
					temp.setCoefficient(1);
			}
			// If coefficient is not 1 or -1, it is converted into an int and added to the temp class
			else
			{
				while (isdigit(equation[i]))
				{
					temp_substr += equation[i];
					i++;
				}
				temp_num = stof(temp_substr);
				temp.setCoefficient(temp_num);
			}
			temp_substr = "";

			// FINDING VARIABLE
			if (isalpha(equation[i]))
			{
				temp.setVariable(equation[i]);
				i++;
			}

			// FINDING EXPONENT
			if (equation[i] == '^')
			{
				i++;

				// Checking if value is negative
				if (equation[i] == '-')
				{
					temp_substr = equation[i];
					i++;
				}
				while (isdigit(equation[i]))
				{
					temp_substr += equation[i];
					i++;
				}
				temp_num = stoi(temp_substr);
				temp.setExponent(temp_num);
			}
			else
			{
				temp.setExponent(0);
			}
			original_comps.push_back(temp);

			// Resetting values to NULL in case they hold no values during the next iteration
			temp_num = NULL;
			temp_substr = "";
			temp.clear();
		}
	}
}

// Returns a string of the equation
string arithmetic::returnEquation(vector<equComponent> parts)
{
	// Variable that will create an equation based on the equation components passed
	string equation;

	for (equComponent i : parts)
	{
		// If the coefficient is positive and not at the beginning of the user's equation, " + " is added to the equation string
		if (i.getCoefficient() >= 0 && i.getCoefficient() != parts[0].getCoefficient())
			if (getMul())
			{
				equation += " * ";
				setMul(false);
			}
			else if (getDiv())
			{
				equation += " / ";
				setDiv(false);
			}
			else
				equation += " + ";

		// If the coefficient is negative and at the beginning of the user's equation, a " - " is added to the equation string along with the coefficient
		if (i.getCoefficient() < 0 && i.getCoefficient() != parts[0].getCoefficient())
			equation = equation + " " + to_string(i.getCoefficient())[0] + " " + to_string(i.getCoefficient()).substr(1, to_string(i.getCoefficient()).length());
		else
			// Else, the coefficient is added to the equation string
			equation += to_string(i.getCoefficient());
		
		// Adds variable and exponent to equation string if they exist
		if (isalpha(i.getVariable()))
		{
			// Adds variable to equation string
			equation += i.getVariable();

			// Adds exponent to equation string if it is not equal to 0 or 1
			if (i.getExponent() != NULL && i.getExponent() != 1)
				equation = equation + "^" + to_string(i.getExponent());
		}
	}
	//2x^3 - 15 + x^7 - 4x^8 + 5x - x^-4 + 3x^9
	return equation;
}

// Power Rule used when calculating derivatives
void arithmetic::powerRule(equComponent &x)
{
	// Incomplete
	x.setCoefficient(x.getCoefficient() * x.getExponent());
	x.setExponent(x.getExponent() - 1);
}

// Calculates derivative using the Addition and Subtraction Rule
void arithmetic::add_sub()
{
	// Incomplete
}

// Calculates derivative using the Product Rule
void arithmetic::productRule()
{
	// Left and right sides of equation
	equComponent left = original_comps[0];
	equComponent d_left = left;
	equComponent right = original_comps[1];
	equComponent d_right = right;

	// Derivatives of left and right sides of inputted equation
	powerRule(d_left);
	powerRule(d_right);

	right = right * d_left;
	left = left * d_right;

	new_comps.push_back(right);
	new_comps.push_back(left);
}

// Calculates the derivative using the Quotient Rule
void arithmetic::quotientRule() {
	// Left (top) and right (bottom) sides of equation
	equComponent bottom = original_comps[1];
	equComponent d_bottom = bottom;
	equComponent top = original_comps[0];
	equComponent d_top = top;

	// Derivatives of left (top) and right (bottom) sides of inputted equation
	powerRule(d_top);
	powerRule(d_bottom);

	// Incomplete
	top = (bottom * d_top) - (top * d_bottom);
	bottom = bottom * bottom;
}