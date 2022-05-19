#include "GaussSolver.h"
#include <cmath>

GaussSolver:: GaussSolver():accuracy(0.0000000001){}

std::vector<Vector> GaussSolver:: solve(const Matrix& matr_, const Vector& add_) {
	Matrix matr = matr_;
	Vector add = add_;
	Vector onlysolution(matr.getM());
	bool flag;
	std::vector<int> numb;
	int max;

	for (int i = 0; i < std::min<int>(matr.getM(), matr.getN()); i++) {
		flag = true;
		max = i;
		for (int j = i; j < matr.getM(); j++)
			if (abs(matr[j][i]) > abs(matr[max][i])) max = j;
		
		if (abs(matr[i][i]) > accuracy && matr[i][i] >= matr[i][max]) {  
			flag = false;
			zeroing(matr, add, i);
			indep.push_back(i);
		}
		else if (nonullcol(matr, add, i) && i < matr.getM() - 1) {
			flag = false;
			indep.push_back(i);
			//swap(matr, add, i);
			swap(matr, add, i, max);
			zeroing(matr, add, i);
		}
		else if (abs(matr[i][i]) > accuracy) {
			zeroing(matr, add, i);
		}
		if (flag)
			dep.push_back(i);
	}

	if (matr.getN() > matr.getM()) 
		for (int i = matr.getM(); i < matr.getN(); i++)
			dep.push_back(i);

	numb = numbernonullstr(matr);

	if (isjoint(matr, add)) {
		if (numb.size() == matr.getN()) {
			for (int i = 0; i < matr.getN(); i++) 
				onlysolution[i] = add[i];
			
			solutions.push_back(onlysolution);
			state = 1;
		}
		else {
			Vector column(numb.size());
			for (int i = 0; i < numb.size(); i++)
				column[i] = add[numb[i]];
			solutions.push_back(column);


			for (int i = 0; i < dep.size(); i++) {
				for (int j = 0; j < numb.size(); j++)
					column[j] = -matr[numb[j]][dep[i]];
				solutions.push_back(column);
			}
			state = 2;
		}
	}
	else 
		state = 0;
	
	
	return solutions;

}

bool GaussSolver::nonullcol(const Matrix& matr, const Vector& add, int i1) {
	for (int i = i1 + 1; i < matr.getM(); i++) {
		if (abs(matr[i][i1]) > accuracy)
			return true;
	}
	return false;
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

void GaussSolver::zeroing(Matrix& matr, Vector& add, int i1) {
	double r , r2 = 1 / matr[i1][i1];
	
	for(int i = 0; i < matr.getM(); i++)
		if (i != i1) {
			r = matr[i][i1] / matr[i1][i1];
			matr[i] -= matr[i1] * r;
			add[i] -= add[i1] * r;
		}
	
	matr[i1] *= r2;
	add[i1] *= r2;
}

void GaussSolver::printsolution() {
	std::cout << std::endl;
	if (!state)
		std::cout << "Solutions don't exist" << std::endl;
	 
	else if (state == 1) 
		std::cout << "Solution vector: " << solutions[0] << std::endl;
	
	else {
		std::cout << "( ";
		for (int i = 0; i < indep.size(); i++)
			i < indep.size() - 1 ? std::cout << "x" << indep[i] + 1 << ", " : std::cout << "x" << indep[i] + 1;
		std::cout << " ) = ( ";
		for (int i = 0; i < indep.size(); i++)
			i < indep.size() - 1 ? std::cout << solutions[0][i] << ", " : std::cout<<solutions[0][i];
		std::cout << " )";
		for (int i = 1; i < solutions.size(); i++) {
			std::cout << " + t" << i << "( ";
			for (int j = 0; j < indep.size(); j++)
				std::cout << solutions[i][j] << ", ";
			std::cout << " )";
		}
		std::cout << std::endl;
		for (int i = 0; i < dep.size(); i++) 
			std::cout << "x" << dep[i] + 1 << " = " << "t" << i + 1 << std::endl;
	}
}

void GaussSolver::swap(Matrix& matr, Vector& add, int i1, int i2) {
	
	Vector tmp = matr[i1];
	double tmp2 = add[i1];
	matr[i1] = matr[i2];
	add[i1] = add[i2];
	matr[i2] = tmp;
	add[i2] = tmp2;
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

