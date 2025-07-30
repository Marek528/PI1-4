#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    Node *getRoot()
    {
        return root;
    }

    Node *rInsert(Node *currentNode, int value)
    {
        if (currentNode == nullptr)
            return new Node(value);

        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }
    void rInsert(int value)
    {
        if (root == nullptr)
            root = new Node(value);
        rInsert(root, value);
    }

    // 3. task (min value)
    int minValue(Node *currentNode)
    {
        while (currentNode->left != nullptr)
        {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }
};