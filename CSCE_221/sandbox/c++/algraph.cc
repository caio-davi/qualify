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
    vector<tuple<string, vector<int>>> nodes;
    int size;

    Graph();
    void addVertex(string name, vector<int> adjList);
    void printVertices();
    int getPosition(string name);

};

Graph::Graph(){
    size = 0; 
}

void Graph::addVertex(string name, vector<int> adjList){
    nodes[size] = make_tuple(name, adjList);
}

void Graph::printVertices(){
    for(auto node : nodes){
        cout << get<0>(node) ;// << "AdjList: " << get<1>(node) << "\n";
    }
}

int main(){

    Graph g = Graph();

    // vertex<int> adjListA = [0,1];

    g.addVertex("A", {1});
    g.addVertex("B", {0});

    g.printVertices();

    return 1;
}