#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define macros to simplify memory allocation and deallocation
#define new(var) (var *)malloc(sizeof(var)) // Allocates memory for a new variable of type 'var'
#define delete(var) \
    free(var);      \
    var = NULL; // Frees allocated memory and sets the pointer to NULL to prevent dangling references

// Structure for a node
typedef struct Node {
    char name[50]; // Item name
    int price;     // Item price
    int available; // Item availability
    struct Node* prev;    // Pointer to the previous node in the list
    struct Node* next;    // Pointer to the next node in the list
} Node;

// Structure to manage the linked list
typedef struct LinkedList {
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    int size;   // Size of the list
} LinkedList;

// Function prototypes
void createCircularDL(LinkedList* list, const char* name, int price, int available);
void addAtFirstNode(LinkedList* list, const char* name, int price, int available);
void addAtNthNode(LinkedList* list, const char* name, int price, int available, int pos);
void addAtLastNode(LinkedList* list, const char* name, int price, int available);
void updateFirstNode(LinkedList* list, const char* name, int price, int available);
void updateNthNode(LinkedList* list, const char* name, int price, int available, int pos);
void updateLastNode(LinkedList* list, const char* name, int price, int available);
void removeFirstNode(LinkedList* list);
void removeNthNode(LinkedList* list, int pos);
void removeLastNode(LinkedList* list);
void printCircularDL(LinkedList* list);
int countNodes(LinkedList* list);

int main() {
    LinkedList list = { NULL, NULL, 0 };

    // Create the circular doubly linked list with the first node
    createCircularDL(&list, "Laptop", 20000000, 20);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Add a node at the beginning of the list
    addAtFirstNode(&list, "Handphone", 5000000, 50);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Add nodes at the end of the list
    addAtLastNode(&list, "Mouse", 1200000, 100);
    addAtLastNode(&list, "Keyboard", 2250000, 100);
    addAtLastNode(&list, "Headphone", 1800000, 100);
    addAtLastNode(&list, "Monitor", 4200000, 100);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Remove the first node from the list
    removeFirstNode(&list);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Remove the last node from the list
    removeLastNode(&list);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Add a node at the nth position in the list
    addAtNthNode(&list, "RTX 5090", 40000000, 15, 3);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Remove the nth node from the list
    removeNthNode(&list, 4);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Update the first node in the list
    updateFirstNode(&list, "Laptop", 19000000, 10);
    // Update the nth node in the list
    updateNthNode(&list, "Mouse", 1000000, 3, 2);
    // Update the last node in the list
    updateLastNode(&list, "Headphone", 1900000, 5);
    printCircularDL(&list);
    printf("==========\n\n\n");

    // Print the total number of nodes in the list
    printf("Total nodes: %d\n", countNodes(&list));

    return 0;
}

// Function to create a circular doubly linked list with the first node
void createCircularDL(LinkedList* list, const char* name, int price, int available) {
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->available = available;
    newNode->next = newNode;
    newNode->prev = newNode;
    list->head = newNode;
    list->tail = newNode;
    list->size = 1;
}

// Function to add a node at the beginning of the list
void addAtFirstNode(LinkedList* list, const char* name, int price, int available) {
    if (list->size == 0) {
        createCircularDL(list, name, price, available);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->available = available;
    newNode->next = list->head;
    newNode->prev = list->tail;
    list->head->prev = newNode;
    list->tail->next = newNode;
    list->head = newNode;
    list->size++;
}

// Function to add a node at the nth position in the list
void addAtNthNode(LinkedList* list, const char* name, int price, int available, int pos) {
    if (pos < 1 || pos > list->size + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        addAtFirstNode(list, name, price, available);
        return;
    }
    if (pos == list->size + 1) {
        addAtLastNode(list, name, price, available);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->available = available;
    Node* cur = list->head;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    newNode->prev = cur;
    cur->next->prev = newNode;
    cur->next = newNode;
    list->size++;
}

// Function to add a node at the end of the list
void addAtLastNode(LinkedList* list, const char* name, int price, int available) {
    if (list->size == 0) {
        createCircularDL(list, name, price, available);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->available = available;
    newNode->next = list->head;
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->head->prev = newNode;
    list->tail = newNode;
    list->size++;
}

// Function to update the first node in the list
void updateFirstNode(LinkedList* list, const char* name, int price, int available) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->head->name, name);
    list->head->price = price;
    list->head->available = available;
}

// Function to update the nth node in the list
void updateNthNode(LinkedList* list, const char* name, int price, int available, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    strcpy(cur->name, name);
    cur->price = price;
    cur->available = available;
}

// Function to update the last node in the list
void updateLastNode(LinkedList* list, const char* name, int price, int available) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->tail->name, name);
    list->tail->price = price;
    list->tail->available = available;
}

// Function to remove the first node from the list
void removeFirstNode(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = list->head;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = list->head->next;
        list->head->prev = list->tail;
        list->tail->next = list->head;
    }
    delete(temp);
    list->size--;
}

// Function to remove the nth node from the list
void removeNthNode(LinkedList* list, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        removeFirstNode(list);
        return;
    }
    if (pos == list->size) {
        removeLastNode(list);
        return;
    }
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete(cur);
    list->size--;
}

// Function to remove the last node from the list
void removeLastNode(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = list->tail;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->tail = list->tail->prev;
        list->tail->next = list->head;
        list->head->prev = list->tail;
    }
    delete(temp);
    list->size--;
}

// Function to print the circular doubly linked list
void printCircularDL(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    Node* cur = list->head;
    do {
        printf("Name: %s, Price: %d, Available: %d\n", cur->name, cur->price, cur->available);
        cur = cur->next;
    } while (cur != list->head);
}

// Function to count the number of nodes in the list
int countNodes(LinkedList* list) {
    return list->size;
}