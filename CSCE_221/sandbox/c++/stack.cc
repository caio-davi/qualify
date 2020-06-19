#include <bits/stdc++.h> 
using namespace std; 
  
void showstack(stack <int> s) {   
    cout << '\n';
    cout << "----------------" << '\n'; 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top() << '\n'; 
        s.pop(); 
    } 
    cout << "----------------" << '\n'; 
}

// Pop qeue-style
int q_pop(stack <int> s){
    stack <int> temp;
    while (!s.empty()) 
    { 
        temp.push(s.top()); 
        s.pop(); 
    } 
    return temp.top();
}
  
int main (){ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 

    cout << "Qeue-Style Pop: " << q_pop(s) << '\n';

    showstack(s); 
  
    return 0; 
} 