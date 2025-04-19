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
            summationMatrixVar += matrix[counterI][counterJ];
        }
    }

    return summationMatrixVar; 
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

    // summation Direct the matrix all element in matrix 
    cout << "The Summation Elements In Matrix = " << summationMatrix(matrix, row , column);


    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    system("pause>0");

}
