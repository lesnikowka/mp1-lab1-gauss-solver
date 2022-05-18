#pragma once
#include <iostream>


class Vector {
private:
	double* data = 0;
	int n = 0;
	static int counter;

	friend Vector operator* (double c, Vector v) { return v * c; }

	friend std::ostream& operator<<(std::ostream& out, const Vector& v) {
		out << "(";
		for (int i = 0; i < v.n; i++) {
			out << v.data[i] << "  ";
		}
		out << ")" << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, const Vector& v) {
		for (int i = 0; i < v.n; i++) 
			in >> v.data[i];
		return in;
	}

public:

	Vector();
	Vector(int n);
	~Vector();
	Vector(const Vector& v);

	void resize(int newSize);

	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	Vector& operator*=(double c);
	bool operator==(const Vector& v);
	bool operator!=(const Vector& v);
	double dot(const Vector& v) const;
	double& operator[](int i);  //return v.data[i]
	double& operator[](int i) const;
	int getsize() const;

	static int getcounter() { return counter; }

};


