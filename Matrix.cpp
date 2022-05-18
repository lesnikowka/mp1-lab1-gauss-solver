#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {
	data = 0;
	m = 0;
	n = 0;
}

Matrix::Matrix(int m, int n) {
	this->m = m;
	this->n = n;
	data = new Vector[m];
	for (int i = 0; i < m; i++)
		data[i].resize(n);
}

Matrix::Matrix(const Matrix& matr) {
	n = matr.n;
	m = matr.m;
	
	data = new Vector[m];
	for (int i = 0; i < m; i++)
		data[i] = matr.data[i];
}

Matrix:: ~Matrix() {
	delete[] data;
	n = 0;
	m = 0;
}

Vector& Matrix:: operator[](int i) {
	return data[i];
}

Vector& Matrix:: operator[](int i)const {
	return data[i];
}


Matrix& Matrix:: operator+=(const Matrix& matr) {
	if (n == matr.n && m == matr.m)
		for (int i = 0; i < m; i++)
			data[i] += matr.data[i];
	return *this;
}

Matrix& Matrix:: operator-=(const Matrix& matr) {
	if (n == matr.n && m == matr.m)
		for (int i = 0; i < m; i++)
			data[i] -= matr.data[i];
	return *this;
}

Matrix Matrix:: operator*(const Matrix& matr)const {
	Matrix result = Matrix(m, matr.n);
	if (n == matr.m)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < matr.n; j++)
				for (int k = 0; k < n; k++)
					result[i][j] += data[i][k] * matr.data[k][j];
	return result;
}

Matrix& Matrix:: operator=(const Matrix& matr) {
	if (n != matr.n || m != matr.m)
		resize(matr.m, matr.n);
	for (int i = 0; i < m; i++)
		data[i] = matr.data[i];
	return *this;
}

Matrix Matrix:: operator+(const Matrix& matr) const {
	Matrix result(m, n);
	if(m == matr.m && n == matr.n)
		for (int i = 0; i < m; i++)
			result.data[i] = data[i] + matr.data[i];
	return result;
}

Matrix Matrix:: operator-(const Matrix& matr) const {
	Matrix result(m, n);
	if (m == matr.m && n == matr.n)
		for (int i = 0; i < m; i++)
			result.data[i] = data[i] - matr.data[i];
	return result;
}

Matrix& Matrix:: operator*=(const Matrix& matr) {
	Matrix result = Matrix(m, matr.n);
	if (n == matr.m)
		for (int i = 0; i < m; i++)
			for (int j = 0; j < matr.n; j++)
				for (int k = 0; k < n; k++)
					result[i][j] += data[i][k] * matr.data[k][j];
	*this = result;
	return *this;
}

Matrix& Matrix:: operator*=(double a) {
	for (int i = 0; i < m; i++)
		data[i] *= a;
	return *this;
}

Matrix Matrix:: operator*(double a) const {
	Matrix result(m, n);
	for (int i = 0; i < m; i++)
		result[i] = data[i] * a;
	return result;
}

Matrix Matrix:: operator-() const {
	Matrix result(m, n);
	result = *this * (-1);
	return result;
}

bool Matrix:: operator==(const Matrix& matr)const {
	if (m != matr.m || n != matr.n)
		return false;
	for (int i = 0; i < m; i++)
		if (data[i] != matr.data[i])
			return false;
	return true;
}

bool Matrix:: operator!=(const Matrix& matr) const {
	return !(*this == matr);
}

void Matrix::resize(int new_m, int new_n) {
	n = new_n;
	m = new_m;
	delete[] data;
	data = new Vector[m];
	for (int i = 0; i < m; i++)
		data[i].resize(n);
}
