#include <iostream>
#include "d2boh.h"
#include <sstream>
using namespace std;

int main(int argc, char* argv[]){
    stringstream convert, number;
    int mode, num;
    convert << argv[1];
    convert >> mode;
    number << argv[2];
    number >> num;
    if (mode==1){
        int myarray[10]={};
        decimal_to_binary(num, myarray);
        for (int i = (10 - decimal_to_binary(num, myarray)); i<10; ++i){
            cout<<myarray[i];
        }
        cout << endl;
    }
    else if (mode==2){
        int myarray[10]={};
        decimal_to_octal(num, myarray);
        for (int i = (10 - decimal_to_octal(num, myarray)); i<10; ++i){
            cout<<myarray[i];
    }
        cout << endl;}
    else if (mode==3){
        char myarray[10]={};
        decimal_to_hexadecimal(num, myarray);
        for (int i = (10 - decimal_to_hexadecimal(num, myarray)); i<10; ++i){
            cout<<myarray[i];
    }
        cout << endl;}
        return 0;
}