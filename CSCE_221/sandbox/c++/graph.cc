#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include<tuple>
#include <algorithm>

using namespace std;


class Vertice{

public:
    string name;
    int numEdges;
    vector<tuple<int, Vertice*>> edges;
    
    Vertice(string name);
    void addEdge(int cost, Vertice *v);
    void print();
    void printAll();

};

Vertice::Vertice(string vName){ 
    name = vName;
    numEdges = 0;
};

void Vertice::addEdge(int cost, Vertice *v){
    tuple<int, Vertice*> edge;
    edge = make_tuple(cost, v);
    edges.push_back(edge);
    numEdges = ++numEdges;
}

void Vertice::print(){
    cout << name << "\n";
}

void Vertice::printAll(){
    cout << "Name: " << name << "\n";
    cout << "Vertices" << "\n";
    for(int i = 0; i < numEdges; i++){
        cout << get<0>(edges[i]) << " | " << get<1>(edges[i])->name << "\n"; 
    }
}

void printNames(vector<string> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i]; 
    }
}

  
int main(){ 
    Vertice s = Vertice("s");
    Vertice a = Vertice("A");
    Vertice b = Vertice("B");
    Vertice c = Vertice("C");
    Vertice d = Vertice("D");
    Vertice e = Vertice("E");
    Vertice f = Vertice("F");
    Vertice g = Vertice("G");
    Vertice h = Vertice("H");
    Vertice i = Vertice("I");
    Vertice t = Vertice("t");

    s.addEdge(1,&a);
    s.addEdge(4,&d);
    s.addEdge(6,&g);

    a.addEdge(2, &b);
    a.addEdge(2, &e);

    b.addEdge(2, &c);

    d.addEdge(3, &a);
    d.addEdge(3, &e);

    e.addEdge(2, &c);
    e.addEdge(3, &f);
    e.addEdge(3, &i);

    f.addEdge(1, &c);
    f.addEdge(3, &t);

    g.addEdge(2, &d);
    g.addEdge(1, &e);
    g.addEdge(6, &h);

    h.addEdge(2, &e);
    h.addEdge(6, &i);

    i.addEdge(1, &f);
    i.addEdge(4, &t);

    return 0; 
} 