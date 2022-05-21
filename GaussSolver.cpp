#include "GaussSolver.h"
#include <cmath>

GaussSolver:: GaussSolver():accuracy(0.0000000001),numb_dep_elements(0){}

std::vector<Vector> GaussSolver::solve(const Matrix& matr_, const Vector& add_) {
	Matrix matr = matr_;
	Vector add = add_, onlysolution(matr.getN());
	std::vector<int> numb_no_null_str;
	dep_elements.resize(matr.getN());
	columns_main_elements.resize(matr.getM());
	rows_main_elements.resize(matr.getN());
	Vector used_string(matr.getM());
	int max, i = 0;


	for(int j = 0; j < matr.getN(); j++){
		max = i;
		for (int m = 0; m < matr.getM(); m++)
			if (!used_string[m] && abs(matr[m][j]) > abs(matr[max][j])) max = m;

		if (abs(matr[max][j]) > accuracy && !used_string[max]) {
			dep_elements[j] = 0;
			swap(matr, add, i, max);
			used_string.swap(i, max);
			zeroing(matr, add, i, j);
			used_string[i] = 1;
			columns_main_elements[i] = j;
			rows_main_elements[j] = i;

		}
		else {
			dep_elements[j] = 1;
			numb_dep_elements++;
		}

		if (i < matr.getM()-1) i++;
	}
	

	numb_no_null_str = numbernonullstr(matr);
	
	if (isjoint(matr, add)) {
		if (!numb_dep_elements) {
			for (int i = 0; i < matr.getN(); i++) 
				onlysolution[i] = add[i];
			
			solutions.push_back(onlysolution);
		}
		else {
			Vector column(matr.getN());
			for (int i = 0; i < matr.getN(); i++)
				column[i] = dep_elements[i] ? 0 : add[rows_main_elements[i]];
			solutions.push_back(column);
			
	
			for (int i = 0; i < matr.getN(); i++)
				if (dep_elements[i]) {
					for (int j = 0; j < matr.getN(); j++)
						column[j] = 0;
					for (int j = 0; j < numb_no_null_str.size(); j++) 
						column[columns_main_elements[numb_no_null_str[j]]] = -matr[numb_no_null_str[j]][i];
					
					column[i] = 1;
					solutions.push_back(column);
				}
		}
	}
	
	return solutions;

}


bool GaussSolver::isjoint(const Matrix& matr, const Vector& add) { 
	bool flag;
	for (int i = 0; i < matr.getM(); i++) {
		flag = true;
		for (int j = 0; j < matr.getN(); j++) {
			if (abs(matr[i][j]) > accuracy) {
				flag = false;
				break;
			}
		}
		if (flag && abs(add[i]) > accuracy)
			return false;
	}
	return true;
}

void GaussSolver::zeroing(Matrix& matr, Vector& add, int i1, int j1) {
	double r , r2 = 1 / matr[i1][j1];
	
	for(int i = 0; i < matr.getM(); i++)
		if (i != i1) {
			r = matr[i][j1] / matr[i1][j1];
			matr[i] -= matr[i1] * r;
			add[i] -= add[i1] * r;
		}
	
	matr[i1] *= r2;
	add[i1] *= r2;
}


void GaussSolver::swap(Matrix& matr, Vector& add, int i1, int i2) {
	if (i1 != i2) {
		Vector tmp = matr[i1];
		matr[i1] = matr[i2];
		matr[i2] = tmp;
		add.swap(i1, i2);
	}
	
}

std::vector<int> GaussSolver::numbernonullstr(const Matrix& matr) {
	std::vector<int> v;
	bool flag;
	for (int i = 0; i < matr.getM(); i++) {
		flag = false;
		for (int j = 0; j < matr.getN(); j++)
			if (abs(matr[i][j]) > accuracy)
				flag = true;
		if (flag)
			v.push_back(i);
	}

	return v;
}