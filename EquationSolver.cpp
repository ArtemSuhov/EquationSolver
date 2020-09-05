#include "pch.h"
#include "ISolver.h"
#include "Equation.h"
#include <math.h>
#include <iostream>
#pragma once

double* ISolver::calculateRoots(double* coefficients) {
	double a = coefficients[0], b = coefficients[1], c = coefficients[2];
	double discriminant = b * b - 4 * a * c;
	double* roots = new double[2]{ NAN, NAN };

	if (discriminant < 0) {
		return roots;
	}
	else if (a == 0 && b == 0) {
		if (c == 0) {
			roots[0] = std::numeric_limits<double>::infinity();
			return roots;
		}
		else {
			return roots;
		}
	}
	else if (a == 0) {
		roots[0] = -c / b;
		return roots;
	}
	else {
		double divider = 2 * a;
		roots[0] = (-b + sqrt(discriminant)) / divider;
		roots[1] = (-b - sqrt(discriminant)) / divider;
		return roots;
	}
}

int main()
{
	ISolver quadraticSolver = ISolver(2);
	quadraticSolver.printDescription();

	Equation equationExample = Equation(2, new double[3]{ 1, -2, 1 });

	double* roots = quadraticSolver.getRoots(equationExample);
	printf("%f \n", roots[0]);
}