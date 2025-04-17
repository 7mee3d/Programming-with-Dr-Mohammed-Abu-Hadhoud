// [6]- Problem Six.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std; 

unsigned short int kZERO{ 0 }; 

int readNumberPostive(string const message) {

    int number{ ::kZERO };

    do {
        cout << message;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "\nPlease sir , enter the number not character : ";
            cin >> number;


        }
    } while (number < ::kZERO );
    return number; 
}

void printArrayDynamic(int* matrix[], int row, int column) {

    for (int counter{ ::kZERO }; counter < row; counter++) {
        cout << "[   ";
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
            printf("%-5d", matrix[counter][counterJ]);

        cout << " ]\n";
    }
}


void readElementInMatrix(int* matrix[], int row, int column) {


    for (int counter{ ::kZERO }; counter < row; counter++) {
        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++) {
            cout << "Enter the Element [" << counter + 1 << "][" << counterJ + 1  << "] : ";
            cin >> matrix[counter][counterJ];
        }
        cout << endl;

    }
}

void fillMatrixNumberOrderd(int* matrix[], int row, int column) {

    int counter3 = 0;

    for (int counter{ ::kZERO }; counter < row; counter++) {

        for (int counterJ{ ::kZERO }; counterJ < column; counterJ++)
        {
            counter3++;
            matrix[counter][counterJ] = counter3;
        }
    }

        
}

int main()
{
    
    int row{ readNumberPostive("Enter the Row : ") };
    int column{ readNumberPostive("Enter the Column : ") };

    int** matrix = new int *[row];
    for (int i{ ::kZERO }; i < row; i++)
        matrix[i] = new int[column]; 

    // read Element to store in matrix 
    readElementInMatrix(matrix, row, column); 

    // print matrix to be enterd 
    cout << endl;
    printArrayDynamic(matrix, row, column);

    //fill matrix orderd numbers 
    cout << endl << endl << endl;
    cout << "The Matrix fill is numbers orderd \n";
    fillMatrixNumberOrderd(matrix, row, column);
    printArrayDynamic(matrix, row, column);


    for (int i = 0; i < row; i++)
        delete[]matrix[i];

    delete[] matrix; 


}

