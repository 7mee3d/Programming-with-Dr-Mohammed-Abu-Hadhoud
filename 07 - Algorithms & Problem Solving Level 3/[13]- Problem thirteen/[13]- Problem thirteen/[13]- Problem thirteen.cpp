// Problem Ten.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    randomNumber = (rand() % (to - from + 1) + from);
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
            *(*(matrix + counter) + counterJ) = randomNumberFromTo(0, 1);
    }
}

void printArrayDynamic(int* matrix[], int row, int column) {
    for (int counter{ ::kZERO }; counter < row; counter++) {
        cout << "[  ";
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
            printf("%01d ", *(*(matrix + counter) + counterJ));
        cout << " ]\n";
    }
}


int summationMatrix(int* matrix[], int row, int column) {

    int summationMatrixVar{ ::kZERO };

    for (int counterI{ ::kZERO }; counterI < row;counterI++)
    {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
        {
            summationMatrixVar += *(*(matrix + counterI) + counterJ);
        }
    }

    return summationMatrixVar;
}


bool isEqual(int& number1, int number2) {
    return number1 == number2;
}



bool areMatriceIdentity(int* matrix[], int row, int column) {

    bool flagIsIdentity{ true };
    for (int counterI{ ::kZERO }; counterI < row;counterI++)
    {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
        {
            if (counterI == counterJ ) {
                if (!(*(*(matrix + counterI) + counterJ) == ::kONE)) {
                    flagIsIdentity = { false };
                    break;
                }
            }
            /*else if (counterJ < counterJ) {
                if (!(*(*(matrix + counterI) + counterJ) == ::kONE)) {
                    flagIsIdentity = { false };
                    break;

                }
            }*/
            else   {
                if (!(*(*(matrix + counterI) + counterJ) == ::kZERO)) {
                    flagIsIdentity = { false };
                    break;

                   
                }
            }
        }
    }
    return { flagIsIdentity };
}


int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrix = new int* [row];

    createMatrixDynamic(matrix, row, column);

    // Fill matrix is random numbers [0-1]
    fillMatrixRandomNumbers(matrix, row, column);

    cout << "\nThe Matrix after filling with random numbers [0 - 1]:\n\n";
    printArrayDynamic(matrix, row, column);

    // Cheak Two Matrix is Eaqules or not 

    if (areMatriceIdentity(matrix, row, column))
        cout << "\nYES: The martix is is Identity";
    else
        cout << "\nNo: The martix is is Not Identity";


    //Deleteation the Matrixes 
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    system("pause>0");

}