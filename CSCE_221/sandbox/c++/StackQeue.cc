#include <bits/stdc++.h> 

using namespace std; 

class StackQeue{ 
    public: 
  
    // Data Members 
    stack <int> s;

    void push(int elem){
        s.push(elem);
    }

    int top_pop(){
        int top = s.top();
        s.pop();
        return top;
    }

    int bottom_pop(){
        stack <int> copy = s;
        stack <int> newS;
        s = newS;
        int temp = 0;
        while (!copy.empty()){ 
            temp = copy.top(); 
            newS.push(temp);
            copy.pop(); 
        }
        newS.pop(); 
        while (!newS.empty()) { 
            s.push(newS.top());
            newS.pop(); 
        } 
        return temp;
    }


    void print(){
        stack <int> temp = s;
        cout << "----------------" << '\n'; 
        while (!temp.empty()){ 
            cout << '\t' << temp.top() << '\n'; 
            temp.pop(); 
        } 
        cout << "----------------" << '\n'; 
    }

    bool empty(){
        return s.empty();
    }

    bool top(){
        return s.top();
    }
};

int main (){ 
    StackQeue sq;

    sq.push(10); 
    sq.push(30); 
    sq.push(20); 
    sq.push(5); 
    sq.push(1); 

    sq.print();

    cout << "Top pop: " << sq.top_pop() << "\n";
    
    sq.print();

    cout << "Bottom pop: " << sq.bottom_pop() << "\n";
    
    sq.print();

    return 0;
}