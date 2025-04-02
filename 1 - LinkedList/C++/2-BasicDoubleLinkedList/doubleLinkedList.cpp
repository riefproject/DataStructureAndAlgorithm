#include <iostream>
#include <string>

using namespace std;

// Node class representing each element in the doubly linked list
class Node {
public:
    string name;     // Data title
    string username; // Author of the data
    string email;    // Author of the data
    string password; // Publication year of the data
    Node* prev;      // Pointer to the previous data in the list
    Node* next;      // Pointer to the next data in the list

    // Constructor to initialize a new node
    Node(const string& name, const string& username, const string& email, const string& password)
        : name(name), username(username), email(email), password(password), prev(nullptr), next(nullptr) {}
};

// LinkedList class to manage the doubly linked list
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
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to create a double linked list with the first node
    void createDoubleLinkedList(const string& name, const string& username, const string& email, const string& password) {
        Node* newNode = new Node(name, username, email, password);
        head = newNode;
        tail = newNode;
        size = 1;
    }

    // Function to add a node at the beginning of the list
    void addAtFirstNode(const string& name, const string& username, const string& email, const string& password) {
        if (size == 0) {
            createDoubleLinkedList(name, username, email, password);
            return;
        }
        Node* newNode = new Node(name, username, email, password);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        size++;
    }

    // Function to add a node at the nth position in the list
    void addAtNthNode(const string& name, const string& username, const string& email, const string& password, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtFirstNode(name, username, email, password);
            return;
        }
        if (pos == size + 1) {
            addAtLastNode(name, username, email, password);
            return;
        }
        Node* newNode = new Node(name, username, email, password);
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
    void addAtLastNode(const string& name, const string& username, const string& email, const string& password) {
        if (size == 0) {
            createDoubleLinkedList(name, username, email, password);
            return;
        }
        Node* newNode = new Node(name, username, email, password);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    // Function to update the first node in the list
    void updateFirstNode(const string& name, const string& username, const string& email, const string& password) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        head->name = name;
        head->username = username;
        head->email = email;
        head->password = password;
    }

    // Function to update the nth node in the list
    void updateNthNode(const string& name, const string& username, const string& email, const string& password, int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->name = name;
        cur->username = username;
        cur->email = email;
        cur->password = password;
    }

    // Function to update the last node in the list
    void updateLastNode(const string& name, const string& username, const string& email, const string& password) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        tail->name = name;
        tail->username = username;
        tail->email = email;
        tail->password = password;
    }

    // Function to remove the first node from the list
    void removeAtFirst() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* del = head;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete del;
        size--;
    }

    // Function to remove the nth node from the list
    void removeAtNthNode(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            removeAtFirst();
            return;
        }
        if (pos == size) {
            removeAtLast();
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        Node* del = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete del;
        size--;
    }

    // Function to remove the last node from the list
    void removeAtLast() {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* del = tail;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete del;
        size--;
    }

    // Function to print the double linked list
    void printDoubleLinkedList() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Number of Nodes: " << size << endl; // Display the total number of nodes

        Node* cur = head;
        int i = 1;
        while (cur != nullptr) {
            cout << "Node " << i << endl;
            cout << "name\t\t: " << cur->name << endl;
            cout << "username\t: " << cur->username << endl;
            cout << "email\t\t: " << cur->email << endl;
            cout << "password\t: " << cur->password << endl << endl;
            cur = cur->next;
            i++;
        }
    }
};

int main() {
    LinkedList list;

    list.createDoubleLinkedList("Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.addAtLastNode("Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.addAtFirstNode("Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.removeAtFirst();
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.removeAtLast();
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.addAtFirstNode("dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
    list.addAtFirstNode("dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
    list.addAtFirstNode("dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
    list.addAtFirstNode("dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
    list.addAtFirstNode("dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.addAtNthNode("Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    list.removeAtNthNode(6);
    list.printDoubleLinkedList();
    cout << "==========\n\n\n";

    return 0;
}