#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

struct Node
{
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    Node *insertRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    Node *findMax(Node *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    Node *deleteRecursive(Node *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->left = deleteRecursive(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteRecursive(node->right, value);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node *successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteRecursive(node->right, successor->data);
            }
        }

        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void preorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            std::cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void postorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            std::cout << node->data << " ";
        }
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree()
    {
        deleteTree(root);
    }

    void deleteTree(Node *node)
    {
        if (node)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    void remove(int value)
    {
        root = deleteRecursive(root, value);
    }

    void inorder()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorder()
    {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder()
    {
        postorderTraversal(root);
        std::cout << std::endl;
    }

    void printLevelOrder()
    {
        if (root == nullptr)
        {
            return;
        }

        int h = height(root);

        for (int level = 0; level < h; level++)
        {
            printLevel(root, level, 0);
            std::cout << std::endl;
        }

        int leafCount = countNodesAtLevel(root, h - 1);
        for (int i = 0; i < leafCount * 2; i++)
        {
            std::cout << "X ";
        }
        std::cout << std::endl;
    }

    void printLevel(Node *node, int targetLevel, int currentLevel)
    {
        if (node == nullptr)
        {
            if (currentLevel == targetLevel)
            {
                std::cout << "X ";
            }
            return;
        }

        if (currentLevel == targetLevel)
        {
            std::cout << node->data << " ";
            return;
        }

        if (currentLevel < targetLevel)
        {
            printLevel(node->left, targetLevel, currentLevel + 1);
            printLevel(node->right, targetLevel, currentLevel + 1);
        }
    }

    int countNodesAtLevel(Node *node, int level)
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (level == 0)
        {
            return 1;
        }

        return countNodesAtLevel(node->left, level - 1) + countNodesAtLevel(node->right, level - 1);
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    BinarySearchTree bst;
    std::string line;

    if (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        int value;

        while (iss >> value)
        {
            bst.insert(value);
        }
    }

    inputFile.close();

    bst.postorder();
    bst.preorder();
    bst.inorder();
    bst.printLevelOrder();

    return 0;
}