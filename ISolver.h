#include <math.h>
#include <iostream>
#include <string>
#include "Equation.h"
#pragma once

class ISolver
{
public:
	ISolver(int highestOrder) {
		solverOrder = highestOrder + 1;
		description = "I can solve only a_n*x^n + ... + a_0 with order: " 
					+ std::to_string(highestOrder) 
					+ "\n";
	};

	int getSolverOrder() {
		return solverOrder;
	};

	void printDescription() {
		std::cout << description;
	};

	double* getRoots(Equation &equation) {
		int equationOrder = equation.getEquationOrder();
		double * coefficients = equation.getCoefficients();
		double* roots = new double[equationOrder];

		if (checkOrder(equationOrder)) {

			for (int i = 0; i < equationOrder; i++) {
				roots[i] = NAN;
			}

			return roots;
		}

		delete[] roots;

		roots = calculateRoots(coefficients);

		return roots;
	};

private:
	double* calculateRoots(double* coefficients);

	bool checkOrder(int order) {
		return (order + 1) != solverOrder;
	};

	int solverOrder = 0;

	std::string description = "";
};