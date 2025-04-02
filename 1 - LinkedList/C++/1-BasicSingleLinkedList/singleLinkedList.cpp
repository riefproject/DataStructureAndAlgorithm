#include <iostream>
#include <string>

using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    string title;  // Book title
    string author; // Author of the book
    string year;   // Publication year of the book
    Node* next;    // Pointer to the next book in the list

    // Constructor to initialize a new node
    Node(const string& title, const string& author, const string& year)
        : title(title), author(author), year(year), next(nullptr) {}
};

// LinkedList class to manage the linked list
class LinkedList {
private:
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    int size;   // Size of the list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor to clean up the linked list
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to add a node at the end of the linked list
    void addNode(const string& title, const string& author, const string& year) {
        Node* newBook = new Node(title, author, year);
        if (head == nullptr) {
            head = tail = newBook;
        }
        else {
            tail->next = newBook;
            tail = newBook;
        }
        size++;
    }

    // Function to add a node at the beginning of the linked list
    void addAtFirstNode(const string& title, const string& author, const string& year) {
        Node* newBook = new Node(title, author, year);
        newBook->next = head;
        head = newBook;
        if (size == 0) {
            tail = newBook;
        }
        size++;
    }

    // Function to add a node at a specified position in the linked list
    void addAtNthNode(const string& title, const string& author, const string& year, int pos) {
        if (pos < 1 || pos > size + 1) {
            cout << "Position out of range" << endl;
            return;
        }
        if (pos == 1) {
            addAtFirstNode(title, author, year);
            return;
        }
        if (pos == size + 1) {
            addNode(title, author, year);
            return;
        }

        Node* newBook = new Node(title, author, year);
        Node* cur = head;
        for (int i = 1; i < pos - 1; i++) {
            cur = cur->next;
        }
        newBook->next = cur->next;
        cur->next = newBook;
        size++;
    }

    // Function to update the details of the first node in the linked list
    void updateFirstNode(const string& title, const string& author, const string& year) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        head->title = title;
        head->author = author;
        head->year = year;
    }

    // Function to update the details of the nth node in the linked list
    void updateNthNode(const string& title, const string& author, const string& year, int pos) {
        if (pos < 1 || pos > size) {
            cout << "Position out of range" << endl;
            return;
        }
        Node* cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->title = title;
        cur->author = author;
        cur->year = year;
    }

    // Function to update the details of the last node in the linked list
    void updateLastNode(const string& title, const string& author, const string& year) {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        tail->title = title;
        tail->author = author;
        tail->year = year;
    }

    // Function to remove the first node from the linked list
    void removeAtFirst() {
        if (size == 0) return;
        Node* del = head;
        head = head->next;
        delete del;
        if (size == 1) {
            tail = nullptr;
        }
        size--;
    }

    // Function to remove the nth node from the linked list
    void removeAtNthNode(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Position out of range" << endl;
            return;
        }
        if (pos == 1) {
            removeAtFirst();
            return;
        }
        Node* cur = head;
        Node* before = nullptr;
        for (int i = 1; i < pos; ++i) {
            before = cur;
            cur = cur->next;
        }
        before->next = cur->next;
        if (cur == tail) {
            tail = before;
        }
        delete cur;
        size--;
    }

    // Function to remove the last node from the linked list
    void removeAtLast() {
        if (size == 0) return;
        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }
        Node* cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
        size--;
    }

    // Function to print all nodes in the linked list
    void printSingleLinkedList() const {
        cout << "Number of Nodes: " << size << endl;
        Node* cur = head;
        int i = 1;
        while (cur != nullptr) {
            cout << "NODE " << i << endl;
            cout << "Title\t: " << cur->title << endl;
            cout << "Author\t: " << cur->author << endl;
            cout << "Year\t: " << cur->year << endl << endl;
            cur = cur->next;
            i++;
        }
    }

    // Utility function to count the number of nodes in the linked list
    int countNodes() const {
        return size;
    }
};

int main() {
    LinkedList list;

    // Adding and printing nodes to demonstrate linked list operations
    list.addNode("Introduction to C", "Arief", "2022");
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    list.addAtFirstNode("Chemistry", "Wijaya", "2019");
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    list.addNode("Physics", "Nisa", "2024");
    list.addNode("Introduction to Python", "Arief", "2023");
    list.addAtNthNode("F1 For Child", "Anomali", "2000", 2);
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    // Removing nodes and updating information to show dynamic modifications
    list.removeAtFirst();
    list.printSingleLinkedList();
    list.updateFirstNode("Introduction to C++", "Arief", "2022");
    cout << "=========" << endl << endl;

    list.removeAtLast();
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    list.removeAtNthNode(2);
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    list.addNode("Introduction to Kotlin", "Arief", "2023");
    list.updateNthNode("Math", "Nisa", "2024", 2);
    list.printSingleLinkedList();
    cout << "=========" << endl << endl;

    return 0;
}