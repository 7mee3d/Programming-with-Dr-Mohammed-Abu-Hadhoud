#pragma once 

#include <iostream> 
using namespace std;

namespace printArray2D {


	void printArray2Dimenional(int array[][100], int sizeRow, int sizeColumn) {
		
		cout << endl;
		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				printf("%-3d ", array[counter][counterJ]);
			}
			cout << " ]\n";
		}
	}


	void printArray2Dimenional(char array[][100], int sizeRow, int sizeColumn) {

		cout << endl;
		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				printf("%-3c ", array[counter][counterJ]);
			}
			cout << " ]\n";
		}
	}


	void printArray2Dimenional(char* array[], int sizeRow, int sizeColumn) {

		cout << endl;
		for (int counter{ 0 }; counter < sizeRow; counter++) {

			cout << "[ ";
			for (int counterJ{ 0 }; counterJ < sizeColumn;counterJ++) {
				printf("%-3c ", array[counter][counterJ]);
			}
			cout << " ]\n";
		}
	}

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
}; 