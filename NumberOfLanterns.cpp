// Apriorit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cmath>

void init(int& n, int& m, int& k) {
	bool dealing = true;
	while (dealing) {
		std::cout << "Enter n - row, m - column and k - amount tram. 1 <= m,n <= 10^9, 0 <= k <= 1000" << std::endl;
		std::cout << "Input format: n m k" << std::endl;
		std::cin >> n >> m >> k;
		char counter = 0;
		int tenNinthDegree = pow(10, 9);
		if (m >= 1 && m <= tenNinthDegree) {
			counter += 1;
		}
		if (n >= 1 && n <= tenNinthDegree) {
			counter += 1;
		}
		if (k >= 0 && k <= 1000) {
			counter += 1;
		}
		if (counter == 3) { 
			dealing = false;
		}
	}
}

void matrixFilling(std::vector<std::vector<int>>& matrix, int r, int c1, int c2) {
	for (int j = c1 - 1; j < c2; j++) {
		matrix[r - 1][j] = 1;
	}
}

void buildingTram(std::vector<std::vector<int>>& matrix,int n, int m, int k) {
	int r = 0;
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < k; ) {
		short counter = 0;
		std::cout << "Enter row: r, enter column start and finish: c1, c2. 0 < r <= n and 0 < c1,c2 <= m " << std::endl;
		std::cout << "Input format: r c1 c2" << std::endl;
		std::cin >> r >> c1 >> c2;
		if (c1 > 0 && c2 > 0 && c1 <= m && c2 <= m) {
			counter += 2;
		}
		if (r > 0 && r <= n) {
			counter += 1;
		}
		if (counter == 3) {
			matrixFilling(matrix, r, c1, c2);
			i += 1;
		}
		else {
			std::cout << "Incorrectly entered data!" << std::endl;
		}
	}
}

int searchPlacesLanterns(std::vector<std::vector<int>>& matrix, int n, int m) {
	int placesLight = 0;
	int bottomLine = n - 1;
	int rightLine = m - 1;
	int middleRow = n / 2;
	int middleColumn = m / 2;
	if (n > 1 && m > 1) {
		std::cout << "n,m > 1" << std::endl;
		for (int i = 0; i < middleRow; i++) {
			for (int j = 0; j < middleColumn; j++) {
				placesLight += matrix[i][j];
				placesLight += matrix[i][rightLine - j];
				placesLight += matrix[bottomLine - i][j];
				placesLight += matrix[bottomLine - i][rightLine - j];
			}
			if (m % 2 == 1) {
				placesLight += matrix[i][middleColumn];
				placesLight += matrix[bottomLine - i][middleColumn];
			}
		}
		if (n % 2 == 1) {
			for (int i = 0; i < middleColumn; i++) {
				placesLight += matrix[middleRow][i];
				placesLight += matrix[middleRow][rightLine - i];
			}
			if (m % 2 == 1) {
				placesLight += matrix[middleRow][middleColumn + 1];
			}
		}
	}
	else if (n == 1) {
		for (int i = 0; i < middleColumn; i++) {
			placesLight += matrix[0][i];
			placesLight += matrix[0][rightLine - i];
		}
		if (n % 2 == 1) {
			placesLight += matrix[0][middleColumn];
		}
	}
	return (placesLight = m * n - placesLight);
}

int main()
{
	int m, n, k;
	init(n, m, k);
	std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
	buildingTram(matrix, n, m, k);
	int placesLight = searchPlacesLanterns(matrix, n, m);
	std::cout << "Number of lanterns - " << placesLight << std::endl;
	std::cin >> k;
    return 0;
}

