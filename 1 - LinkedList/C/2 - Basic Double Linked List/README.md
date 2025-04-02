# Basic Double Linked List in C

## Introduction

A Double Linked List is a type of linked list where each node contains a data part and two pointers, one pointing to the next node and the other pointing to the previous node. This structure allows for efficient traversal and manipulation of the list in both directions (forward and backward).

## Structure

### Node Structure

Each node in the Double Linked List contains:

-   `name`: A string representing the name associated with the node.
-   `username`: A string representing the username associated with the node.
-   `email`: A string representing the email associated with the node.
-   `password`: A string representing the password associated with the node.
-   `prev`: A pointer to the previous node in the list.
-   `next`: A pointer to the next node in the list.

### Linked List Structure

The linked list is managed using a structure that contains:

-   `head`: A pointer to the head (first node) of the list.
-   `tail`: A pointer to the tail (last node) of the list.
-   `size`: An integer representing the size (number of nodes) of the list.

## Functions

### Creating the List

-   `void createDoubleLinkedList(LinkedList* list, const char* name, const char* username, const char* email, const char* password);`
    -   Creates a double linked list with the first node.

### Adding Nodes

-   `void addAtFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);`

    -   Adds a node at the beginning of the list.

-   `void addAtNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos);`

    -   Adds a node at the nth position in the list.

-   `void addAtLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);`
    -   Adds a node at the end of the list.

### Updating Nodes

-   `void updateFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);`

    -   Updates the first node in the list.

-   `void updateNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos);`

    -   Updates the nth node in the list.

-   `void updateLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);`
    -   Updates the last node in the list.

### Removing Nodes

-   `void removeAtFirst(LinkedList* list);`

    -   Removes the first node from the list.

-   `void removeAtNthNode(LinkedList* list, int pos);`

    -   Removes the nth node from the list.

-   `void removeAtLast(LinkedList* list);`
    -   Removes the last node from the list.

### Utility Functions

-   `void printDoubleLinkedList(LinkedList* list);`

    -   Prints the double linked list.

-   `int countNodes(LinkedList* list);`
    -   Returns the number of nodes in the list.

## Example Usage

Here is an example of how to use the Basic Double Linked List in C:

1. **Initialize the Linked List:**
    ```c
    LinkedList list = { NULL, NULL, 0 };
    ```
2. **Create the Double Linked List with the First Node**

```c
createDoubleLinkedList(&list, "Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
```

3. **Add Nodes**
    - At the beginning
    ```c
    addAtFirstNode(&list, "Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
    ```
    - At a specific position
    ```c
    addAtNthNode(&list, "Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
    ```
    - At the last
    ```c
    addAtLastNode(&list, "Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
    ```
4. **Update Nodes**
    - First node
    ```c
    updateFirstNode(&list, "Updated Name", "updated_username", "updated@mail.id", "Updated123");
    ```
    - Nth node
    ```c
    updateNthNode(&list, "Updated Name", "updated_username", "updated@mail.id", "Updated123", 2);
    ```
    - Last node
    ```c
    updateLastNode(&list, "Updated Name", "updated_username", "updated@mail.id", "Updated123");
    ```
5. **Remove Nodes**
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
6. **Print the List**

```c
printDoubleLinkedList(&list);
```

7. **Count the Nodes**

```c
int totalNodes = countNodes(&list);
printf("Total nodes: %d\n", totalNodes);
```

## Conclusion

The Basic Double Linked List is a versatile data structure that allows efficient insertion, deletion, and traversal operations. This implementation in C demonstrates how to create, manipulate, and manage a double linked list. The provided functions cover various operations, including adding, updating, removing, and printing nodes, as well as counting the total number of nodes in the list.
