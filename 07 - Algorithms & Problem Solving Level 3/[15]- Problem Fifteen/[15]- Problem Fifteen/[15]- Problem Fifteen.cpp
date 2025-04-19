// Problem fifteen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
unsigned short int kZERO{ 0U };
unsigned short int kONE{ 1 };

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
    randomNumber = (rand() % (to - from + ::kONE) + from);
    return randomNumber;
}

void createMatrixDynamic(int* matrix[], int row, int column) {
    for (int counter{ ::kZERO }; counter < row; counter++) {
        *(matrix + counter) = new int[column];
    }
}

void fillMatrixRandomNumbers(int* matrix[], int row, int column) {
    for (int counter{ ::kZERO }; counter < row; counter++) {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
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


bool isFoundNumber(int& number1, int number2) {
    return number1 == number2;
}



int countNumberInMatrix(int* matrix[], int row, int column, int numberToSearch) {

    int  CountNumberInMatrix{ 0 };

    for (int counterI{ ::kZERO }; counterI < row;counterI++)
    {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
        {
            if (isFoundNumber( *(*(matrix + counterI) + counterJ), numberToSearch)){
                ++CountNumberInMatrix;
            }
            
        }
    }
    return CountNumberInMatrix;
}

int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrix = new int* [row];

    createMatrixDynamic(matrix, row, column);

    // Fill matrix is random numbers [1-10]
    fillMatrixRandomNumbers(matrix, row, column);

    cout << "\nThe Matrix after filling with random numbers [1 - 10]:\n\n";
    printArrayDynamic(matrix, row, column);

    int numberToSearch { readNumberPositive("\nEnter the number to search in the matrix and return the count again  : ") };

    cout << "\nThe count number [" << numberToSearch << "] : " << countNumberInMatrix(matrix, row, column, numberToSearch) << endl; 


    //Deleteation the Matrixes 
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    system("pause>0");

}