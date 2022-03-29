/*Задание 1. Написать программу, которая удаляет из
двухмерного массива, заполненного случайными числами
строки, содержащие нулевые элементы.*/

#include <iostream>
#include <ctime>
using namespace std;

int** creatArr(int rows, int cols);
void initArr(int** Arr, int rows, int cols);
void delArr(int** Arr, int rows);
void printArr(int** Arr, int rows, int cols);
void delNullRows(int**& Arr, int &rows, int cols);


int main()
{
    setlocale(LC_ALL, "ru");
    int rows = 5, cols = 5;
    int** mArr = creatArr(rows, cols);
    initArr(mArr, rows, cols);
    printArr(mArr, rows, cols);
    
    delNullRows(mArr, rows, cols);

    printArr(mArr, rows, cols);

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
        for (int j = 0; j < cols; j++){
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

void delNullRows(int**& Arr, int &rows, int cols) {
    int countRows = 0;
    bool Z = false;//меняется при наличии 0
    for (int i = 0; i < rows; i++) {
        Z = false;
        for (int j = 0; j < cols; j++) {
            if (Arr[i][j] == 0) {
                Z = true;
                break;
            }
        }
        if (!Z) countRows++;
    }
    cout << "Ноль есть в " << rows-countRows << " строчках\n\n";
    if (!countRows) {
        //cout << "В каждой строчке массива 0";
        return void();//тут можно удалить массив по заданию. но не стал
    }
    int** tempArr = creatArr(countRows, cols);
    for (int i = 0, i2=0; i < rows; i++, i2++) {
        for (int j = 0; j < cols; j++) {
            if (i2 < countRows) {
                tempArr[i2][j] = Arr[i][j];
                if (Arr[i][j] == 0) {
                    i2--;
                    break;
                }
            }
        }
    }
    delArr(Arr, rows);
    Arr = tempArr;
    rows = countRows;
}
