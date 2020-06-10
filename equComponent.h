#pragma once
#include <vector>

class equComponent {
private:
	float _coefficient = NULL;
	char _variable = NULL;
	int _exponent = NULL;

public:
	void setCoefficient(float);
	float getCoefficient();
	
	void setVariable(char);
	char getVariable();
	
	void setExponent(int);
	int getExponent();

	void clear();
	std::vector<equComponent> operator+(equComponent);
	std::vector<equComponent> operator-(equComponent);
	equComponent operator*(equComponent);
	equComponent operator/(equComponent);
};