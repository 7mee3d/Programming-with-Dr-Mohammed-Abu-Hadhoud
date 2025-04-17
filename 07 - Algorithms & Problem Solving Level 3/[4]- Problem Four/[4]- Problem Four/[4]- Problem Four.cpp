// [2]- Problem Two.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Problem [2] - [ Sum Each Row In Matrix ] 


#include <iostream>
#include <cstdlib>

unsigned short int const kZERO{ 0 };

using namespace std;

int readNumberPositive(string const message) {

    int number{};
    do {

        cout << message;
        cin >> number;

        while (cin.fail()) {

            cin.clear();
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

            cout << "\nPlease Sir , Enter the valid number not character ? ";
            cin >> number;
        }

    } while (number < ::kZERO);

    return number;
}


int randomNumber_Fram_To(int fram, int to) {

    int randomNumber;
    randomNumber = { (rand() % to - fram + 1) + fram };
    return randomNumber;

}

void fillArray2TwoDeminonalInRandomNumber(int* matrix[], int row, int column) {

    for (int counter{ 0 }; counter < row; counter++)
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
            matrix[counter][counterJ] = randomNumber_Fram_To(1, 100);

}
/*
void summationEachColumnInMatrixStoreingArray(int* matrix[], int row, int column, int* arrayOfColumn) {

    int summationEachColumn{ 0 };

    for (int counterI{ 0 }; counterI < row;counterI++)
    {
        for (int counterJ{ 0 }; counterJ < column; counterJ++)
        {
            summationEachColumn += matrix[counterJ][counterI];
        }

        arrayOfColumn[counterI] = summationEachColumn;
        summationEachColumn = { 0 };
    }
}
*/
void printArray2Dimenional(int* array[], int sizeRow, int sizeColumn) {

    cout << endl;
    for (int counter{ 0 }; counter < sizeRow; counter++) {

        cout << "[  ";
        for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
            printf("%-3d ", array[counter][counterJ]);
        }
        cout << "]\n";
    }
}


int summationEachColumnInMatrix(int* matrix[], int& row, int& column) {

    int summationEachColumn{ 0 };

    for (int counterI{ 0 }; counterI < row; counterI++)
        summationEachColumn += matrix[counterI][column];

    return summationEachColumn;
}


void print1DArraySumationEachColumn(int* matrix[], int row, int column) {

    for (int counter{ 0 }; counter < column; counter++)
    {
        cout << "Sum Column " << counter + 1;


        // space if the rows total more than 5 spaces     
        int result = summationEachColumnInMatrix(matrix, row, counter);
        printf(" = [%-6d]\n", result);
    }
}

int main()
{
    //To Genarating the Number Every run the programm 
    srand((unsigned)time(0));

    // Read row and column in the user 
    int row = readNumberPositive("\nEnter the Row : ");
    int column = readNumberPositive("\nEnter the Column : ");


    //Create the 2D array and 1D
    int** matrix = new int* [row];
    for (int counter{ 0 }; counter < row; counter++)
        matrix[counter] = new int[column];

    int* array1D = new int[row];

    //Fill Array number random 
    fillArray2TwoDeminonalInRandomNumber(matrix, row, column);

    //Print the martrix 
    cout << "\nThe Matrix [" << row << "][" << column << "] : \n";
    printArray2Dimenional(matrix, row, column);

    //Summation each Column in the Matrix 
    cout << "\n\nThe Summation of each Column in the matrix is results :\n";
    print1DArraySumationEachColumn(matrix, row, column);
    cout << endl << endl;



    //Realesed the array Dynamicly ( Deleteations ) 
    for (int counter{ 0 }; counter < row; counter++)
        delete[] matrix[counter];

    delete[] matrix;
    delete[]array1D;

}