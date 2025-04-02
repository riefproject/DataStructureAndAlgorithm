# Basic Single Linked List in C

## Introduction

A Single Linked List is a type of linked list where each node contains a data part and a pointer to the next node in the sequence. This structure allows for efficient traversal and manipulation of the list in a single direction (forward).

## Structure

### Node Structure

Each node in the Single Linked List contains:

-   `title`: A string representing the title associated with the node.
-   `author`: A string representing the author associated with the node.
-   `year`: A string representing the year associated with the node.
-   `next`: A pointer to the next node in the list.

### Linked List Structure

The linked list is managed using a structure that contains:

-   `head`: A pointer to the head (first node) of the list.
-   `tail`: A pointer to the tail (last node) of the list.
-   `size`: An integer representing the size (number of nodes) of the list.

## Functions

### Adding Nodes

-   `void addNode(LinkedList* list, const char* title, const char* author, const char* year);`

    -   Adds a node at the end of the list.

-   `void addAtFirstNode(LinkedList* list, const char* title, const char* author, const char* year);`

    -   Adds a node at the beginning of the list.

-   `void addAtNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos);`
    -   Adds a node at the nth position in the list.

### Updating Nodes

-   `void updateFirstNode(LinkedList* list, const char* title, const char* author, const char* year);`

    -   Updates the first node in the list.

-   `void updateNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos);`

    -   Updates the nth node in the list.

-   `void updateLastNode(LinkedList* list, const char* title, const char* author, const char* year);`
    -   Updates the last node in the list.

### Removing Nodes

-   `void removeAtFirst(LinkedList* list);`

    -   Removes the first node from the list.

-   `void removeAtNthNode(LinkedList* list, int pos);`

    -   Removes the nth node from the list.

-   `void removeAtLast(LinkedList* list);`
    -   Removes the last node from the list.

### Utility Functions

-   `void printSingleLinkedList(LinkedList* list);`

    -   Prints the single linked list.

-   `int countNodes(LinkedList* list);`
    -   Returns the number of nodes in the list.

## Example Usage

Here is an example of how to use the Basic Single Linked List in C:

1. **Initialize the Linked List:**
    ```c
    LinkedList list = { NULL, NULL, 0 };
    ```
2. **Add Nodes**
    - At the beginning
    ```c
        addAtFirstNode(&list, "Chemistry", "Wijaya", "2019");
    ```
    - At a specific position
    ```c
    addAtNthNode(&list, "F1 For Child", "Anomali", "2000", 2);
    ```
    - node
    ```c
    addNode(&list, "Introduction to C", "Arief", "2022");
    ```
3. **Update Nodes**
    - First node
    ```c
    updateFirstNode(&list, "Introduction to C++", "Arief", "2022");
    ```
    - Nth node
    ```c
    updateNthNode(&list, "Math", "Nisa", "2024", 2);
    ```
    - Last node
    ```c
    updateLastNode(&list, "Updated Title", "Updated Author", "Updated Year");
    ```
4. **Last Nodes**
    - First node
    ```c
    removeAtFirst(&list);
    ```
    - Nth node
    ```c
    removeAtNthNode(&list, 2);
    ```
    - Last node
    ```c
    removeAtLast(&list);
    ```
5. **Print the List**

```c
printSingleLinkedList(&list);
```

6. **Count the Nodes**

```c
int totalNodes = countNodes(&list);
printf("Total nodes: %d\n", totalNodes);
```

## Conclusion

The Basic Single Linked List is a versatile data structure that allows efficient insertion, deletion, and traversal operations. This implementation in C demonstrates how to create, manipulate, and manage a single linked list. The provided functions cover various operations, including adding, updating, removing, and printing nodes, as well as counting the total number of nodes in the list.
