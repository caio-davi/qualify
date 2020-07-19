#include <iostream>
using namespace std;

void print(int pointer){
    cout << pointer << "\n";
}

void printPointer(int* pointer){
    cout << *pointer << "\n";
    cout << pointer << "\n";
}

int main ()
{

    int value;
    
    value = 50;

    int * pointer = &value;

    cout << value << "\n";

    value++;

    // print(&pointer);
    printPointer(pointer);
    printPointer(&value);


    return 0;
}