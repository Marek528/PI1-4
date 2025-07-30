#include <iostream>
#include <vector>

using namespace std;

// 1. task
class Node
{
    public:
        string key;
        int value;
        Node *next;

        Node(string key, int value)
        {
            this->key = key;
            this->value = value;
            next = nullptr;
        }      
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(string key)
        {
            int hash = 0;
            for (int i = 0; i < key.length(); i++)
            {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            
            return hash;
        }

    public:
        HashTable() {
            for(int i = 0; i < SIZE; i++) {
                dataMap[i] = nullptr;
            }
        }
        
        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
        
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                cout << "Index " << i << ": ";
                if(dataMap[i]) {
                    cout << "Contains => ";
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "{" << temp->key << ", " << temp->value << "}";
                        temp = temp->next;
                        if (temp) cout << ", ";
                    }
                    cout << endl;
                } else {
                    cout << "Empty" << endl;
                }
            }
        }

        // 2. task
        void set(string key, int value)
        {
            int index = hash(key);
            Node* newNode = new Node(key, value);

            if (dataMap[index] == nullptr)
            {
                dataMap[index] = newNode;
            }
            else
            {
                Node* temp = dataMap[index];
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        
        // 3. task
        int get(string key)
        {
            int index = hash(key);
            Node* temp = dataMap[index];

            while (temp != nullptr)
            {
                if (temp->key == key)
                {
                    return temp->value;
                }
                temp = temp->next;
            }

            return 0;
        }

        // 4. task
        vector<string> keys()
        {
            vector<string> allKeys;
            allKeys.reserve(SIZE);
            
            for (int i = 0; i < SIZE; i++)
            {
                if (dataMap[i] != nullptr)
                {
                    Node* temp = dataMap[i];
                    while (temp != nullptr)
                    {
                        allKeys.push_back(temp->key);
                        temp = temp->next;
                    }
                }
            }
            
            return allKeys;
        }
};

int main()
{
    HashTable* hashTable = new HashTable();

    hashTable->set("apple", 10);
    hashTable->set("banana", 20);
    hashTable->set("orange", 30);
    hashTable->set("grape", 40);

    cout << "Value for 'apple': " << hashTable->get("apple") << endl;
    cout << "Value for 'banana': " << hashTable->get("banana") << endl;
    cout << "Value for 'orange': " << hashTable->get("orange") << endl;
    cout << "Value for 'grape': " << hashTable->get("grape") << endl;
    cout << "Value for 'watermelon' (not in table): " << hashTable->get("watermelon") << endl;

    vector<string> allKeys = hashTable->keys();
    for (size_t i = 0; i < allKeys.size(); i++)
    {
        cout << allKeys[i] << " ";
    }
    
    cout << endl;
    hashTable->printTable();

    return 0;
}