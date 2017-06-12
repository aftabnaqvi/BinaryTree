//
//  BinaryTree.hpp
//  BinaryTrees
//
//  Created by Syed Aftab Naqvi on 6/11/17.
//  Copyright © 2017 Syed Aftab Naqvi. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <iostream>

struct Node{
    int mData;
    Node* mLeft;
    Node* mRight;
    
    Node(int data):mData(data),
                    mLeft(NULL),
                    mRight(NULL){
                        
                        
        std::cout<<"Node() with data: "<<data<<std::endl;
    }
};

class BinaryTree{

public:
    BinaryTree(int rootData);
    ~BinaryTree();
    
    void insert(int data);
    void deleteTree();
    Node* search(int data);
    Node* searchIterative(int data);
    
    int findMin();
    int findMinRecursive(Node* node);
    int findMax();
    int findMaxRecursive(Node* node);
    
    int findHeight(Node* node); // O(n)
    int findDepth(Node* node);
    
    
    bool isBST(Node* node);
    void levelOrderTraversal(Node* node);
    void mirror(Node* node);
    
    int count(Node* node);
    Node* getRoot();
    void display();
    
private:
    Node* mRoot;
    
    void deleteTree(Node* node);
    void insert(int data, Node* node);
    Node* search(int data, Node* node);
    
    void display(Node* node);
    Node* createNode(int data);
    
    void swapLeftRight(Node* node);
};
#endif /* BinaryTree_hpp */
