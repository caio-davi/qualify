# Data Structures and Algorithm Analysis in C++

Mark Allen Weiss

## Chapter 3

### 3.1 

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