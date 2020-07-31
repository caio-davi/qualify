# Chapter 3

#### 3.1
[Code](./31.cc)

Ouputs:

```
// Using Vector:
200, 400, 500, 700,
Running time: 0.049
// Using List:
200, 400, 500, 700,
Running time: 0.062
```

If it uses a vector implementation it will be O(n), if it is a linked list, O(n^2).

#### 3.2
a) The parameter is the element before the ones to be swapped. 
```c++
void swap(Node* before){
    Node* first = before-> next;
    Node* second = first-> next;
    first->next = second-> next;
    before->next = second;
    second->next = first;
}
```
b) The parameter is the first element be swapped. 
```c++
void swap(Node* first){
    Node* before = first-> previous;
    Node* second = first-> next;
    Node* after = second-> next;
    before->next = second;
    second->previous = before;
    second->next = first;
    first->previous = second;
    first->next = after;
    after->previous = first;
}
```
#### 3.11
[Code](./311.cc)

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

Just change the `insert()` prototype. [Code](./312.cc).

#### 3.13