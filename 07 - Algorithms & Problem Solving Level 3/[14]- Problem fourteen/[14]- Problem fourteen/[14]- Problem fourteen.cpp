// Problem Ten.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;
unsigned short int kZERO{ 0U };
unsigned short int kONE{ 1 };


void createMatrixDynamic(int* matrix[], int row, int column) {
    for (int counter{ ::kZERO }; counter < row; counter++) {
        *(matrix + counter) = new int[column];
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


bool areMatrixScalar(int* matrix[], int row, int column) {

    bool flagIsIdentity{ true };
    int const numberScalar{ *(*(matrix + 0) + 0) };

    for (int counterI{ ::kZERO }; counterI < row;counterI++)
    {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
        {
            if (counterI == counterJ ) {
                if ((*(*(matrix + counterI) + counterJ) != numberScalar)) {
                    flagIsIdentity = { false };
                    break;
                }
            }
            else {
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

    int row = 3;
    int column = 3;
    int** matrix = new int* [row];

    createMatrixDynamic(matrix, 3, 3);

    *(*(matrix + 0) + 0) = 9;
    *(*(matrix + 0) + 1) = 0;
    *(*(matrix + 0) + 2) = 0;

    *(*(matrix + 1) + 0) = 0;
    *(*(matrix + 1) + 1) = 9;
    *(*(matrix + 1) + 2) = 0;

    *(*(matrix + 2) + 0) = 0;
    *(*(matrix + 2) + 1) = 0;
    *(*(matrix + 2) + 2) = 9;
   
    printArrayDynamic(matrix, 3, 3);

    // Cheak Two Matrix is Scalar or not 

    if (areMatrixScalar(matrix, row, column))
        cout << "\nYES: The martix is  Scalar";
    else
        cout << "\nNo: The martix is  Not Scalar";


    //Deleteation the Matrixes 
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    system("pause>0");

}