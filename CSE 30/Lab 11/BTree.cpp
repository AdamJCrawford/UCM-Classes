#include <iostream>

#include "BTree.h"

using namespace std;

BTree::BTree()
{
    root = nullptr;
}


BTree::~BTree()
{
    destroy_tree(root);
}


void BTree::destroy_tree(Node *leaf)
{
    if (leaf != nullptr)
    {
        destroy_tree(leaf->right);
        destroy_tree(leaf->left);
        delete leaf;
    }
}


void BTree::insert(int key, Node *leaf)
{
    if (key < leaf->key_value)
    {
        if (leaf->left == nullptr)
        {
            leaf->left            = new Node;
            leaf->left->key_value = key;
            leaf->left->right     = nullptr;
            leaf->left->left      = nullptr;
        }
        else
        {
            insert(key, leaf->left);
        }
    }
    else
    {
        if (leaf->right == nullptr)
        {
            leaf->right            = new Node;
            leaf->right->key_value = key;
            leaf->right->right     = nullptr;
            leaf->right->left      = nullptr;
        }
        else
        {
            insert(key, leaf->right);
        }
    }
}


Node *BTree::search(int key, Node *leaf)
{
    if (leaf == nullptr)
    {
        return nullptr;
    }
    if (leaf->key_value == key)
    {
        return leaf;
    }
    else if (leaf->key_value > key)
    {
        search(key, leaf->left);
    }
    else
    {
        search(key, leaf->right);
    }
}


Node *BTree::BTree_root()
{
    return root;
}


void BTree::insert(int key)
{
    if (root == nullptr)
    {
        root            = new Node;
        root->key_value = key;
        root->right     = nullptr;
        root->left      = nullptr;
    }
    else
    {
        insert(key, root);
    }
}


Node *BTree::search(int key)
{
    return search(key, root);
}


void BTree::destroy_tree()
{
    destroy_tree(root);
}
