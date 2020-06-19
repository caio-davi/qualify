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
}; 

class List {
private:
    Node* head;

public:

    List(int value){
        head = new Node(value);
    }

    void insert(int value){
        Node* iterator = head; 
        while(iterator->next != NULL){
            iterator = iterator->next;
        }
        Node* newNode = new Node(value);
        iterator->next = newNode;
    }

    // void insert(Node* n, int position){
    //     int iterationCounter = 0;
    //     while(n->next != NULL){
    //         if(iterationCounter>position){
    //             cout << "Error. Cuurent list has only " << iterationCounter << "elements. \n";
    //             return ;
    //         }
    //         if(iterationCounter == position){
    //             Node* temp = n->next;
    //             n->next = 
    //         }
    //     }
    // }

    void print(){ 
        Node* iterator = head; 
        cout << "ENTROU";
        while (iterator->next != NULL) { 
            cout << iterator->data << " "; 
            iterator = iterator->next; 
        } 
        cout << "\n";
    } 
};



void printRecursive (Node* n){
    if(n->next != NULL){
        cout << n->data << " ";
        printRecursive(n->next);
    }else{
        cout << n->data << "\n";
    }
}



int main(){ 

    List* head = new List(10);

    // head.insert(5);

    head->print();
    return 0; 

} 