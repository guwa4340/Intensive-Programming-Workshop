#include <iostream>
#include "pe3_references.h"

using namespace std;
// Name: Gunther Wallach

Custom::Custom(){//constructor
    num = 0;
}

Custom::Custom(int n){
    num = n;
}

int Custom::get_num(){
    return num;
}


void pointer(int *par){
        cout << *par << endl;
}

void reference(int& ref){
    cout << ref << endl;
}

int * constref(const int& ref){
    int tmp = ref;
    int *ret = &tmp;
    cout << "Pointer = " << *ret << endl;
    cout << "Success" << endl;
    return ret;
}