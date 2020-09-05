#pragma once
class Equation
{
public:
	Equation(int equationOrder, double* coefficients) {
		this->equationOrder = equationOrder;
		this->coefficients = coefficients;
	};

	~Equation()
	{
		delete[] coefficients;
	};

	int getEquationOrder() {
		return equationOrder;
	};

	double* getCoefficients() {
		return coefficients;
	};

private:

	int equationOrder = 0;
	
	double* coefficients = {};

};