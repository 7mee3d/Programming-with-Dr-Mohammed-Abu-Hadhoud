// Problem Ten.cpp : This file contains the 'main' function. Program execution begins and ends there.
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


int summationMatrix(int* matrix[], int row, int column) {

    int summationMatrixVar{ 0 };

    for (int counterI{ 0 }; counterI < row;counterI++)
    {
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
        {
            summationMatrixVar += *(*(matrix + counterI ) + counterJ ) ;
        }
    }

    return summationMatrixVar;
}


bool isEqual(int& number1, int number2) {
    return number1 == number2; 
}

bool areMatricesTypical(int* matrix1[], int* matrix2[], int row, int column) {

    bool flagIsEqualyElement{ true };
    for (int counterI{ 0 }; counterI < row;counterI++)
    {
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
        {
            if (!(isEqual(*(*(matrix1 + counterI) + counterJ), *(*(matrix2 + counterI) + counterJ)))) {
                flagIsEqualyElement = { false };
                break;
            }
        }
    }
    return {flagIsEqualyElement};
}


int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrix = new int* [row];
    int** matrix2 = new int* [row];

    createMatrixDynamic(matrix, row, column);
    createMatrixDynamic(matrix2, row, column);

    // Fill matrix is random numbers 
    fillMatrixRandomNumbers(matrix, row, column);
    fillMatrixRandomNumbers(matrix2, row, column);

    cout << "\nThe Matrix after filling with random numbers [1 - 10]:\n\n";
    printArrayDynamic(matrix, row, column);

    cout << "\nThe Matrix Two after filling with random numbers [1 - 10]:\n\n";
    printArrayDynamic(matrix2, row, column);

    // Cheak Two Matrix is Eaqules or not 

    if (areMatricesTypical(matrix, matrix2, row , column))
        cout << "\nYES: both martices are typical";
    else
        cout << "\nNo: martices are NOT typical";


    //Deleteation the Matrixes 
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    for (int i = 0; i < row; i++) {
        delete[] matrix2[i];
    }

    delete[] matrix;
    delete[] matrix2;

    system("pause>0");

}