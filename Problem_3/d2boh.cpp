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
		else if (count > 0){
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
// int main(){
// 	int output[10]={};
// 	cout << decimal_to_octal(36,output) << endl;
// 	for (int i = 0; i< 10;++i){
// 		cout << output[i] << " ";
// 	}
// 	return 0;
// }