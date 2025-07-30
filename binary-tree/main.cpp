#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node (int item)
    {
        data = item;
        left = right = nullptr;
    }
};

void postOrderTraversal(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);

    cout << node->data << " ";
}

void preOrderTraversal(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data << " ";

    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void inOrderTraversal(Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

void levelOrderTraversal(Node* node)
{
    queue<Node*> q;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        vector<string> level;

        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if (temp)
            {
                level.push_back(to_string(temp->data));
                q.push(temp->left);
                q.push(temp->right);
            }
            else
            {
                level.push_back("X");
            }
        }

        for (const auto &s : level)
        {
            cout << s << " ";
        }

        cout << endl;
    }
}

Node* insert(Node* node, int value)
{
    if (node == nullptr)
    {
        return new Node(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value);
    }

    return node;
}

int getMinValue(Node* node)
{
    Node* current = node;

    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->data;
}

Node* deleteNode(Node* node, int item)
{
    if (node == nullptr)
    {
        return node;
    }

    if (item < node->data)
    {
        node->left = deleteNode(node->left, item);
    }
    else if (item > node->data)
    {
        node->right = deleteNode(node->right, item);
    }
    else
    {
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        int successor = getMinValue(node->right);
        node->data = successor;
        node->right = deleteNode(node->right, successor);
    }

    return node;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    Node* root = nullptr;
    int number;

    while (file >> number)
    {
        root = insert(root, number);
    }

    file.close();

    postOrderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    inOrderTraversal(root);
    cout << endl;
    levelOrderTraversal(root);

    return 0;
}