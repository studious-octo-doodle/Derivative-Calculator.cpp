#pragma once
#include "equComponent.h"
#include <vector>
#include <string>
class arithmetic
{
private:
	bool _mul = false;
	bool _div = false;
public:
	std::vector<equComponent> original_comps;
	std::vector<equComponent> new_comps;

	void setMul(bool);
	bool getMul();
	void setDiv(bool);
	bool getDiv();

	arithmetic(std::string);
	std::string returnEquation(std::vector<equComponent>);

	void powerRule(equComponent&);
	void add_sub();
	void productRule();
	void quotientRule();
};

