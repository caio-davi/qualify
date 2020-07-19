#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <tuple>
#include <list>
#include <algorithm>

using namespace std;

// Adjacency List Graph
class Graph{

public:
    vector<string> names;
    list<int> edges;
    int size;

    Graph();
    void addVertex(string name);
    void addEdge(string v, string u);
    void printVertices();
    int getPosition(string name);

};

Graph::Graph(){
    size = 0; 
}

void Graph::addVertex(string name){
    names.push_back(name);
    size = ++size;
}

void Graph::addEdge(string vName, string uName){
    int v = getPosition(vName);
    int u = getPosition(uName);
    edges[v].push_back(u);
}

void Graph::printVertices(){
    for(int i = 0; i < size; i++){
        cout << "["<< i << "]: " << names[i] << "\n";
    }
}

int Graph::getPosition(string name){
    for(int i = 0; i < size; i++){
        if(names[i]== name)
            return i;
    }
    return 9999;

}

int main(){

    Graph g = Graph();

    g.addVertex("A");
    g.addVertex("B");

    g.printVertices();

    cout << g.getPosition("A") << "\n";
    g.addEdge("A", "B");
    return 1;
}