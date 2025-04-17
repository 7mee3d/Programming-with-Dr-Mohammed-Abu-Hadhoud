#pragma once 

#include <iostream> 
using namespace std;

namespace printArray2D {


	void printArray2Dimenional(int array[][100], int sizeRow, int sizeColumn) {
		
		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				cout << array[counter][counterJ] << " ";
			}
			cout << " ]\n";
		}
	}


	void printArray2Dimenional(char array[][100], int sizeRow, int sizeColumn) {

		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				cout << array[counter][counterJ] << " ";
			}
			cout << " ]\n";
		}
	}


	void printArray2Dimenional(char* array[][100], int sizeRow, int sizeColumn) {

		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				cout << array[counter][counterJ] << " ";
			}
			cout << " ]\n";
		}
	}

		void printArray2Dimenional(int* array[][100], int sizeRow, int sizeColumn) {

		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				cout << array[counter][counterJ] << " ";
			}
			cout << " ]\n";
		}
	}
}; 