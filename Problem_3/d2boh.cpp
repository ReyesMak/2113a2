// d2boh.cpp

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
			//The digit representing the {i}th exponents of 2 is stored at the (9-i)th index of the array {output}
			output[9-i]=floor(input/pow(2,i));
			//{input} reduces by 2^i after calculating the digit
			input-=pow(2,i);
			//{count} increments by 1 after calculating the digit
			count++;
		}
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
			output[9-i]=floor(input/pow(8,i));
			input-=pow(8,i)*floor(input/pow(8,i));
			count++;
		}
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
			// consider ascii value
			if (floor(input/pow(16,i)) < 10){
				output[9-i]=char(floor(input/pow(16,i)) + 48);
			}
			else{
				output[9-i]=char(floor(input/pow(16,i)) + 55);
			}
			input-=pow(16,i)*floor(input/pow(16,i));
			count++;
		}
		else if (count > 0){
			count++;}
	}
	return count;
}
