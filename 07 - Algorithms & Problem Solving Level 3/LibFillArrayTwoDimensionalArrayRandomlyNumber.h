#pragma once 

#include <iostream>
#include <vector>
#include <string> 
#include <random>

#include <time.h>

int const kSIZE_COLUMN_FIXED{ 100 };
using namespace std;


namespace LibReadElementSquareMatrix {


	int randomNumbers(int& fram, int to) {

		int numberRandom{};
		numberRandom = (rand() % (to - fram + 1) + 1); // fram = 1 , to = 10 ( genarate the random number 1- 11 ) ( 11 not included ) 
		return numberRandom; 

	}

	// Memory Static Allocation 


	//Function Fill array Squaring in random character Uppercase 

	void readElementArraySquareing(char array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				arrayDynamic[counter][counterJ] = static_cast <char>(randomNumbers(65, 90));
	}

	//Function Fill array Squaring in random character LowerCase   

	void readElementArraySquareing(char array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				arrayDynamic[counter][counterJ] = static_cast <char>(randomNumbers(97, 122));
	}


	//Function Fill array Squaring in random Numbers int 

	void readElementArraySquareing(int array[][kSIZE_COLUMN_FIXED], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				 array[counter][counterJ] = randomNumbers ( 1, 100 ) ;
	}



	// Memory Dynamic Allocation 

//Note : choise the function ( read Element in array ) dynamic >> look !! Must be the Delete array 
// to avoid memory lack 
// Using 

/*

for (int i = 0; i < sizeArray_Row; i++)
delete[] arrayDynamic[i];


*/


//Function Fill array Squaring in random Numbers int ( Dynamic )

	voidFillElementArraySquareingDynamicInRandomNumbersAndCharacter(int* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
			arrayDynamic[counter] = new char[sizeArray_Column];
		}

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				arrayDynamic[counter][counterJ] = (randomNumbers(1, 100));
	}


	
	
	

	//Function Fill array Squaring in random character Uppercase 
	voidFillElementArraySquareingDynamicInRandomNumbersAndCharacter (char* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
			arrayDynamic[counter] = new char[sizeArray_Column];
		}

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				 arrayDynamic[counter][counterJ] = static_cast < char > ( randomNumbers( 65 , 90 ) )  ;
	}

	//Function Fill array Squaring in random character LowerCase 
	voidFillElementArraySquareingDynamicInRandomNumbersAndCharacter(char* arrayDynamic[], int& sizeArray_Row, int& sizeArray_Column) {

		for (int counter{ 0 }; counter < sizeArray_Row; counter++) {
			arrayDynamic[counter] = new char[sizeArray_Column];
		}

		for (int counter{ 0 }; counter < sizeArray_Row;counter++)
			for (int counterJ{ 0 }; counterJ < sizeArray_Column; counterJ++)
				arrayDynamic[counter][counterJ] = static_cast <char>(randomNumbers(97, 122));
	}


};