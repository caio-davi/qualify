#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    Node* next;
}; 

class List {
    private:

    int size;

    public:
    Node* root;

    List();                         // Constructor
    void insert(int value);         // Prototypes
    void remove_at(int index);
    void remove(int value);
    void printAll();
    int listSize();
    bool has(int value);
};

List::List(){
    root = new Node;
    root->data = 0;
    root->next = new Node;
    root->next->data = 9999;
    size = 0;
}

void List::printAll(){
    Node* lastNode = root;
    lastNode = lastNode->next;
    for(int i =0; i < size; i++){
        cout << lastNode->data << " ";
        lastNode = lastNode->next;
    }
    cout << "\n";
}

bool List::has(int value){
    Node* lastNode = root;
    for(int i=0; i<=size; i++){
        if(lastNode->data == value){
            return true;
        }
        lastNode = lastNode->next;
    }
    return false;
}

void List::insert(int value){
    Node* lastNode = root;
    for(int i=0; i<=size; i++){
        // Node* temp = lastNode;
        if(lastNode->data == value){
            cout << "Element " << value << " already in the list" << "\n";
        }else{
            Node* next = lastNode->next;
            if (next->data > value){
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = next;
                lastNode->next = newNode; 
                size++;
                break;
            }else{
                lastNode = lastNode->next;
            }
        }
    }
}

int List::listSize(){
    return size;
}

void List::remove(int value){
    Node* lastNode = root;
    for(int i=0; i<=size; i++){
        Node* temp = lastNode;
        lastNode = lastNode->next;
        if(lastNode->data == value){
            temp->next = lastNode->next;
            size--;
            break;
        }
    }
}

int main(){ 

    List head = List();

    head.insert(5);
    head.insert(4);
    head.insert(2);
    head.insert(-9);
    head.insert(22);
    head.insert(3);
    head.printAll();

    cout << "Size: " << head.listSize() << "\n";
    cout << "Has 3: " << head.has(3) << "\n";
    cout << "Has 5: " << head.has(5) << "\n\n";

    cout << "Remove 3 " << "\n\n";
    head.remove(3);

    head.printAll();
    cout << "Has 3: " << head.has(3) << "\n";
    cout << "Size: " << head.listSize() << "\n";

    return 0; 

} 