#include <iostream>
using namespace std;

int main ()
{

    int value;
    
    value = 50;

    int * pointer = &value;

    cout << value << "\n";

    value++;
    
    cout << pointer << "\n";
    cout << *pointer << "\n";



    return 0;
}