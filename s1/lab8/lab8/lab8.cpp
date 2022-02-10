#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

void print_array(int** arr, int len);
int** generate(int len), ** min_matrix(int**, int), find_min(int**, int, int);

int main()
{
    const int n = 7;
    int** A = generate(n);
	print_array(A, n);

	int** B = min_matrix(A, n);

	cout << "The new matrix: " << endl;
	print_array(B, n);
}

//генерує квадратну матрицю з випадковими числами
int** generate(int len) {
	srand(time(NULL));

	int** matrix = new int* [len];
	for (int i = 0; i < len; i++)
	{
		matrix[i] = new int[len];

		for (int j = 0; j < len; j++)
		{
			matrix[i][j] = rand() % 90 + 10;
		}
	}
	
	return matrix;
}

//виводить квадратну матрицю
void print_array(int** arr, int len) {
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//створює та заповнює матрицю мінімальними елементами з трикутників
int** min_matrix(int** arr, int len) {
	
	int** matrix = new int* [len];
	for (int i = 0; i < len; i++)
	{
		matrix[i] = new int[len];

		for (int j = 0; j < len; j++)
		{
			matrix[i][j] = find_min(arr, i, j);
		}
	}
	return matrix;
}


//знаходить мінімальний елемент в трикутнику з головною діагоналлю
int find_min(int** arr, int row, int column) {
	int change;
	
	//визначається, знаходиться елемент над чи під діагоналлю
	if (column >= row) change = 1;
	else change = -1;

	int elem = arr[row][column];

	for (int i = row; i != column; i += change)
	{
		for (int j = i; j != column; j += change)
		{
			if (arr[i][j] < elem) elem = arr[i][j];
		}
	}

	return elem;
}