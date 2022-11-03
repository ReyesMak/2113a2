#include <iostream>
#include "d2boh.h"
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){
    //Declare stringstream object of {convert} and {number}
    stringstream convert, number;
    //Declare integer {mode} and {num}
    int mode, num;
    //Convert string of the first argument {argv[1]} to integer {mode}
    convert << argv[1];
    convert >> mode;
    //Convert string of the second argument {argv[2]} to integer {num}
    number << argv[2];
    number >> num;
    
    //Convert decimal number to binary number
    if (mode==1){
        //Declare an integer array of size 10
        int myarray[10]={};
        //Call function {decimal_to_binary} from d2boh.cpp
        decimal_to_binary(num, myarray);
        //Display the binary number
        for (int i = (10 - decimal_to_binary(num, myarray)); i<10; ++i){
            cout<<myarray[i];
        }
        //Display an empty line
        cout << endl;
    }
    
    //Convert decimal number to octal number
    else if (mode==2){
        //Declare an integer array of size 10
        int myarray[10]={};
        //Call function {decimal_to_octal} from d2boh.cpp
        decimal_to_octal(num, myarray);
        //Display the octal number
        for (int i = (10 - decimal_to_octal(num, myarray)); i<10; ++i){
            cout<<myarray[i];
        }
        //Display an empty line
        cout << endl;
    }
    
    //Convert decimal number to hexadecimal number
    else if (mode==3){
        //Declare a character array of size 10
        char myarray[10]={};
        //Call function {decimal_to_hexadecimal} from d2boh.cpp
        decimal_to_hexadecimal(num, myarray);
        //Display the hexadecimal number
        for (int i = (10 - decimal_to_hexadecimal(num, myarray)); i<10; ++i){
            cout<<myarray[i];
        }
        //Display an empty line
        cout << endl;
    }
        return 0;
}
