/*Задание 3. Дана матрица порядка M×N (M строк, N столбцов). Необходимо заполнить ее значениями и написать
функцию, осуществляющую циклический сдвиг строк
и/или столбцов массива указанное количество раз и в указанную сторону.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    int M, N;
    cin >> M >> N;
    int** ppArr = new int*[M];
    for (int i = 0; i < M; i++) {
        ppArr[i] = new int[N];
    }
    for (int i = 0, c = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            ppArr[i][j] = c;
            c++;
            cout << ppArr[i][j] << "\t";
        }
        cout << endl;
    }
}
