#include <iostream>
#include <stdlib.h>
#include <stdio.h> 

using namespace std;

void print (int v[], int size){
    for(int i = 0; i< size; i++){
        cout << v[i] << " | ";
    }
    cout << "\n";
}

void swap (int v[], int k){
  int temp = v[k];
  v[k] = v[k+1];
  v[k+1] = temp;
}

void bubble_sort(int v[], int size){
    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0; i < size-1; i++){
            if(v[i]>v[i+1]){
                swap(v, i);
                changed = true;
            }
        }
    }
}

int * create_array(int v[], int size){
    for(int i = 0; i< size; i++){
        v[i] = rand() % 10000;
    }
    return v;
}

int select_k(int v[], int k){
    return v[k-1];
}

int main (){

    int size;
    cout << "Size of randomly generated array:";
    cin >> size;
    int a [size];
    int *v = create_array(a, size);
    print(v, size);
    
    int k ;
    cout << "The k(th) element on the array:";
    cin >> k;
    if(k < size){
        bubble_sort(v, size);
        print(v, size);
        cout << "The "<< k << "th number is " << select_k(v, k)<< "\n";
    }else{
        cout << "K is bigger than the Length of array.";
    }

    return 0;
}