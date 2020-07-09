# Chapter 3

#### 3.1

```c++
#include <list>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

typedef std::list<int> list_of_int;
// typedef std::vector<int> list_of_int;

void printLots(const list_of_int& L, const list_of_int& P){
    int count =0;
    for(list_of_int::const_iterator i = L.begin(), j= P.begin(); i!= L.end(); ++i, ++count){
        if(count == *j){
            cout << *i << ", ";
            ++j;
        }
    }
}

int main(){
    int start_s = clock();
    list_of_int L = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    list_of_int P = {1, 3, 4, 6};

    printLots(L,P);

    int stop_s = clock();

    cout << "\n Running time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) *1000 << "\n";
    return 0;
}
```

Ouputs:

```
// Using Vector:
200, 400, 500, 700,
Running time: 0.049
// Using List:
200, 400, 500, 700,
Running time: 0.062
```

If it uses a vector implementations it will be O(n), if it is a linked list, O(n^2).

#### 3.11

```c++
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
        lastNode = lastNode->next;
    }
    if(has(value) == true){
        cout << "Element " << value << " already in the list" << "\n";
    }else{
    lastNode->data = value;
    lastNode->next = new Node;
    size++;
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

    head.insert(2);
    head.insert(3);
    head.insert(3);
    head.insert(4);
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
```

Output:

```
Element 3 already in the list
2 3 4
Size: 3
Has 3: 1
Has 5: 0

Remove 3

2 4
Has 3: 0
Size: 2
```

#### 3.12

Just change the `insert()` prototype:

```c++
void List::insert(int value){
    Node* lastNode = root;
    for(int i=0; i<=size; i++){
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
```