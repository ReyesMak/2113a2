// d2boh.cpp

#include <iostream>
#include <cmath>
#include "d2boh.h"
using namespace std;

int decimal_to_binary(int input, int output[10]) {
	int count = 0;
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(2,i) >= 1){
			output[9-i]=floor(input/pow(2,i));
			input-=pow(2,i);
			count++;
		}
	}
	return count;
}

int decimal_to_octal(int input, int output[10]) {
	int count = 0;
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(8,i) >= 1){
			output[9-i]=floor(input/pow(8,i));
			input-=pow(8,i);
			count++;
		}
	}
	return count;
}

int decimal_to_hexadecimal(int input, char output[10]) {
	int count = 0;
	for (int i = 9; i >= 0 ; --i){
		if (input / pow(16,i) >= 1){
			// consider ascii value
			output[9-i]=floor(input/pow(16,i));
			input-=pow(16,i);
			count++;
		}
	}
	return count;
}

int main(){
	int output[10]={0,0,0,0,0,0,0,0,0,0};
	decimal_to_binary(10,output);
	return 0;
}