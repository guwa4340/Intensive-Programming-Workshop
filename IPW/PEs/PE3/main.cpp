#include <iostream>
#include "pe3_references.h"
//Name: Gunther Wallach
using namespace std;

int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int var = 0;
    cout << var << endl;
    // 2) Declare a pointer to that int
    int *v = &var;
    // 3) Increment the int via the pointer
    (*v)++;
    cout << var << endl;
    // 4) Declare a reference to your int
    int& v_ = var;
    // 5) Increment the int via the reference
    ++(v_);
    cout << var << endl;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: 
    //Question is worded oddly; none of the reference or point variable need to be edited to output the value of var. 
    //This is because the int var variable is changed in its value, but its address is still the same
    
    
    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: the var variable is modified, where as the other variable just point to the orginal variable var

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: 

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    pointer(&var);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer:
    //pointer(v_);
    // No, if you don't reference the address the pointer does not know what it is pointing at

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    reference(var);
    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: yes
    reference(*v);
    // 13) Can you pass your reference from #4 to the function from #11? yes
    reference(v_);
    // Answer: yes

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    constref(var);
    constref(var);
    constref(var);
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: An output parameter ensures that the output is the variable type specificed, 
    //but a return object is literally just the variable to be returned from the function
    
    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:
    Custom c1(1);
    Custom c2(1);
    Custom c3;
    c3 = c1 + c2;
    cout << "New Added Custom =" << c3.get_num() << endl;
    if (c1 == c2){
        cout << "Operator Successful in Comparing Truth" << endl;
    }else{
        cout << "Operator Not Successful in Comparing Truth" << endl;
    }
    return 0;
}