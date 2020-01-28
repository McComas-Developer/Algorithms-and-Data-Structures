// Author: Michael McComas
// Project #6
// File: worldtree.cpp
// CSCI 3110-001
// Due: 4/1/19
// Remarks: Implemetation file for WordTree class.

#include <iostream>
#include <string>
#include "wordtree.h"

using namespace std;

// Create an empty Binary Search Tree
WordTree::WordTree(){
    root = new TreeNode;
    root->left = nullptr;
    root->right = nullptr;
    root->value = "";
    root->count = 0;
}

// Deallocate memory from the Binary Search Tree
WordTree::~WordTree(){
    deleteSubTree(root);
}

// Remove a subtree from the Binary Search Tree
void WordTree::deleteSubTree(TreeNode *node){
    if(node == nullptr)
        return;
    deleteSubTree(node->left);
    deleteSubTree(node->right);
    delete node;
    node = nullptr;
}

// Search the Binary Tree for a word and output its count
void WordTree::findWord(string word){
    TreeNode *n = new TreeNode;
    n = root;
    bool found;
    while(n != nullptr && !found){
        if(n->value > word)
            n = n->left;
        else if(n->value < word)
            n = n->right;
        else if(n->value == word)
            found = true;
    }
    if(found == true){
        cout << "The word '" << word << "' occurs " << n->count << " time(s) in the text." << endl;
        cout << "\n";
    }
    else if(found == false){
        cout << "The word '" << word << "' was not found in the text." << endl;
        cout << "\n";
    }
    delete n;
    n = nullptr;
}
// Get the amount of times a specific word appears (helper)
void WordTree::getCounts(int count){
    int cnt = 0;
    cout << "Finding all words with " << count << " or more occurances:" << endl;
    getCounts(root, count, cnt);
    cout << cnt << " nodes had words with " << count << " or more occurance(s)" << endl;
    cout << "\n";
}
// Finds the amount of times a word appears in the tree
void WordTree::getCounts(TreeNode *r, int cnt, int& count) const{
    if(r == nullptr)
        return;
    getCounts(r->left, cnt, count);
    if(r->count >= cnt){
        count++;
        cout << r->value << "(" << r->count << ")" << endl;
    }
    getCounts(r->right, cnt, count);
}

// Add words to Binary Search Tree (helper)
void WordTree::addWord(string word){
    addWord(root, word);
}

// Adds node to tree if node already present. If present, increment its count
void WordTree::addWord(TreeNode *&node, string word){
    if(root == nullptr){
        root->value = word;
        root->count = 1;
    }
    else if(node == nullptr){
        TreeNode *n;
        n = new TreeNode;
        n->count = 1;
        n->left = nullptr;
        n->right = nullptr;
        n->value = word;
        node = n;
    }
    else if(node->value == word)
        node->count++;
    else if(node->value > word)
        addWord(node->left, word);
    else if(node->value < word)
        addWord(node->right, word);
}

// string split function
void WordTree::split(const string& s, char c, vector<string>& v) {

   string::size_type i = 0;
   string::size_type j = s.find(c);

   while(j != string::npos){
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}