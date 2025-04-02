# Circular Double Linked List in C

## Introduction

A Circular Double Linked List is a type of linked list in which each node contains a data part and two pointers, one pointing to the next node and the other pointing to the previous node. The last node of the list points back to the first node, forming a circular structure. This type of linked list allows traversal in both directions (forward and backward) and provides efficient insertion and deletion operations.

## Structure

### Node Structure

Each node in the Circular Double Linked List contains:

-   `name`: A string representing the item name.
-   `price`: An integer representing the item price.
-   `available`: An integer representing the item availability.
-   `prev`: A pointer to the previous node in the list.
-   `next`: A pointer to the next node in the list.

### Linked List Structure

The linked list is managed using a structure that contains:

-   `head`: A pointer to the head (first node) of the list.
-   `tail`: A pointer to the tail (last node) of the list.
-   `size`: An integer representing the size (number of nodes) of the list.

## Functions

### Creating the List

-   `void createCircularDL(LinkedList* list, const char* name, int price, int available);`
    -   Creates a circular doubly linked list with the first node.

### Adding Nodes

-   `void addAtFirstNode(LinkedList* list, const char* name, int price, int available);`

    -   Adds a node at the beginning of the list.

-   `void addAtNthNode(LinkedList* list, const char* name, int price, int available, int pos);`

    -   Adds a node at the nth position in the list.

-   `void addAtLastNode(LinkedList* list, const char* name, int price, int available);`
    -   Adds a node at the end of the list.

### Updating Nodes

-   `void updateFirstNode(LinkedList* list, const char* name, int price, int available);`

    -   Updates the first node in the list.

-   `void updateNthNode(LinkedList* list, const char* name, int price, int available, int pos);`

    -   Updates the nth node in the list.

-   `void updateLastNode(LinkedList* list, const char* name, int price, int available);`
    -   Updates the last node in the list.

### Removing Nodes

-   `void removeFirstNode(LinkedList* list);`

    -   Removes the first node from the list.

-   `void removeNthNode(LinkedList* list, int pos);`

    -   Removes the nth node from the list.

-   `void removeLastNode(LinkedList* list);`
    -   Removes the last node from the list.

### Utility Functions

-   `void printCircularDL(LinkedList* list);`

    -   Prints the circular doubly linked list.

-   `int countNodes(LinkedList* list);`
    -   Returns the number of nodes in the list.

## Example Usage

Here is an example of how to use the Circular Double Linked List in C:

```c
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
```

## Conclusion

The Circular Double Linked List is a versatile data structure that allows efficient insertion, deletion, and traversal operations. This implementation in C demonstrates how to create, manipulate, and manage a circular doubly linked list. The provided functions cover various operations, including adding, updating, removing, and printing nodes, as well as counting the total number of nodes in the list.
