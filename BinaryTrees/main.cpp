//
//  main.cpp
//  BinaryTrees
//
//  Created by Syed Aftab Naqvi on 6/11/17.
//  Copyright © 2017 Syed Aftab Naqvi. All rights reserved.
//

#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    BinaryTree bTree(100);
    bTree.insert(50);
    bTree.insert(60);
    bTree.insert(70);
    bTree.insert(80);
    bTree.insert(90);
    bTree.insert(95);
    bTree.insert(200);
    bTree.insert(40);
    bTree.insert(30);
    
    bTree.display();
    
    cout<<"isBST: "<<bTree.isBST(bTree.getRoot())<<endl;
    cout<<"Min: "<<bTree.findMin()<<endl;
    cout<<"Min: "<<bTree.findMinRecursive(bTree.getRoot())<<endl;
    cout<<"Max: "<<bTree.findMax()<<endl;
    cout<<"Max: "<<bTree.findMaxRecursive(bTree.getRoot())<<endl;
    
    cout<<"Height of Tree: "<<bTree.findHeight(bTree.getRoot())<<endl;
    cout<<"Depth of Tree: "<<bTree.findDepth(bTree.getRoot())<<endl;
    
    bTree.levelOrderTraversal(bTree.getRoot());
    cout<<endl;
    bTree.display();
    cout<<endl;
    bTree.mirror(bTree.getRoot());
    bTree.display();
    cout<<"isBST: "<<bTree.isBST(bTree.getRoot())<<endl;
    bTree.mirror(bTree.getRoot());
    cout<<"isBST: "<<bTree.isBST(bTree.getRoot())<<endl;
    
    Node* node = bTree.search(200);
    if(node != NULL)
        cout<<"Searched: "<<node->mData<<endl;
    
    node = bTree.searchIterative(80);
    if(node != NULL)
        cout<<"Searched: "<<node->mData<<endl;
    
    cout<<"Nodes count in Tree: "<<bTree.count(bTree.getRoot()) << endl;
    return 0;
}
