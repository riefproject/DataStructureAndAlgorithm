#include <iostream>
#include <string>

using namespace std;

// Node class representing each element in the circular doubly linked list
class Node {
public:
    string name;  // Item name
    int price;    // Item price
    int available; // Item availability
    Node* prev;   // Pointer to the previous node in the list
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize a new node
    Node(const string& name, int price, int available)
        : name(name), price(price), available(available), prev(nullptr), next(nullptr) {}
};

// LinkedList class to manage the circular doubly linked list
class LinkedList {
private:
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    int size;   // Size of the list

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor to clean up the list
    ~LinkedList() {
        while (size > 0) {
            removeFirstNode();
        }
    }

    // Function to create a circular doubly linked list with the first node
    void createCircularDL(const string& name, int price, int available) {
        Node* newNode = new Node(name, price, available);
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;
        size = 1;
    }

    // Function to add a node at the beginning of the list
    void addAtFirstNode(const string& name, int price, int available) {
        if (size == 0) {
            createCircularDL(name, price, available);
            return;
        }
        Node* newNode = new Node(name, price, available);
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        size++;
    }

    // Function to add a node at the nth position in the list
    void addAtNthNode(const string& name, int price, int available, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtFirstNode(name, price, available);
            return;
        }
        if (pos == size + 1) {
            addAtLastNode(name, price, available);
            return;
        }
        Node* newNode = new Node(name, price, available);
        Node* cur = head;
        for (int i = 1; i < pos - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
        size++;
    }

    // Function to add a node at the end of the list
    void addAtLastNode(const string& name, int price, int available) {
        if (size == 0) {
            createCircularDL(name, price, available);
            return;
        }
        Node* newNode = new Node(name, price, available);
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
        size++;
    }

    // Function to update the first node in the list
    void updateFirstNode(const string& name, int price, int available) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        head->name = name;
        head->price = price;
        head->available = available;
    }

    // Function to update the nth node in the list
    void updateNthNode(const string& name, int price, int available, int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->name = name;
        cur->price = price;
        cur->available = available;
    }

    // Function to update the last node in the list
    void updateLastNode(const string& name, int price, int available) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        tail->name = name;
        tail->price = price;
        tail->available = available;
    }

    // Function to remove the first node from the list
    void removeFirstNode() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
        size--;
    }

    // Function to remove the nth node from the list
    void removeNthNode(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            removeFirstNode();
            return;
        }
        if (pos == size) {
            removeLastNode();
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        size--;
    }

    // Function to remove the last node from the list
    void removeLastNode() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        size--;
    }

    // Function to print the circular doubly linked list
    void printCircularDL() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* cur = head;
        do {
            cout << "Name: " << cur->name << ", Price: " << cur->price << ", Available: " << cur->available << endl;
            cur = cur->next;
        } while (cur != head);
    }

    // Function to count the number of nodes in the list
    int countNodes() const {
        return size;
    }
};

int main() {
    LinkedList list;

    // Create the circular doubly linked list with the first node
    list.createCircularDL("Laptop", 20000000, 20);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Add a node at the beginning of the list
    list.addAtFirstNode("Handphone", 5000000, 50);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Add nodes at the end of the list
    list.addAtLastNode("Mouse", 1200000, 100);
    list.addAtLastNode("Keyboard", 2250000, 100);
    list.addAtLastNode("Headphone", 1800000, 100);
    list.addAtLastNode("Monitor", 4200000, 100);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Remove the first node from the list
    list.removeFirstNode();
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Remove the last node from the list
    list.removeLastNode();
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Add a node at the nth position in the list
    list.addAtNthNode("RTX 5090", 40000000, 15, 3);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Remove the nth node from the list
    list.removeNthNode(4);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Update the first node in the list
    list.updateFirstNode("Laptop", 19000000, 10);
    // Update the nth node in the list
    list.updateNthNode("Mouse", 1000000, 3, 2);
    // Update the last node in the list
    list.updateLastNode("Headphone", 1900000, 5);
    list.printCircularDL();
    cout << "==========\n\n\n";

    // Print the total number of nodes in the list
    cout << "Total nodes: " << list.countNodes() << endl;

    return 0;
}