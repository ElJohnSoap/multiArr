/*Задание 2. Написать программу, которая поэлементно
суммирует два динамических двумерных массива, заполненных случайными числами и сохраняет результат
в третьем массиве.Размеры исходных массивов задаются
пользователем.*/


#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int** creatArr(int rows, int cols);
void initArr(int** Arr, int rows, int cols);
void delArr(int** Arr, int rows);
void printArr(int** Arr, int rows, int cols);



int main()
{
    setlocale(LC_ALL, "ru");
    int rows1 = 5, cols1 = 6, rows2 = 7, cols2 = 8;

    //cin >> rows1 >> cols1 >> rows2 << cols2;
    int rows3 = (rows1 > rows2) ? rows1 : rows2;
    int cols3 = (cols1 > cols2) ? cols1 : cols2;
    int** mArr3 = creatArr(rows3, cols3);
    int** mArr1 = creatArr(rows1, cols1);
    int** mArr2 = creatArr(rows2, cols2);

    initArr(mArr1, rows1, cols1);
    printArr(mArr1, rows1, cols1);
    
    initArr(mArr2, rows2, cols2);
    printArr(mArr2, rows2, cols2);
    
    for (int i = 0; i < rows3; i++) {
        for (int j = 0; j < cols3; j++) {
            mArr3[i][j] = 0;
        }
    }
   
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            mArr3[i][j] = mArr1[i][j];
        }
    }
    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            mArr3[i][j] = mArr3[i][j] + mArr2[i][j];
        }
    }

    printArr(mArr3, rows3, cols3);

    return 0;
}

int** creatArr(int rows, int cols) {
    int** tempArr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        tempArr[i] = new int[cols];
    }
    return tempArr;
}

void initArr(int** Arr, int rows, int cols) {

    srand(time(0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            Arr[i][j] = rand() % 10 - 5;
        }
    }
}

void delArr(int** Arr, int rows) {
    for (int i = 0; i < rows; i++)
    {
        delete[] Arr[i];
    }
    delete[] Arr;
}

void printArr(int** Arr, int rows, int cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << Arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;
}
