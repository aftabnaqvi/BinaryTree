//
//  main.cpp
//  BinaryTrees
//
//  Created by Syed Aftab Naqvi on 6/11/17.
//  Copyright © 2017 Syed Aftab Naqvi. All rights reserved.
//

#include <list>
#include <set>
#include <iostream>
#include "BinaryTree.hpp"

using namespace std;

std::list<int> intersect(const std::set<int>& lhs, const std::set<int>& rhs);

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
    
    
    std::set<int> s1{10, 20, 30, 60, 90, 100, 200, 210};
    std::set<int> s2{50, 90, 95, 99, 200};
    std::list<int> common = intersect(s1, s2);
    
    
    return 0;
}

//                          i1
//10, 20, 30, 60, 90, 100, 200, 210

//                      i2
//50, 90, 95, 99, 200

std::list<int> intersect(const std::set<int>& lhs, const std::set<int>& rhs) {
    std::list<int> result;
    auto iter1 = lhs.cbegin();
    auto iter2 = rhs.cbegin();
    // ArrayList<Integer> list1;
    // for (Integer i : list1) {  }
    while (iter1 != lhs.cend() && iter2 != rhs.cend()) {
        if (*iter1 < *iter2) { ++iter1; }
        else if (*iter2 < *iter1) { ++iter2; }
        else { result.push_back(*iter1); ++iter1; ++iter2; }
    }
    return result;
}


/*

 
 insert(#)
 search(#)
 remove(#)
SETUP: insert 1..6
 
 OODLDD
1
2
3
4
5
6
 NEW

 search(1)

*/
