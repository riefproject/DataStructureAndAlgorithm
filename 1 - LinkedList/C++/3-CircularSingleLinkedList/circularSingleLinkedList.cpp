#include <iostream>
#include <string>

using namespace std;

// Node class representing each element in the circular singly linked list
class Node {
public:
    string id;    // ID of the student
    string name;  // Name of the student
    string major; // Major of the student
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize a new node
    Node(const string& id, const string& name, const string& major)
        : id(id), name(name), major(major), next(nullptr) {}
};

// LinkedList class to manage the circular singly linked list
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

    // Function to create a circular singly linked list with the first node
    void createCircularSL(const string& id, const string& name, const string& major) {
        Node* newNode = new Node(id, name, major);
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        size = 1;
    }

    // Function to add a node at the beginning of the list
    void addAtFirstNode(const string& id, const string& name, const string& major) {
        if (size == 0) {
            createCircularSL(id, name, major);
            return;
        }
        Node* newNode = new Node(id, name, major);
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        size++;
    }

    // Function to add a node at the nth position in the list
    void addAtNthNode(const string& id, const string& name, const string& major, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            addAtFirstNode(id, name, major);
            return;
        }
        if (pos == size + 1) {
            addAtLastNode(id, name, major);
            return;
        }
        Node* newNode = new Node(id, name, major);
        Node* cur = head;
        for (int i = 1; i < pos - 1; i++) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    // Function to add a node at the end of the list
    void addAtLastNode(const string& id, const string& name, const string& major) {
        if (size == 0) {
            createCircularSL(id, name, major);
            return;
        }
        Node* newNode = new Node(id, name, major);
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    // Function to update the first node in the list
    void updateFirstNode(const string& id, const string& name, const string& major) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        head->id = id;
        head->name = name;
        head->major = major;
    }

    // Function to update the nth node in the list
    void updateNthNode(const string& id, const string& name, const string& major, int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->id = id;
        cur->name = name;
        cur->major = major;
    }

    // Function to update the last node in the list
    void updateLastNode(const string& id, const string& name, const string& major) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        tail->id = id;
        tail->name = name;
        tail->major = major;
    }

    // Function to remove the first node from the list
    void removeFirstNode() {
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
            tail->next = head;
        }
        delete del;
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
        Node* cur = head;
        for (int i = 1; i < pos - 1; i++) {
            cur = cur->next;
        }
        Node* del = cur->next;
        cur->next = del->next;
        if (del == tail) {
            tail = cur;
        }
        delete del;
        size--;
    }

    // Function to remove the last node from the list
    void removeLastNode() {
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
            Node* cur = head;
            while (cur->next != tail) {
                cur = cur->next;
            }
            tail = cur;
            tail->next = head;
        }
        delete del;
        size--;
    }

    // Function to print the circular singly linked list
    void printCircularSL() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "Number of Nodes: " << size << endl; // Display the total number of nodes

        Node* cur = head;
        int i = 1;
        do {
            cout << "Node " << i << endl;
            cout << "ID\t\t: " << cur->id << endl;
            cout << "Name\t\t: " << cur->name << endl;
            cout << "Major\t\t: " << cur->major << endl << endl;
            cur = cur->next;
            i++;
        } while (cur != head);
    }
};

int main() {
    LinkedList list;

    // Create the circular singly linked list with the first node
    list.createCircularSL("11223399", "Arief F-sa", "Computer Science");
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Add a node at the beginning of the list
    list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Add a node at the end of the list
    list.addAtLastNode("11223400", "Pejeel", "Drop out");
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Remove the first node from the list
    list.removeFirstNode();
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Remove the last node from the list
    list.removeLastNode();
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Add nodes at the beginning and end of the list
    list.addAtFirstNode("11223398", "Nisa Uswa", "Psychology");
    list.addAtLastNode("11223400", "Pejeel", "Drop out");
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Add nodes at specific positions in the list
    list.addAtNthNode("11223401", "dummy1", "Math", 3);
    list.addAtNthNode("11223402", "dummy2", "Physics", 2);
    list.printCircularSL();
    cout << "==========\n\n\n";

    // Remove the node at the specified position in the list
    list.removeNthNode(2);
    list.printCircularSL();
    cout << "==========\n\n\n";

    return 0;
}