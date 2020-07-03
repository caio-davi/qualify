#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node* next;

    Node(int value){
        data = value;
    }

    Node(int value, Node* n){
        data = value;
        next = n;
    }

    bool hasNext(){
        if(next->data == NULL){
            return false;
        }else{
            return true;
        }
    }
}; 

class List {
    Node* root;
    public:

    List(int value){ 
        Node a = (value);
        root = &a; 
    }

};


int main(){ 

    // List head = (10);

    Node test = (10);
    Node test1 = (11);
    Node test2 = (12);

    test.next = &test1;

    cout << test.hasNext();
    cout << test1.hasNext();


    return 0; 

} 