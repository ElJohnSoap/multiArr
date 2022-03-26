/*Задание 2. Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.*/
#include <iostream>
using namespace std;
void printArr(int** multiArr, int rows, int cols);
void delCols(int**& multiArr, int rows, int& cols);

int main()
{
	setlocale(LC_ALL, "ru");
	int rows = 5, cols = 5;
	int** multiArr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		multiArr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			multiArr[i][j] = j;
		}
	}
	printArr(multiArr, rows, cols);
	delCols(multiArr, rows, cols);
	printArr(multiArr, rows, cols);

	for (int i = 0; i < rows; i++) {
		delete[]multiArr[i];
	}
	delete[]multiArr;
	return 0;
}

void printArr(int** multiArr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << multiArr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void delCols(int**& multiArr, int rows, int& cols) {
	int index;
	cout << "Введите позицию ";
	cin >> index;
	cols--;
	int** newArr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		newArr[i] = new int[cols];
	}
	

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			newArr[i][j] = multiArr[i][j];
			
			if (j >= index)
			{
				newArr[i][j] = multiArr[i][j + 1];
			}
		}
	}
	
	for (int i = 0; i < rows; i++) {
		delete[]multiArr[i];
	}
	delete[]multiArr;


	multiArr = newArr;
}