#include "GaussSolver.h"

int main() {
	GaussSolver a1;
	std::vector<Vector> res;
	int m, n;
	std::cout << "Enter size: ";
	std::cin >> m >> n;
	Matrix a(m,n); Vector b(m);
	
	
	

	//std::cin >> a >> b;

	//std::srand(std::time(0));
	//
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++)
	//		a[i][j] = std::rand();
	//	b[i] = rand();
	//}
	std::cin >> a >> b;

	res = a1.solve(a, b);
	std::cout << "\n\nRESULT: ";

	for (int i = 0; i < res.size(); i++)
		std::cout << res[i];


	
	
	

	return 0;
}