#include <bits/stdc++.h>
#include <stdio.h>


using namespace std; 
  
int myfunct ( unsigned int x , int y ) {
    if ( x == 0 ) {
        return 0;
    }
    cout << "x= " << x << " | y= " << y << "\n";
    return x + myfunct ((x>>y) , (y + 1)) ;
}

int main(){ 

    int a, b, c;
    a=2;
    b=4;
    c = myfunct(7,0);

    cout << c << "\n";

    return 0;
}
