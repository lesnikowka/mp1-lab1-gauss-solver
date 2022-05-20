#include "Vector.h"
#include <cmath>


Vector::Vector() {
	data = 0;
	n = 0;
	counter++;
}

Vector::Vector(int n) {
	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; i++) {
		data[i] = 0.;
	}
	counter++;
};

Vector::Vector(const Vector& v) {
	n = v.n;
	data = new double[n];

	for (int i = 0; i < n; i++)
		data[i] = v.data[i];
	counter++;

}

Vector::~Vector() {
	delete[] data;
	data = 0;
	n = 0;
	counter--;
}


void Vector::resize(int newSize) {
	delete data;
	data = new double[newSize];
	n = newSize;
	for (int i = 0; i < n; i++) 
		data[i] = 0.;
}

Vector& Vector:: operator=(const Vector& v) {
	if (this != &v) {
		if (n != v.n) 
			resize(v.n);
		for (int i = 0; i < n; i++) 
			data[i] = v.data[i];
		
	}

	return *this;
}

Vector Vector::operator+(const Vector& v) const {
	Vector result(n);
	for (int i = 0; i < n; i++) 
		result.data[i] = data[i] + v.data[i];
	return result;
}

Vector Vector::operator-(const Vector& v) const {
	Vector result(n);
	for (int i = 0; i < n; i++) 
		result.data[i] = data[i] - v.data[i];
	return result;
}

Vector& Vector::operator+=(const Vector& v) {
	for (int i = 0; i < n; i++) 
		data[i] += v.data[i];
	return *this;
}

Vector& Vector::operator-=(const Vector& v) {
	for (int i = 0; i < n; i++) 
		data[i] -= v.data[i];
	return *this;
}

Vector Vector::operator*(double c) const {
	Vector result(n);
	for (int i = 0; i < n; i++) 
		result[i] = c * data[i];
	return result;
}

Vector& Vector:: operator*=(double c) {
	for (int i = 0; i < n; i++) 
		data[i] *= c;
	return *this;
}

double Vector::dot(const Vector& v) const {
	double result = 0;
	for (int i = 0; i < n; i++) 
		result += data[i] * v.data[i];
	return result;
}

double& Vector:: operator[](int i) {
	if (i > n || i < 0) {
		std::cout << "ERROR operator[]";
		return data[0];
	}
	return data[i];
}

double& Vector:: operator[](int i) const {
	return data[i];
}

bool Vector:: operator==(const Vector& v) {
	if (n != v.n) return false;
	for (int i = 0; i < n; i++)
		if (data[i] != v.data[i])
			return false;
	return true;
	
}

bool Vector:: operator!=(const Vector& v) {
	if (n != v.n)
		return true;
	for (int i = 0; i < n; i++)
		if (data[i] != v.data[i])
			return true;
	return false;
}

int Vector::getsize() const {
	return n;
}

void Vector::swap(int i1, int i2) {
	if (i1 != i2) {
		double tmp = data[i1];
		data[i1] = data[i2];
		data[i2] = tmp;
	}
}

int Vector::counter = 0;