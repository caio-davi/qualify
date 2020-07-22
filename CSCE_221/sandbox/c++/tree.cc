#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include<tuple>
#include <algorithm>

using namespace std;


class Node{

public:
    string name;
    int value;
    bool hasLeft = false;
    bool hasRight = false;
    Node* left;
    Node* right;
    
    Node();
    Node(string name);
    bool addNode(Node* n);
    void print();

};

Node::Node(){};

Node::Node(string nName){ 
    name = nName;
};

bool Node::addNode(Node* n){
    if(!hasLeft){
        left = n;
        hasLeft = true;
        return true;
    }else if(!hasRight){
        right = n;
        hasRight = true;
        return true;
    }else{
        return false;
    }
}

class Tree{

public:
    Node* root;
    
    Tree(Node* r);
    void addNode(Node* n);
    void order(int order);
    void preOrder(Node* n);
    void inOrder(Node* n);
    void postOrder(Node* n);
};

Tree::Tree(Node* n){
    root = n;
}

void Tree::addNode(Node* n){
    Node* current = root;
    if(!current->addNode(n)){
        bool added = false;
        Node* next;
        while(!added){
            next = current->left;
            if(next->addNode(n)){
                added = true;
                break;
            }
            next = current->right;
            if(next->addNode(n)){
                added = true;
                break;
            }
        }
    }
}


void Tree::preOrder(Node* n){
    cout << n->name << " - ";
    if (n->hasLeft) preOrder(n->left); 
    if (n->hasRight) preOrder(n->right); 
}

void Tree::inOrder(Node* n){
    if (n->hasLeft) inOrder(n->left); 
    cout << n->name << " - ";
    if (n->hasRight) inOrder(n->right); 
}

void Tree::postOrder(Node* n){
    if (n->hasLeft) postOrder(n->left); 
    if (n->hasRight) postOrder(n->right); 
    cout << n->name << " - ";
}

void Tree::order(int order){
    switch(order){
        case(1):
            cout << " Pre Order: ";
            preOrder(root);
            break;
        case(2):
            cout << " In Order: ";
            inOrder(root);
            break;
        case(3):
            cout << " Post Order: ";
            postOrder(root);
            break;
        default:
            cout << "Order not selected" << "\n";
    }
    cout << "\n\n";
}

int main(){

    Node n = Node("N");
    Node o = Node("O");
    Node p = Node("P");
    Node q = Node("Q");
    Node r = Node("R");
    Node s = Node("S");
    
    Tree t = Tree(&n);

    t.addNode(&o);
    t.addNode(&p);
    t.addNode(&q);
    t.addNode(&r);
    // t.addNode(&s);

    t.order(1);
    t.order(2);
    t.order(3);
    cout << "\n\n";
    return 1;
}