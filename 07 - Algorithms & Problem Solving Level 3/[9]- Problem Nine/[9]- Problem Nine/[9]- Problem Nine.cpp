// Problem Eight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
unsigned short int kZERO{ 0U };

int readNumberPositive(string const message) {
    int number{};
    do {
        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            cout << message;
            cin >> number;
        }
    } while (number < ::kZERO);

    return number;
}

int randomNumberFromTo(int from, int to) {
    int randomNumber{};
    randomNumber = (rand() % (to - from + 1) + from);
    return randomNumber;
}

void createMatrixDynamic(int* matrix[], int row, int column) {
    for (int counter{ 0 }; counter < row; counter++) {
        *(matrix + counter) = new int[column];
    }
}

void fillMatrixRandomNumbers(int* matrix[], int row, int column) {
    for (int counter{ 0 }; counter < row; counter++) {
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
            *(*(matrix + counter) + counterJ) = randomNumberFromTo(1, 10);
    }
}

void printArrayDynamic(int* matrix[], int row, int column) {
    for (int counter{ ::kZERO }; counter < row; counter++) {
        cout << "[  ";
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
            printf("%02d ", *(*(matrix + counter) + counterJ));
        cout << " ]\n";
    }
}

string separator(int number, int size) {
    return (size - 1 > number) ? " , " : "";
}

void print1DArray(int* array, int sizeArray1D) {
    cout << "\n[ ";
    for (int counter{ 0 }; counter < sizeArray1D; counter++) {
        cout << *(array + counter) << separator(counter, sizeArray1D);
    }
    cout << " ] \n";
}

int findRowOrColumnMiddleInMatrix(int RowOrColumn) {
    return RowOrColumn / 2;
}

void fillArray1DMiddleRow(int* matrix[], int row, int column, int* array1D, int& TypeFindMiddleInMatrix) {
    int rowMiddle = findRowOrColumnMiddleInMatrix(TypeFindMiddleInMatrix);
    for (int counterJ{ 0 }; counterJ < column; counterJ++) {
        *(array1D + counterJ) = *(*(matrix + rowMiddle) + counterJ);
    }
}

void fillArray1DMiddleColumn(int* matrix[], int row, int column, int* array1D, int& TypeFindMiddleInMatrixColumn) {
    int ColumnMiddle = findRowOrColumnMiddleInMatrix(TypeFindMiddleInMatrixColumn);
    for (int counter{ 0 }; counter < row; counter++) {
        *(array1D + counter) = *(*(matrix + counter) + ColumnMiddle);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrix = new int* [row];
    createMatrixDynamic(matrix, row, column);

    fillMatrixRandomNumbers(matrix, row, column);

    cout << "\nThe Matrix after filling with random numbers [1 - 10]:\n\n";
    printArrayDynamic(matrix, row, column);

    // Middle Row
    int* arrayMiddleRow = new int[column];
    cout << "\n\nThe Middle Row in Matrix:\n";
    fillArray1DMiddleRow(matrix, row, column, arrayMiddleRow, row);
    print1DArray(arrayMiddleRow, column);

    // Middle Column
    int* arrayMiddleColumn = new int[row];
    cout << "\n\nThe Middle Column in Matrix:\n";
    fillArray1DMiddleColumn(matrix, row, column, arrayMiddleColumn, column);
    print1DArray(arrayMiddleColumn, row);

    // Realesd dynamic array 
    delete[] arrayMiddleRow;
    delete[] arrayMiddleColumn;

    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

