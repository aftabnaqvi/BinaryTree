//
//  BinaryTree.cpp
//  BinaryTrees
//
//  Created by Syed Aftab Naqvi on 6/11/17.
//  Copyright © 2017 Syed Aftab Naqvi. All rights reserved.
//

#include "BinaryTree.hpp"
#include <queue>

using namespace std;

BinaryTree::BinaryTree(int rootData){
    mRoot = createNode(rootData);
}

BinaryTree::~BinaryTree(){
    deleteTree();
}

void BinaryTree::insert(int data){
    insert(data, mRoot);
}

void BinaryTree::deleteTree(){
    deleteTree(mRoot);
}

Node* BinaryTree::search(int data){
    return search(data, mRoot);
}


void BinaryTree::deleteTree(Node* node){
    if(node != NULL){
        deleteTree(node->mLeft);
        deleteTree(node->mRight);
        //cout<<"deleting node with data: " << node->mData << endl;
        delete node;
    }
}

void BinaryTree::insert(int data, Node* node){
    if(data < node->mData){
        // go on left side of the tree
        if(node->mLeft == NULL){
            // our left node is NULL - create a new node and set in its left node.
            node->mLeft = createNode(data);
        } else {
            // our left node is not NULL - keep going further down.
            insert(data, node->mLeft);
        }
    } else if (data > node->mData) {
        // keep going on the right side of the tree
        if(node->mRight == NULL){
            // our right node is NULL - create a new node and set in its right node.
            node->mRight = createNode(data);
        } else {
            // our left node is not NULL - keep going further down.
            insert(data, node->mRight);
        }
    }
}

Node* BinaryTree::search(int data, Node* node){
    if(node == NULL)
        return NULL;
    
    if(data == node->mData)
        return node;
    
    if(data < node->mData)
        return search(data, node->mLeft);
    else
        return search(data, node->mRight);
}

Node* BinaryTree::searchIterative(int data){
    queue<Node*> queue;
    queue.push(mRoot);
    
    while(!queue.empty()){
        Node *node = queue.front();
        if(node->mData == data)
            return node;
        
        queue.pop();
        
        if(node->mLeft != NULL)
            queue.push(node->mLeft);
        
        if(node->mRight != NULL)
            queue.push(node->mRight);
    }
    
    return NULL;
}

/*
 int findMin();
 int findMinRecursive();
 int findMax();
 int findMaxRecursive();
 */
int BinaryTree::findMin(){
    if(mRoot == NULL){
        cout<<"Error: Tree is empty" <<endl;
        return -1;
    }
    
    Node* node = mRoot;
    while(node->mLeft != NULL){
        node = node->mLeft;
    }
    
    return node->mData;
}

// findHeight
int BinaryTree::findHeight(Node* node){
    
    if(node == NULL)
        return -1;
    
    int leftHeight = findHeight(node->mLeft);
    int rightHeight = findHeight(node->mRight);
    
    return max(leftHeight, rightHeight)+1;
}

// Depth
int BinaryTree::findDepth(Node* node){
    if(node == NULL)
            return -1;
    
    int leftDepth = findDepth(node->mLeft);
    int rightDepth = findDepth(node->mRight);
    
    return max(leftDepth, rightDepth)+1;
}


int BinaryTree::findMinRecursive(Node* node){
    if(node == NULL){
        cout<<"Error: Tree is empty" <<endl;
        return -1;
    } else if(node->mLeft == NULL) {
        return node->mData;
    }
        
    return findMinRecursive(node->mLeft);
}

int BinaryTree::findMax(){
    if(mRoot == NULL){
        cout<<"Error: Tree is empty" <<endl;
        return -1;
    }
    
    Node* node = mRoot;
    while(node->mRight != NULL){
        node = node->mRight;
    }
    
    return node->mData;
}

int BinaryTree::findMaxRecursive(Node* node){
    if(node == NULL){
        cout<< "Error: Tree is empty." <<endl;
        return -1;
    } else if (node->mRight == NULL){
        return node->mData;
    }
    
    return findMaxRecursive(node->mRight);
    
}

bool BinaryTree::isBST(Node* node){
    if(node == NULL)
        return true;
    
    if(node->mLeft != NULL && node->mData < node->mLeft->mData)
        return false;
    
    if(node->mRight != NULL && node->mData > node->mRight->mData)
        return false;
    
    if (!isBST(node->mLeft) || !isBST(node->mRight))
        return false;
    
    return true;
}

void BinaryTree::levelOrderTraversal(Node* node){
    if(node == NULL)
        return;
    
    queue<Node*> que;
    que.push(node); // discover node
    while(!que.empty()){
        Node* currNode = que.front();
        
        cout<<currNode->mData<<" ";
        if(currNode->mLeft != NULL)
            que.push(currNode->mLeft);
        
        if(currNode->mRight != NULL)
            que.push(currNode->mRight);
        
        que.pop();
    }
}

void BinaryTree::mirror(Node* node){
    if(node == NULL)
        return;
    
    mirror(node->mLeft);
    mirror(node->mRight);
    swapLeftRight(node);
}

int BinaryTree::count(Node* node){
    if(node == NULL)
        return 0;
    
    return count(node->mLeft) + count(node->mRight) + 1;
    
//    int cnt =  1;
//    if(node->mLeft != NULL)
//        cnt += count(node->mLeft);
//    
//    if(node->mRight != NULL)
//        cnt += count(node->mRight);
//    
//    return cnt;
    
//    int cnt =  1;
//    if(node == NULL)
//        return 0;
//    
//    cnt += count(node->mLeft);
//    cnt += count(node->mRight);
//    
//    return cnt;
}

void BinaryTree::swapLeftRight(Node* node){
    if(node != NULL){
        Node* temp = node->mLeft;
        node->mLeft = node->mRight;
        node->mRight = temp;
    }
}

Node* BinaryTree::getRoot(){
    return mRoot;
}

// Create Node:
Node* BinaryTree::createNode(int data){
    
    return new Node(data);
}

void BinaryTree::display(){
    display(mRoot);
    cout<<endl;
}

void BinaryTree::display(Node* node){
    if(node != NULL){
        cout<<node->mData<<" ";
        display(node->mLeft);
        display(node->mRight);
    }
}
