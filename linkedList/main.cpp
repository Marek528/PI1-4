#include <iostream>

using namespace std;

class Node
{
    public:
        int value;  // Hodnota uzla
        Node *next; // Ukazovateľ na ďalší uzol

        Node(int val) : value(val), next(nullptr) {}
};

class LinkedList
{
    public:
        Node *head; // Ukazovateľ na prvý uzol v zozname

        LinkedList() : head(nullptr) {}

        // Vloženie na začiatok zoznamu
        void insertAtBeginning(int value)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }

        // Vloženie na koniec zoznamu
        void insertAtEnd(int value)
        {
            Node *newNode = new Node(value);
            if (!head)
            {
                head = newNode;
                return;
            }
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        // Zmazanie prvého uzla
        void deleteFirstNode()
        {
            if (head)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }

        // Vyhľadanie hodnoty v zozname
        bool search(int value)
        {
            Node *temp = head;
            while (temp)
            {
                if (temp->value == value)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        // Výpis zoznamu
        void printList()
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void reverse()
        {
            Node *prev = nullptr;
            Node *temp = head;
            Node *next = nullptr;

            while (temp)
            {
                next = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next;
            }
            head = prev;
        }

        bool hasCycle() // prepisat tie if podmienky
        {
            Node *temp1 = head;
            Node *temp2 = head->next->next;

            while (temp1 != temp2)
            {
                temp1 = temp1->next;
                if (temp1 == nullptr)
                {
                    return false;
                }

                temp2 = temp2->next->next;
                if (temp2 == nullptr)
                {
                    return false;
                }
            }

            return true;
        }
};

int main()
{
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.printList(); // Výstup: 20 10 30

    list.deleteFirstNode();
    list.printList(); // Výstup: 10 30

    cout << "Hodnota 10 v zozname: " << (list.search(10) ? "Nájdená" : "Nenájdená") << endl;
    cout << "Hodnota 50 v zozname: " << (list.search(50) ? "Nájdená" : "Nenájdená") << endl;

    list.reverse();
    list.printList(); // Výstup: 30 10

    return 0;
}