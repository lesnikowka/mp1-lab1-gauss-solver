#pragma once
#include <iostream>
#include "Vector.h"

class Matrix {
	Vector* data = 0;
	int m = 0;
	int n = 0;

	friend std::ostream& operator<<(std::ostream& out, const Matrix& matr) {
		for (int i = 0; i < matr.m; i++) 
			out << matr.data[i];
		out << "\n";
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const Matrix& matr) {
		for (int i = 0; i < matr.m; i++) {
			in >> matr.data[i];
		}
		return in;
	}

public:
	Matrix();
	Matrix(int m, int n);
	~Matrix();
	Matrix(const Matrix& matr);

	Vector& operator[](int i);
	Vector& operator[](int i)const;
	Matrix& operator+=(const Matrix& matr);
	Matrix& operator-=(const Matrix& matr);
	Matrix operator*(const Matrix& matr)const;
	Matrix& operator=(const Matrix& matr);
	Matrix operator+(const Matrix& matr)const;
	Matrix operator-(const Matrix& matr)const;
	Matrix& operator*=(const Matrix& matr);
	Matrix& operator*=(double a);
	Matrix operator*(double a)const;
	Matrix operator-()const;
	bool operator==(const Matrix& matr)const;
	bool operator!=(const Matrix& matr)const;
	int getM() const { return m; }
	int getN() const { return n; }
	void resize(int new_m, int new_n);

};