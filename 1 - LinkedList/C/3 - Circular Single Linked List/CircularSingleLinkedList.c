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
    char id[11];
    char name[50];
    char major[30];
    struct Node* next;
} Node;

// Structure to manage the linked list
typedef struct LinkedList {
    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    int size;   // Size of the list
} LinkedList;

// Function prototypes
void createCircularSL(LinkedList* list, const char* id, const char* name, const char* major);
void addAtFirstNode(LinkedList* list, const char* id, const char* name, const char* major);
void addAtNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos);
void addAtLastNode(LinkedList* list, const char* id, const char* name, const char* major);
void updateFirstNode(LinkedList* list, const char* id, const char* name, const char* major);
void updateNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos);
void updateLastNode(LinkedList* list, const char* id, const char* name, const char* major);
void removeFirstNode(LinkedList* list);
void removeNthNode(LinkedList* list, int pos);
void removeLastNode(LinkedList* list);
void printCircularSL(LinkedList* list);
int countNodes(LinkedList* list);

int main() {
    // Initialize the linked list
    LinkedList list = { NULL, NULL, 0 };

    // Create the circular singly linked list with the first node
    createCircularSL(&list, "11223399", "Arief F-sa", "Computer Science");
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Add a node at the beginning of the list
    addAtFirstNode(&list, "11223398", "Nisa Uswa", "Psychology");
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Add a node at the end of the list
    addAtLastNode(&list, "11223400", "Pejeel", "Drop out");
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Remove the first node from the list
    removeFirstNode(&list);
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Remove the last node from the list
    removeLastNode(&list);
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Add nodes at the beginning and end of the list
    addAtFirstNode(&list, "11223398", "Nisa Uswa", "Psychology");
    addAtLastNode(&list, "11223400", "Pejeel", "Drop out");
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Add nodes at specific positions in the list
    addAtNthNode(&list, "11223401", "dummy1", "Math", 3);
    addAtNthNode(&list, "11223402", "dummy2", "Physics", 2);
    printCircularSL(&list);
    printf("==========\n\n\n");

    // Remove the node at the specified position in the list
    removeNthNode(&list, 2);
    printCircularSL(&list);
    printf("==========\n\n\n");

    return 0;
}

// ========== CREATE ==========
// Function to create a circular singly linked list with the first node
void createCircularSL(LinkedList* list, const char* id, const char* name, const char* major) {
    Node* newNode = new(Node);
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = newNode;
    list->head = newNode;
    list->tail = newNode;
    list->size = 1;
}

// ========== ADD ==========
// Function to add a node at the beginning of the list
void addAtFirstNode(LinkedList* list, const char* id, const char* name, const char* major) {
    if (list->size == 0) {
        createCircularSL(list, id, name, major);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = list->head;
    list->tail->next = newNode;
    list->head = newNode;
    list->size++;
}

// Function to add a node at the nth position in the list
void addAtNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos) {
    if (pos < 1 || pos > list->size + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        addAtFirstNode(list, id, name, major);
        return;
    }
    if (pos == list->size + 1) {
        addAtLastNode(list, id, name, major);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    Node* cur = list->head;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    list->size++;
}

// Function to add a node at the end of the list
void addAtLastNode(LinkedList* list, const char* id, const char* name, const char* major) {
    if (list->size == 0) {
        createCircularSL(list, id, name, major);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->id, id);
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = list->head;
    list->tail->next = newNode;
    list->tail = newNode;
    list->size++;
}

// ========== UPDATE ==========
// Function to update the first node in the list
void updateFirstNode(LinkedList* list, const char* id, const char* name, const char* major) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->head->id, id);
    strcpy(list->head->name, name);
    strcpy(list->head->major, major);
}

// Function to update the nth node in the list
void updateNthNode(LinkedList* list, const char* id, const char* name, const char* major, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    strcpy(cur->id, id);
    strcpy(cur->name, name);
    strcpy(cur->major, major);
}

// Function to update the last node in the list
void updateLastNode(LinkedList* list, const char* id, const char* name, const char* major) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->tail->id, id);
    strcpy(list->tail->name, name);
    strcpy(list->tail->major, major);
}

// ========== DELETE ===========
// Function to remove the first node from the list
void removeFirstNode(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    Node* del = list->head;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }
    delete(del);
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
    Node* cur = list->head;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }
    Node* del = cur->next;
    cur->next = del->next;
    if (del == list->tail) {
        list->tail = cur;
    }
    delete(del);
    list->size--;
}

// Function to remove the last node from the list
void removeLastNode(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    Node* del = list->tail;
    if (list->size == 1) {
        list->head = NULL;
        list->tail = NULL;
    }
    else {
        Node* cur = list->head;
        while (cur->next != list->tail) {
            cur = cur->next;
        }
        list->tail = cur;
        list->tail->next = list->head;
    }
    delete(del);
    list->size--;
}

// ========== READ ===========
// Function to print the circular singly linked list
void printCircularSL(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    printf("Number of Nodes: %d\n", countNodes(list)); // Display the total number of nodes

    Node* cur = list->head;
    int i = 1;
    do {
        printf("Node %d\n", i);
        printf("ID\t\t: %s\n", cur->id);
        printf("Name\t\t: %s\n", cur->name);
        printf("Major\t\t: %s\n\n\n", cur->major);
        cur = cur->next;
        i++;
    } while (cur != list->head);
}

// ========== UTILS ===========
// Function to count the number of nodes in the list
int countNodes(LinkedList* list) {
    return list->size;
}