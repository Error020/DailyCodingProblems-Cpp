/*
This problem was asked by Google.

An unival tree(which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees :

     0 
    / \
   1   0
      / \
     1   0
    / \
   1   1

*/

#include <iostream>

class Node {
public:
    class Node* left;
    class Node* right;
    int value = 0;

    Node(int val) 
    {
        value = val;
        left = NULL;
        right = NULL;
    }

};

int res = 0;

void getunitree(Node* root) {

    if (root->left == nullptr && root->right == nullptr) {
        res++;
    }
    else if (root->left == nullptr && root->right != nullptr) {
        getunitree(root->right);
    }
    else if (root->left != nullptr && root->right == nullptr) {
        getunitree(root->right);
    }
    else if (root->left->value == root->value && root->right->value == root->value) {
        res++;
        getunitree(root->left);
        getunitree(root->right);
    }
    else {
        getunitree(root->left);
        getunitree(root->right);
    }

}


int main() {

    class Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->right = new Node(0);
    root->right->left = new Node(1);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(1);

    getunitree(root);

    std::cout << res;


    return 0;
}

// there's probably a better solution but like a wise man once said: "it just works!"
