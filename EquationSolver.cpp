#include "pch.h"
#include "ISolver.h"
#include <math.h>
#include <iostream>

double* ISolver::calculateRoots(double* coefficients) {
	double a = coefficients[0], b = coefficients[1], c = coefficients[2];
	double discriminant = b * b - 4 * a * c;
	double* roots = {};

	if (discriminant < 0) {
		return roots;
	}
	else if (discriminant = 0) {
		roots = new double[1];
		roots[0] = - c / b;
		return roots;
	}
	else {
		roots = new double[2];
		double divider = 2 * a;
		roots[0] = (-b + sqrt(discriminant)) / divider;
		roots[1] = (-b - sqrt(discriminant)) / divider;
		return roots;
	}
}

int main()
{
	ISolver quadraticSolver = ISolver(2);
	double* a = quadraticSolver.getRoots(new double[3] { 1, -2, 1 });
	printf("%f", a[0]);
	std::cout << "I can solve only equations of type a_n*x^n + ... + a_0 with" ;
}