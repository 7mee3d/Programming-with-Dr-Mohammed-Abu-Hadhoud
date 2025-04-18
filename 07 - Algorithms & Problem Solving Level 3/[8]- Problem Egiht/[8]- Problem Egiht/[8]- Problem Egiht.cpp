// [8]- Problem Egiht.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib> 


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

int randomNumberFramTo(int fram, int to) {

    int rnadomNumber{};
    rnadomNumber = { (rand() % (to - fram + 1) + fram) };
    return rnadomNumber;

}

void createMatrixDynamic(int* matrix[], int row, int column) {

    for (int counter{ 0 };counter < row; counter++) {

        matrix[counter] = new int[column];
    }

}

void fillMatrixRandomNumbers (int* matrix[], int row, int column) {

    for (int counter{ 0 };counter < row; counter++) {
        for(int counterJ {0} ; counterJ < column ; counterJ++)
            matrix[counter][counterJ] = randomNumberFramTo ( 1, 10  );
    }

}

void printArrayDynamic(int* matrix[], int row, int column) {

    for (int counter{ ::kZERO }; counter < row; counter++) {
        cout << "[  ";
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
            printf("%02d ", matrix[counter][counterJ]);

        cout << " ]\n";
    }
}

int multiplyTwoNumbers(int& number1, int& number2) {
    return number1 * number2; 

}

void storeNumberAfterMultiplyInMatrix(int* matrix[], int &row, int &column, int &number) {

    matrix[row][column] = number;

}

void multiplyingTwoMatrix(int* matrixOne [], int* matrixTwo[], int* matrixResultMulitply[], int row, int column) {

    int numberResultMultiplying{ 1 };
    for (int counterI{ 0 }; counterI < row; counterI++) {
        for (int counterJ{ 0 }; counterJ < column; counterJ++) {
            numberResultMultiplying = multiplyTwoNumbers(matrixOne[counterI][counterJ], matrixTwo[counterI][counterJ]);
            storeNumberAfterMultiplyInMatrix(matrixResultMulitply, counterI, counterJ, numberResultMultiplying);
            numberResultMultiplying = { 1 }; 
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int row{ readNumberPositive("Enter the Row : ") };
    int column{ readNumberPositive("\nEnter the Column : ") };

    int** matrixOne = new int* [row];
    int** matrixTwo = new int* [row];
    int** matrixResultMultiplying = new int* [row];

    createMatrixDynamic(matrixOne, row, column);
    createMatrixDynamic(matrixTwo, row, column);
    createMatrixDynamic(matrixResultMultiplying, row, column);

    fillMatrixRandomNumbers(matrixOne, row, column); 
    fillMatrixRandomNumbers(matrixTwo, row, column);

    cout << "\nThe Matrix One after to fill random number [ 1 - 10 ] \n\n";
    printArrayDynamic(matrixOne, row, column); 

    cout << "\n\nThe Matrix Two after to fill random number [ 1 - 10 ] \n\n";
    printArrayDynamic(matrixTwo, row, column);

    //Calc multiplying two matrix and storing the matrix another
    multiplyingTwoMatrix(matrixOne, matrixTwo , matrixResultMultiplying, row, column);
    cout << "\n\nThe Matrix Result Multiplying two matrixes  \n\n";

    printArrayDynamic(matrixResultMultiplying, row, column);


}

