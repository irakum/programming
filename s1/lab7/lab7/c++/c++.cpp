#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;
void generate_array(int*, int), print_array(int[], int), changed(int*, int*, int);
int divided(int[], int);

int main()
{
	int size;
	cout << "Enter array size: ";	//вводимо розмірність масивів  
	cin >> size;

	int* array = new int [size];
	generate_array(array, size);	//генеруємо початковий масив і виводимо його
	cout << "The first array: ";
	print_array(array, size);

	int* new_array = new int[size];
	changed(array, new_array, size);	//створюємо новий змінений масив та виводимо його
	cout << "Changed array: ";
	print_array(new_array, size);
}

//генерує масив з випадковими числами
void generate_array(int* arr, int len) {
	srand(time(NULL));
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

//виводить масив заданої довжини
void print_array(int arr[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//знаходить кількість елементів масиву, які кратні 3 і не кратні 5, повертає їх суму
int divided(int arr[], int len) {
	int amount = 0, sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] % 3 == 0 and arr[i] % 5 != 0) {
			amount += 1;
			sum += arr[i];
		}
	}
	cout << "The amount is: " << amount << endl;
	cout << "The sum is: " << sum << endl;
	return sum;
}

//створює новий масив, де до кожного елемента старого додається знайдена сума
void changed(int* old, int* change, int len) {
	int differ = divided(old, len);
	for (int i = 0; i < len; i++)
	{
		change[i] = old[i] + differ;
	}
}

