/*Задание 1. Написать функцию, добавляющую столбец
двухмерному массиву в указанную позицию.*/
#include <iostream>
using namespace std;
void printArr(int** multiArr, int rows, int cols);
void addCols(int** &multiArr, int rows, int &cols);

int main()
{
	setlocale(LC_ALL, "ru");
	int rows = 5, cols = 5;
	int** multiArr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		multiArr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			multiArr[i][j] = 0;
		}
	}
	printArr(multiArr, rows, cols);
	addCols(multiArr, rows, cols);
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
void addCols(int** &multiArr, int rows, int &cols) {
	int index;
	cout << "Введите позицию ";
	cin >> index;
	cols++;
	int** newArr = new int* [rows];
	for (int i = 0; i < rows; i++) {
		newArr[i] = new int[cols];
	}
	/*for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			newArr[i][j] = 2;
		}
	}*/
	//printArr(newArr, rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			newArr[i][j] = multiArr[i][j];
			//сдвигаем вправо значения
			if (j == index)
			{
				for (int k = cols; k > index; k--)
				{
					newArr[i][k] = multiArr[i][k-1];
				}
				//заполняем вставленный столбец 1ми
				newArr[i][j] = 1;
				
			}
		}
	}
	//printArr(newArr, rows, cols);
	for (int i = 0; i < rows; i++) {
		delete[]multiArr[i];
	}
	delete[]multiArr;
	

	multiArr = newArr;
}