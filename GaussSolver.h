#pragma once
#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <vector>

class GaussSolver {
	std::vector<Vector> solutions;
	std::vector<bool> dep_elements;
	std::vector<int> columns_main_elements;
	std::vector<int> rows_main_elements;
	Vector used_string;
	int numb_dep_elements;
	double accuracy;
	
	
	bool isjoint(const Matrix& matr, const Vector& add);  
	void zeroing(Matrix& matr, Vector& add, int i1, int j1);
	void swap(Matrix& matr, Vector& add, int i1, int i2);
	std::vector<int> numbernonullstr(const Matrix& matr);
	
public:
	GaussSolver();

	std::vector<Vector> solve(const Matrix& matr_, const Vector& add_); 

};
