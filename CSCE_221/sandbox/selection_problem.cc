#include <iostream>
#include <stdlib.h>

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
        v[i] = rand() % 100;
    }
    return v;
}

int select_k(int v[], int k){
    return v[k-1];
}

int main (){

    int size = 20;
    int a [size];
    int *v = create_array(a, size);

    print(v, size);
    bubble_sort(v, size);
    print(v, size);
    cout << "The Kth number is " << select_k(v, 8);

    return 0;
}