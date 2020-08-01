#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;


class Vertex{

public:
    string name;
    int numEdges;
    vector<tuple<int, Vertex*>> edges;
    
    Vertex();
    Vertex(string name);
    void addEdge(int cost, Vertex *v);
    void print();

};

Vertex::Vertex(){};

Vertex::Vertex(string vName){ 
    name = vName;
    numEdges = 0;
};

void Vertex::addEdge(int cost, Vertex *v){
    tuple<int, Vertex*> edge;
    edge = make_tuple(cost, v);
    edges.push_back(edge);
    numEdges = ++numEdges;
}

void Vertex::print(){
    cout << "Name: " << name << "\n";
    cout << "Vertices" << "\n";
    for(int i = 0; i < numEdges; i++){
        cout << get<0>(edges[i]) << " | " << get<1>(edges[i])->name << "\n"; 
    }
}


void printEdgesCosts(vector<tuple<Vertex, int, string>> edgesCosts){
    for(auto i : edgesCosts){
        cout << get<0>(i).name << " | ";
        cout << get<1>(i) << " | ";
        cout << get<2>(i) << "\n";
    }
}

Vertex getMinCost(vector<tuple<Vertex, int, string>> edgesCosts){
    int min = 9999;
    Vertex vMin;
    for(auto i : edgesCosts){
        if(get<1>(i) < min)
            vMin = get<0>(i);
    }
    return vMin;
}

void printStringVector(vector<string> v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << " \n";
}

void printStringList(list<string> l){
    for(auto i : l){
        cout << i << " ";
    }
    cout << " \n";
}

void printStringListInverse(list<string> l){
    while(!l.empty()){
        cout << l.back() << " ";
        l.pop_back();
    }
    cout << " \n";

}

bool wasVisited(vector<string> visited, string name){
    return (std::find(visited.begin(), visited.end(), name) != visited.end());
    }

bool wasVisited(list<string> visited, string name){
    return (std::find(visited.begin(), visited.end(), name) != visited.end());
    }

Vertex getNext(vector<tuple<Vertex, int, string>> edgesCosts, vector<string> visited){
    int min = 9999;
    Vertex next;
    for(auto i : edgesCosts){
        if(get<1>(i) < min){
            if (!wasVisited(visited, get<0>(i).name)){
                next = get<0>(i);
                min = get<1>(i);
            }
        }
    }
    return next;
}

int getCost(vector<tuple<Vertex, int, string>> edgesCosts, string name){
    for(auto i : edgesCosts){
        if(get<0>(i).name == name){
            return get<1>(i);
        }
    }
    return 99999;
}

bool tableContains(vector<tuple<Vertex, int, string>> edgesCosts, string name){
    for(auto i : edgesCosts){
        if(get<0>(i).name == name){
            return true;
        }
    }
    return false;
}

void updateRow( vector<tuple<Vertex, int, string>>* edgesCosts, 
                string name, tuple<Vertex, int, string> newRow){
    for(int i = 0; i < (*edgesCosts).size(); i++){
        if(get<0>((*edgesCosts)[i]).name == name){
            (*edgesCosts)[i] = newRow;
        }
    }
}

void dijkstra(  Vertex v,
                vector<string> visited,
                vector<tuple<Vertex, int, string>> *edgesCosts){
    if(v.numEdges == 0) return; 
    int residual = getCost(*edgesCosts, v.name);
    for(int i = 0; i < v.numEdges; i++){
        if(!wasVisited(visited, get<1>(v.edges[i])->name)){
            if(!tableContains(*edgesCosts, get<1>(v.edges[i])->name)){
                tuple<Vertex, int, string> cost  = make_tuple(*get<1>(v.edges[i]), residual+get<0>(v.edges[i]), v.name);
                edgesCosts->push_back(cost);
                string node =  get<1>(v.edges[i])->name;       
            }else{
                int currentCost = getCost(*edgesCosts, get<1>(v.edges[i])->name);
                int newCost = residual+get<0>(v.edges[i]);
                if (newCost <= currentCost){
                    tuple<Vertex, int, string> newRow  = make_tuple(*get<1>(v.edges[i]), residual+get<0>(v.edges[i]), v.name);
                    updateRow(edgesCosts, get<1>(v.edges[i])->name, newRow);
                }
            }
        }
    }
    visited.push_back(v.name);
    Vertex next = getNext(*edgesCosts, visited);
    dijkstra (next, visited, edgesCosts);
}

void dijkstra (Vertex v){
    vector<string> visited;
    vector<tuple<Vertex, int, string>> edgesCosts;
    tuple<Vertex, int, string> initial = make_tuple(v, 0, "");
    edgesCosts.push_back(initial);
    for(int i = 0; i < v.numEdges; i++){
        tuple<Vertex, int, string> cost = make_tuple(*get<1>(v.edges[i]), get<0>(v.edges[i]), "");
        edgesCosts.push_back(cost);
    }
    visited.push_back(v.name);
    dijkstra (getNext(edgesCosts, visited), visited, &edgesCosts);
    cout << "Min distances table:" << "\n";
    printEdgesCosts(edgesCosts);
}

void dfs(Vertex *v, vector<string>* visited){
    string next = v->name;
    if(!wasVisited(*visited, next)){
        visited->push_back(v->name);
        cout << v->name << " -> ";
        for(int i = 0; i < v->numEdges; i++){
            dfs(get<1>(v->edges[i]), visited);
        }
    }
}
  
int main(){

    bool allowCycles = false;

    Vertex s = Vertex("s");
    Vertex a = Vertex("A");
    Vertex b = Vertex("B");
    Vertex c = Vertex("C");
    Vertex d = Vertex("D");
    Vertex e = Vertex("E");
    Vertex f = Vertex("F");
    Vertex g = Vertex("G");
    Vertex h = Vertex("H");
    Vertex i = Vertex("I");
    Vertex t = Vertex("t");

    s.addEdge(1,&a);
    s.addEdge(4,&d);
    s.addEdge(6,&g);

    a.addEdge(2, &b);
    a.addEdge(2, &e);

    b.addEdge(2, &c);

    c.addEdge(4, &t);

    if(allowCycles) d.addEdge(3, &a);
    d.addEdge(3, &e);

    e.addEdge(2, &c);
    e.addEdge(3, &f);
    e.addEdge(3, &i);

    if(allowCycles)f.addEdge(1, &c);
    f.addEdge(3, &t);

    g.addEdge(2, &d);
    g.addEdge(1, &e);
    g.addEdge(6, &h);

    h.addEdge(2, &e);
    h.addEdge(6, &i);

    i.addEdge(1, &f);
    i.addEdge(4, &t);

    // dijkstra(s);

    vector<string> visited;
    dfs(&s, &visited);
    

    cout << "\n";
    return 0; 
} 