#include <list>
#include <iostream> 
#include <iterator> 
using namespace std; 
  
void printList(list <int> l){ 
    list <int> :: iterator it; 
    for(it = l.begin(); it != l.end(); ++it) 
        cout << "  " << *it; 
    cout << '\n'; 
}

list <int> common (list <int> A, list <int> B){
    list <int> merged;
    list <int> :: iterator itA;
    list <int> :: iterator itB; 
    itA = A.begin();
    itB = B.begin();
    while(itA != A.end() && itB != B.end()){
        if(*itA == *itB){
            merged.push_back(*itA);
        }
        if(*itA < *itB){
            itA++;
        }else{
            itB++;
        }
    } 
    return merged;
}

list <int> merge (list <int> A, list <int> B){
    list <int> merged;
    list <int> :: iterator itA;
    list <int> :: iterator itB; 
    itA = A.begin();
    itB = B.begin();
    while(itA != A.end() && itB != B.end()){
        if(*itA < *itB){
            merged.push_back(*itA);
            itA++;
        }else{
            merged.push_back(*itB);
            itB++;
        }
    } 
    return merged;
}

int main(){
    list <int> A;
    list <int> B;
    
    A.push_back(2);
    A.push_back(4);
    A.push_back(8);
    A.push_back(9);
    A.push_back(16);
    A.push_back(32);
    A.push_back(81);

    B.push_back(1);
    B.push_back(3);
    B.push_back(4);
    B.push_back(9);
    B.push_back(21);
    B.push_back(81);

    cout << "Common: ";
    printList(common(A,B));
    cout << "Merge: ";
    printList(merge(A,B));

    return 1;
}