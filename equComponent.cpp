#include <string>
#include <vector>
#include "equComponent.h"
#include "arithmetic.h"

using namespace std;

void equComponent::setCoefficient(float num) { _coefficient = num; }
float equComponent::getCoefficient() { return _coefficient; }

void equComponent::setVariable(char var) { _variable = var; }
char equComponent::getVariable() { return _variable; }

void equComponent::setExponent(int num) { _exponent = num; }
int equComponent::getExponent() { return _exponent; }

void equComponent::clear()
{
	setCoefficient(NULL);
	setExponent(NULL);
	setVariable(NULL);
}

// Overloading addition operator
vector<equComponent> equComponent::operator+(equComponent x)
{
	// Incomplete
	vector<equComponent> sum;
	
	return sum;
}

// Overloading subtraction operator
vector<equComponent> equComponent::operator-(equComponent)
{
	// Incomplete
	vector<equComponent> diff;

	return diff;
}
// Overloading multiplication operator
equComponent equComponent::operator*(equComponent x)
{
	equComponent temp;
	temp.setCoefficient(getCoefficient() * x.getCoefficient());
	temp.setExponent(getExponent() + x.getExponent());
	temp.setVariable(x.getVariable());
	return temp;
}

// Overloading division operator
equComponent equComponent::operator/(equComponent x)
{
	equComponent temp;
	temp.setCoefficient(getCoefficient() / x.getCoefficient());
	temp.setExponent(getExponent() / x.getExponent());
	temp.setVariable(x.getVariable());
	return temp;
}