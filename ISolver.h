class ISolver
{
public:
	ISolver(int highestOrder) {
		solverOrder = highestOrder + 1;
	};

	int getSolverOrder() {
		return solverOrder;
	};

	double* getRoots(double* coefficients) {
		double* roots = new double [1];
		int order = sizeof(coefficients);

		if (checkOrder(order)) {
			roots[0] = order;
			return roots;
		}
		
		roots = calculateRoots(coefficients);

		return roots;
	};

private:
	double* calculateRoots(double* coefficients);

	bool checkOrder(int order) {
		return order != solverOrder;
	};

	int solverOrder = 0;

};