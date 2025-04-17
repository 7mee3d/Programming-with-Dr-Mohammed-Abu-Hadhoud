// [1]- Problem #1.cpp : This file contains the 'main' function. Program execution begins and ends there.



//Problem one [ Fill Matrix 3x3 Random Numbers ]  

#include <iostream>
#include "I:\\Programming part 2\\- Programming with Dr. Mohammed Abu-Hadhoud\07 - Algorithms & Problem Solving Level 3\LibReadElementInArrayTwoDimensional.h"
#include "I:\\Programming part 2\\- Programming with Dr. Mohammed Abu-Hadhoud\07 - Algorithms & Problem Solving Level 3\LibReadNumbersInUser.h"
#include "I:\\Programming part 2\\- Programming with Dr. Mohammed Abu-Hadhoud\07 - Algorithms & Problem Solving Level 3\LibFillArrayTwoDimensionalArrayRandomlyNumber.h"
#include "I:\\Programming part 2\\- Programming with Dr. Mohammed Abu-Hadhoud\07 - Algorithms & Problem Solving Level 3\LibPrintArrayTwoDimensional.h"


using namespace std;


int main()
{

	srand(time(0));
	cout << endl;

	int row = myLibRead::readNumberPositiveInteger("Enter the Row , Please Sir : ");
	int column = myLibRead::readNumberPositiveInteger("\nEnter the Column , Please Sir : ");

	int** array = new int* [row];

	for (int i{ 0 }; i < row; i++) {
		array[i] = new int[column];
	}


	LibFillArrayRandom::FillElementArraySquareingDynamicInRandomNumbersAndCharacter(array, row, column);
	cout << "\n\nThe Matric is fill random number [ 1 - 100 ] \n";
	printArray2D::printArray2Dimenional(array, row, column);
}

