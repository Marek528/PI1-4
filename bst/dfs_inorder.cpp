#include "BinarySearchTree.h"

Node::Node(int value)
{
    this->value = value;
    left = nullptr;
    right = nullptr;
}

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    destroy(root);
}

void BinarySearchTree::destroy(Node *currentNode)
{
    if (currentNode)
    {
        destroy(currentNode->left);
        destroy(currentNode->right);
        delete currentNode;
    }
}

void BinarySearchTree::insert(int value)
{
    Node *newNode = new Node(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node *temp = root;
    while (true)
    {
        if (newNode->value == temp->value)
            return;
        if (newNode->value < temp->value)
        {
            if (temp->left == nullptr)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == nullptr)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

bool BinarySearchTree::contains(int value)
{
    if (root == nullptr)
        return false;
    Node *temp = root;
    while (temp)
    {
        if (value < temp->value)
        {
            temp = temp->left;
        }
        else if (value > temp->value)
        {
            temp = temp->right;
        }
        else
        {
            return true;
        }
    }
    return false;
}

void BinarySearchTree::BFS()
{
    Node *currentNode = root;
    queue<Node *> myQueue;
    myQueue.push(currentNode);

    while (myQueue.size() > 0)
    {
        currentNode = myQueue.front();
        myQueue.pop();
        cout << currentNode->value << " ";
        if (currentNode->left)
        {
            myQueue.push(currentNode->left);
        }
        if (currentNode->right)
        {
            myQueue.push(currentNode->right);
        }
    }
}

void BinarySearchTree::DFSPreOrder(Node *currentNode)
{
    cout << currentNode->value << " ";
    if (currentNode->left != nullptr)
    {
        DFSPreOrder(currentNode->left);
    }
    if (currentNode->right != nullptr)
    {
        DFSPreOrder(currentNode->right);
    }
}

void BinarySearchTree::DFSPreOrder()
{
    DFSPreOrder(root);
}

void BinarySearchTree::DFSPostOrder(Node *currentNode)
{
    if (currentNode->left != nullptr)
    {
        DFSPostOrder(currentNode->left);
    }
    if (currentNode->right != nullptr)
    {
        DFSPostOrder(currentNode->right);
    }
    cout << currentNode->value << " ";
}

void BinarySearchTree::DFSPostOrder()
{
    DFSPostOrder(root);
}

// 8. task (DFS inorder)
void BinarySearchTree::DFSInOrder(Node *currentNode)
{
    if (currentNode->left != nullptr)
    {
        DFSInOrder(currentNode->left);
    }
    
    cout << currentNode->value << " ";

    if (currentNode->right != nullptr)
    {
        DFSInOrder(currentNode->right);
    }
    
}

void BinarySearchTree::DFSInOrder()
{
    DFSInOrder(root);
}
