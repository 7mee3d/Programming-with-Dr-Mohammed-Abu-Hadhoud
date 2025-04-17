#pragma once 

#include <iostream>
#include <vector>
#include <string> 

int const kSIZE_COLUMN_FIXED{ 100 };
using namespace std; 

namespace LibReadElementSquareMatrix {

	// Memory Static Allocation 

	//Function read Element in array the every Element type is [int]  and type array is [int]

	void readElementArraySquareing(int array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row , int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> array[counter][counterJ];
	}

	//Function read Element in array the every Element type is [float]  and type array is [float]

	void readElementArraySquareing(float array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++) {
				cin >> array[counter][counterJ];

				array[counter][counterJ] = static_cast<float>(array[counter][counterJ]);
			}
	}

	//Function read Element in array the every Element type is [double]  and type array is [double]

	void readElementArraySquareing(double array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> array[counter][counterJ];
	}

	//Function read Element in array the every Element type is [string]  and type array is [string]

	void readElementArraySquareing(string array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				getline (cin ,  array[counter][counterJ]);
	}
	//Function read Element in array the every Element type is [char]  and type array is [char] 

	void readElementArraySquareing(char array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> array[counter][counterJ];
	}

	//Function read Element in array the every Element type is [long long]  and type array is [long long] 

	void readElementArraySquareing(long long array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> array[counter][counterJ];
	}

	//Function read Element in array the every Element type is [long double] and type array is [long double] 

	void readElementArraySquareing(long double array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> array[counter][counterJ];
	}



		// Memory Dynamic Allocation 

	//Note : choise the function ( read Element in array ) dynamic >> look !! Must be the Delete array 
	// to avoid memory lack 
	// Using 

	/*
	
	for (int i = 0; i < sizeArray_Row; i++) 
    delete[] arrayDynamic[i];

	
	*/
	//Function read Element in array Dynamic the every Element type is [int]  and type array is [int]


	void readElementArraySquareingDynamic(int *arrayDynamic [] , int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
			arrayDynamic[counter] = new int [sizeArray_Column];
		}

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				cin >> arrayDynamic[counter][counterJ]; 
	}


	//Function read Element in array Dynamic the every Element type is [float] and type array is [float]

	void readElementArraySquareingDynamic(float* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
			arrayDynamic[counter] = new float[sizeArray_Column];
		}

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++) {
				cin >> arrayDynamic[counter][counterJ];

				arrayDynamic[counter][counterJ] = static_cast <float>(arrayDynamic[counter][counterJ]);

			}
	}

	//Function read Element in array Dynamic the every Element type is [double] and type array is [double]

		void readElementArraySquareingDynamic(double* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

			for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
				arrayDynamic[counter] = new double[sizeArray_Column];
			}

			for (int counter{ 0 }; counter < sizeArray_Row;counter++)
				for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
					cin >> arrayDynamic[counter][counterJ];

		}	
		
		//Function read Element in array Dynamic the every Element type is [string] and type array is [string]

		void readElementArraySquareingDynamic(string* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

			for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
				arrayDynamic[counter] = new string[sizeArray_Column];
			}

			for (int counter{ 0 }; counter < sizeArray_Row;counter++)
				for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
					getline(cin, arrayDynamic[counter][counterJ]);

		}
		//Function read Element in array Dynamic the every Element type is [char] and type array is [char]

		void readElementArraySquareingDynamic(char* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

			for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
				arrayDynamic[counter] = new char[sizeArray_Column];
			}

			for (int counter{ 0 }; counter < sizeArray_Row;counter++)
				for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
					cin >> arrayDynamic[counter][counterJ];

		}
		//Function read Element in array Dynamic the every Element type is [long long] and type array is [long long]

		void readElementArraySquareingDynamic(long long * arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

			for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
				arrayDynamic[counter] = new long long[sizeArray_Column];
			}

			for (int counter{ 0 }; counter < sizeArray_Row;counter++)
				for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
					cin >> arrayDynamic[counter][counterJ];

		}
		//Function read Element in array Dynamic the every Element type is [long double] and type array is [long double]

		void readElementArraySquareingDynamic(long double* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

			for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
				arrayDynamic[counter] = new long double[sizeArray_Column];
			}

			for (int counter{ 0 }; counter < sizeArray_Row;counter++)
				for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
					cin >> arrayDynamic[counter][counterJ];

		}
	
}; 