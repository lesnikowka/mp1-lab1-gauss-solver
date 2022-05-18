#include "GaussSolver.h"


int main() {
	GaussSolver a1;
	std::vector<Vector> res;
	int m, n;
	std::cout << "Enter size: ";
	std::cin >> m >> n;
	Matrix a(m,n); Vector b(m);
	
	
	//a[0][0] = 1;
	//a[0][1] = 2;
	//a[0][2] = 3;
	//a[1][0] = 1;
	//a[1][1] = 2;
	//a[1][2] = 3;
	//a[2][0] = 1;
	//a[2][1] = 3;
	//a[2][2] = 1;
	//
	//b[0] = 1; b[1] = 1; b[2] = 1;
	//
	
	
	//a[0][0] = 3;
	//a[0][1] = 2;
	//a[0][2] = -5;
	//a[1][0] = 2;
	//a[1][1] = -1;
	//a[1][2] = 3;
	//a[2][0] = 1;
	//a[2][1] = 2;
	//a[2][2] = -1;
	//
	//b[0] = -1; b[1] = 13; b[2] = 9;
	//

	//std::cin >> a >> b;

	std::srand(std::time(0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			a[i][j] = std::rand();
		b[i] = rand();
	}
	std::cin >> a >> b;

	res = a1.solve(a, b);

	a1.printsolution(); 

	
	
	
	

	return 0;
}