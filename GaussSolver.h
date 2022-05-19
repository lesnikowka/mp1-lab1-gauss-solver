#pragma once
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <vector>

class GaussSolver {
	int state; // 0 - solutions don't exist  1 - only   2 - many
	std::vector<Vector> solutions;
	std::vector<int> dep, indep;  // dep - indices of dependent variables  indep - indices of independent variables
	double accuracy;

public:
	GaussSolver();

	std::vector<Vector> solve(const Matrix& matr_, const Vector& add_);

	bool nonullcol(const Matrix& matr, const Vector& add, int i1);  

	bool isjoint(const Matrix& matr, const Vector& add);  

	void zeroing(Matrix& matr, Vector& add, int i1);

	void printsolution();

	void swap(Matrix& matr, Vector& add, int i1, int i2);

	int getstate() { return state; }

	std::vector<int> numbernonullstr(const Matrix& matr);
};
