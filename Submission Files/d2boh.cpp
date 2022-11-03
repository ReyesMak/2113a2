// d2boh.cpp
//Include the necessary libraries
#include <iostream>
#include <cmath>
#include "d2boh.h"
using namespace std;

int decimal_to_binary(int input, int output[10]){
	//Declare integer {count} to store the number of digits after conversion
	int count = 0;
	//Display digits from higher index to lower index
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(2,i) >= 1){
			//The digit representing the {i} power of 2 is stored at the (9-i)th index of the array {output}
			output[9-i]=floor(input/pow(2,i));
			//{input} decreases by the decimal value of the calculated digit
			input-=pow(2,i);
			//{count} increments by 1 after calculating the digit
			count++;
		}
		//Ensure {count} increments by 1 if the calculated digit is equal to 0
		else if (count > 0){
			count++;
		}
	}	
	return count;
}

int decimal_to_octal(int input, int output[10]) {
	//Declare integer {count} to store the number of digits after conversion
	int count = 0;
	//Display digits from higher index to lower index
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(8,i) >= 1){
			//The digit representing the {i} power of 8 is stored at the (9-i)th index of the array {output}
			output[9-i]=floor(input/pow(8,i));
			//{input} decreases by the decimal value of the calculated digit
			input-=pow(8,i)*floor(input/pow(8,i));
			//{count} increments by 1 after calculating the digit
			count++;
		}
		//Ensure {count} increments by 1 if the calculated digit is equal to 0
		else if (count > 0){
			count++;
		}
	}
	return count;
}

int decimal_to_hexadecimal(int input, char output[10]) {
	//Declare integer {count} to store the number of digits after conversion
	int count = 0;
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(16,i) >= 1){
			//Below is based on the ASCII decimal value of characters
			if (floor(input/pow(16,i)) < 10){
				//An addition of 48 is necessary to convert an integer digit which is smaller then 10 
				//to a character of number digits in the array
				output[9-i]=char(floor(input/pow(16,i)) + 48);
			}
			else{
				//An addition of 55 is necessary to convert the digit which is larger than or equal to 10
				//to a character of letters in the array
				output[9-i]=char(floor(input/pow(16,i)) + 55);
			}
			//{input} decreases by the decimal value of the calculated digit
			input-=pow(16,i)*floor(input/pow(16,i));
			//{count} increments by 1 after calculating the digit
			count++;
		}
		//Ensure {count} increments by 1 if the calculated digit is equal to 0
		else if (count > 0){
			count++;
		}
	}
	return count;
}
