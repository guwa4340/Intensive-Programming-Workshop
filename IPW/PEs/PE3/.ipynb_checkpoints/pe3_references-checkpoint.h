#include <iostream>
#ifndef _PE3_REFERENCES_H_ // header guard
#define _PE3_REFERENCES_H_
//Name: Gunther Wallach

class Custom{
public:
    Custom();
    
    Custom(int n);
    
    int get_num();
    
    Custom operator + (const Custom& c){
        Custom custom;
        custom.num = this->num + c.num;
        return custom;
    }
    bool operator == (const Custom& c){
        Custom custom;
        if (this->num == c.num){
            return true;
        }else{
            return false;
        }
    }
private:
    int num;   
};

void pointer(int *par);

void reference(int& ref);

int * constref(const int& ref);

#endif