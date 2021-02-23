// Кабанова Анна 3630102/90003
#include <iostream>
#include <cmath>

typedef enum {
	NONE_ROOTS = 0,
	ALL_ROOTS = 1,
	ONE_ROOT = 2,
	TWO_ROOTS = 3,
	UNKNOWN = 4,
}root_status_t;

double GetDiscriminant(double a, double b, double c) {
	return (b * b) - (4 * a * c);
}

void SolveLinearEquation(double b, double c, double* root, int* error) {
	if (b == 0) {
		if (c == 0)
			*error = ALL_ROOTS;
		else
			*error = NONE_ROOTS;
	}
	else {
		*error = ONE_ROOT;
		*root = (-1) * c / b;
	}
}

void SolveQuadraticEquation(double a, double b, double c, double* root1, double* root2, int* error) {
	double discriminant = GetDiscriminant(a, b, c);
	if (discriminant < 0)
		*error = NONE_ROOTS;
	else if (discriminant == 0) {
		*error = ONE_ROOT;
		*root1 = (((-1) * 0.5 * b) / a);
	}
	else {
		*error = TWO_ROOTS;
		*root1 = (0.5 * (-b + sqrt(discriminant))) / a;
		*root2 = (0.5 * (-b - sqrt(discriminant))) / a;
	}
}

void Run() {
	int rootStatus = UNKNOWN;
	double a = 0, b = 0, c = 0, root1 = 0, root2 = 0;

	std::cout << "Enter the coefficient A: ";
	std::cin >> a;
	std::cout << "A = " << a << std::endl;

	std::cout << "Enter the coefficient B: ";
	std::cin >> b;
	std::cout << "B = " << b << std::endl;

	std::cout << "Enter the coefficient C: ";
	std::cin >> c;
	std::cout << "C = " << c << std::endl;

	if (a == 0)
		SolveLinearEquation(b, c, &root1, &rootStatus);
	else
		SolveQuadraticEquation(a, b, c, &root1, &root2, &rootStatus);
	
	if (rootStatus == UNKNOWN)
		std::cout << "Solving failed" << std::endl;
	else if (rootStatus == NONE_ROOTS)
		std::cout << "No real roots found" << std::endl;
	else if (rootStatus == ALL_ROOTS)
		std::cout << "Every number is a root" << std::endl;
	else if (rootStatus == ONE_ROOT)
		std::cout << "The only root is x = " << root1 << std::endl;
	else if (rootStatus == TWO_ROOTS) {
		std::cout << "The first root is x1 = " << root1 << std::endl;
		std::cout << "The second root is x2 = " << root2 << std::endl;
	}
}
int main(void) {

	Run();

	return 0;
}
