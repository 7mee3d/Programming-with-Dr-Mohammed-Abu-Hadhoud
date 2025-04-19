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


void summationEachRowInMatrix(int* matrix[], int row, int column, int* arrayOfRows) {

    int summationEachRow{ 0 };

    for (int counterI{ 0 }; counterI < row;counterI++)
    {
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
        {
            summationEachRow += matrix[counterI][counterJ];
        }

        arrayOfRows[counterI] = summationEachRow;
        summationEachRow = { 0 };
    }

}


int summationArray1DElement(int* array1D, int sizeArray) {

    int summationElements{ 0 };
    for (int counter{ 0 }; counter < sizeArray; counter++)
        summationElements += *(array1D + counter);

    return summationElements; 
}
int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrix = new int* [row];
    int* array = new int[row]; 
    createMatrixDynamic(matrix, row, column);

    fillMatrixRandomNumbers(matrix, row, column);

    cout << "\nThe Matrix after filling with random numbers [1 - 10]:\n\n";
    printArrayDynamic(matrix, row, column);

    // Summation Each Rows 

    summationEachRowInMatrix(matrix, row, column , array );


    // print array 1D After the storing the Summation each rows 
    cout << "\nArray After the storing sum each ros  \n"; 

    print1DArray(array, row);
    cout << endl; 

    // print summation element in array 1D 
    cout << "The Summation Elements In Matrix = " << summationArray1DElement(array, row);


    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] array;

    system("pause>0");
    system("cls");
}
