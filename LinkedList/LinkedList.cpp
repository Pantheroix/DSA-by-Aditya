#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    ~LinkedList() // Destructor to prevent memory leaks
    {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display()
    {
        for (Node *temp = head; temp != nullptr; temp = temp->next)
        {
            std::cout << temp->data << " -> ";
        }
        std::cout << "nullptr" << std::endl;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void deleteNode(int val)
    {
        // If the list is empty, do nothing
        if (head == nullptr) return;

        // Case 1: The node to delete is the head
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 2: The node is in the middle or at the end
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }

        // If the value was not found in the list
        if (current == nullptr) return;

        // Unlink the node and delete it
        prev->next = current->next;
        delete current;
    }
};

int main()
{
    LinkedList list;
    std::cout << "--- Initial List ---" << std::endl;
    list.insertAtHead(50);
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.display();

    std::cout << "\n--- Testing Delete ---" << std::endl;
    std::cout << "Deleting 99 (not in list): ";
    list.deleteNode(99);
    list.display();

    std::cout << "Deleting 10 (head): ";
    list.deleteNode(10);
    list.display();

    std::cout << "Deleting 30 (middle): ";
    list.deleteNode(30);
    list.display();

    std::cout << "Deleting 50 (tail): ";
    list.deleteNode(50);
    list.display();

    std::cout << "\nFinal list should be: 20 -> 40 -> nullptr" << std::endl;

    return 0;
}
