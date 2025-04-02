# Circular Single Linked List in C

## Introduction

A Circular Single Linked List is a type of linked list where the last node points back to the first node, forming a circular structure. Each node contains data and a pointer to the next node in the sequence. This structure allows for efficient traversal and manipulation of the list, as it can be traversed from any node to any other node in a circular manner.

## Structure

### Node Structure

Each node in the Circular Single Linked List contains:
- `id`: A string representing the unique identifier of the node.
- `name`: A string representing the name associated with the node.
- `major`: A string representing the major or field of study associated with the node.
- `next`: A pointer to the next node in the list.

### Linked List Structure

The linked list is managed using a structure that contains:
- `head`: A pointer to the head (first node) of the list.
- `tail`: A pointer to the tail (last node) of the list.
- `size`: An integer representing the size (number of nodes) of the list.

## Functions

### Creating the List

- `void createCircularSL(LinkedList* list, const char* id, const char* name, const char* major);`
  - Creates a circular singly linked list with the first node.

### Adding Nodes

- `void addAtFirstNode(LinkedList* list, const char* id, const char* name, const char* major);`
  - Adds a node at the beginning of the list.

- `void addAtNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos);`
  - Adds a node at the nth position in the list.

- `void addAtLastNode(LinkedList* list, const char* id, const char* name, const char* major);`
  - Adds a node at the end of the list.

### Updating Nodes

- `void updateFirstNode(LinkedList* list, const char* id, const char* name, const char* major);`
  - Updates the first node in the list.

- `void updateNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos);`
  - Updates the nth node in the list.

- `void updateLastNode(LinkedList* list, const char* id, const char* name, const char* major);`
  - Updates the last node in the list.

### Removing Nodes

- `void removeFirstNode(LinkedList* list);`
  - Removes the first node from the list.

- `void removeNthNode(LinkedList* list, int pos);`
  - Removes the nth node from the list.

- `void removeLastNode(LinkedList* list);`
  - Removes the last node from the list.

### Utility Functions

- `void printCircularSL(LinkedList* list);`
  - Prints the circular singly linked list.

- `int countNodes(LinkedList* list);`
  - Returns the number of nodes in the list.

## Example Usage

Here is an example of how to use the Circular Single Linked List in C:

1. **Initialize the Linked List**
   ```c
   LinkedList list = { NULL, NULL, 0 };
   ```
2. **Create the Circular Singly Linked List with the First Node**
    ```c
    createCircularSL(&list, "11223399", "Arief F-sa", "Computer Science");
    ```
3. **Add Nodes**
    - At the beginning
    ```c
    addAtFirstNode(&list, "11223398", "Nisa Uswa", "Psychology");
    ```
    - At the end
    ```c
    addAtLastNode(&list, "11223400", "Pejeel", "Drop out");
    ```
    - At a specific position
    ```c
    addAtNthNode(&list, "11223401", "dummy1", "Math", 3);;
    ```
4. **Update Nodes**
    - First node
    ```c
    updateFirstNode(&list, "11223397", "Updated Name", "Updated Major");
    ```
    - Nth node
    ```c
    updateNthNode(&list, "11223396", "Updated Name", "Updated Major", 2);
    ```
    - Last Node
    ```c
    updateFirstNode(&list, "11223397", "Updated Name", "Updated Major");
    ```
5. **Remove Nodes**
    - First node:
    ```c
    removeFirstNode(&list);
    ```    
    - Nth node:
    ```c
    removeNthNode(&list, 2);
    ```    
    - Last node:
    ```c
    removeLastNode(&list);
    ```
6. **Print the List**
    ```c
    printCircularSL(&list);
    ```
7. **Count the Nodes**
    ```c
    int totalNodes = countNodes(&list);
    printf("Total nodes: %d\n", totalNodes);
    ```
## Conclusion
The Circular Single Linked List is a versatile data structure that allows efficient insertion, deletion, and traversal operations. This implementation in C demonstrates how to create, manipulate, and manage a circular singly linked list. The provided functions cover various operations, including adding, updating, removing, and printing nodes, as well as counting the total number of nodes in the list.
