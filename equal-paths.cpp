#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int shortestLeaf(Node* n, int depth);
int longestLeaf(Node* n, int depth);


bool equalPaths(Node * root) {

    // Add your code below

    if(root==NULL) {
        return true;
    }

    int shortest = shortestLeaf(root, 0);
    int longest = longestLeaf(root, 0);

    //cout << "shortest: " << shortest << " longest: " << longest << endl;

    bool same;
    if(shortest == longest) {
        same = true;
    }
    
    else {
        same = false;
    }

    return same;
}

// finds the depth of the closest leaf
int shortestLeaf(Node* n, int depth) {

    if(n == NULL) {
        return -1; // shouldnt happen
    }

    // its a leaf
    if(n->left == NULL && n->right == NULL) {
        return depth;
    }

    // only has right child
    if(n->left == NULL) {
        int r = shortestLeaf(n->right, depth+1);
        return r;
    }

    // only has left child
    if(n->right == NULL) {
        int l = shortestLeaf(n->left, depth+1);
        return l;
    }

    // has both
    int leftDepth = shortestLeaf(n->left, depth + 1);
    int rightDepth = shortestLeaf(n->right, depth + 1);

    if(leftDepth < rightDepth){
        return leftDepth;
    }

    else{
        return rightDepth;
    }
}

// finds the depth of the farthest leaf (basically copy pasted from above)
int longestLeaf(Node* n, int depth) {
    if(n == NULL) {
        return -1; // shouldnt happen
    }
    if(n->left == NULL && n->right == NULL)
    {
        return depth;
    }

    if(n->left == NULL) {
        int r = longestLeaf(n->right, depth+1);
        return r;
    }
    
    if(n->right == NULL) {
        int l = longestLeaf(n->left, depth+1);
        return l;
    }

    int leftDepth = longestLeaf(n->left, depth + 1);
    int rightDepth = longestLeaf(n->right, depth + 1);
    if(leftDepth > rightDepth){
        return leftDepth;
    }
    else{
        return rightDepth;
    }
}