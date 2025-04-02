#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define new(var) (var *)malloc(sizeof(var)) #define delete(var) \
    free(var);      \
    var = NULL; 
typedef struct Node {
    char name[50];         char username[50];     char email[30];        char password[50];     struct Node* prev;     struct Node* next; } Node;

typedef struct LinkedList {
    Node* head;     Node* tail;     int size;   } LinkedList;

void createDoubleLinkedList(LinkedList* list, const char* name, const char* username, const char* email, const char* password);
void addAtFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);
void addAtNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos);
void addAtLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);
void updateFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);
void updateNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos);
void updateLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password);
void removeAtFirst(LinkedList* list);
void removeAtNthNode(LinkedList* list, int pos);
void removeAtLast(LinkedList* list);
void printDoubleLinkedList(LinkedList* list);
int countNodes(LinkedList* list);

int main() {
    LinkedList list = { NULL, NULL, 0 };

    createDoubleLinkedList(&list, "Arief F-sa", "ariefff", "arief@mail.id", "Arief123");
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    addAtLastNode(&list, "Fadly Pejel", "pejeel", "fadly@mail.id", "Fadly123");
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    addAtFirstNode(&list, "Nisa Uswa", "icaaa", "nisa@mail.id", "Nisa123");
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    removeAtFirst(&list);
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    removeAtLast(&list);
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    addAtFirstNode(&list, "dummyE", "dummy_5", "dummy5@mail.id", "Dummy123");
    addAtFirstNode(&list, "dummyD", "dummy_4", "dummy4@mail.id", "Dummy123");
    addAtFirstNode(&list, "dummyC", "dummy_3", "dummy3@mail.id", "Dummy123");
    addAtFirstNode(&list, "dummyB", "dummy_2", "dummy2@mail.id", "Dummy123");
    addAtFirstNode(&list, "dummyA", "dummy_1", "dummy1@mail.id", "Dummy123");
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    addAtNthNode(&list, "Ayang", "icaaa", "nisa@mail.id", "Nisa123", 5);
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    removeAtNthNode(&list, 6);
    printDoubleLinkedList(&list);
    printf("==========\n\n\n");

    return 0;
}

void createDoubleLinkedList(LinkedList* list, const char* name, const char* username, const char* email, const char* password) {
    Node* newNode = (Node *)malloc(sizeof(Node))
    strcpy(newNode->name, name);
    strcpy(newNode->username, username);
    strcpy(newNode->email, email);
    strcpy(newNode->password, password);
    newNode->prev = NULL;
    newNode->next = NULL;
    list->head = newNode;
    list->tail = newNode;
    list->size = 1;
}

void addAtFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password) {
    if (list->size == 0) {
        createDoubleLinkedList(list, name, username, email, password);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    strcpy(newNode->username, username);
    strcpy(newNode->email, email);
    strcpy(newNode->password, password);
    newNode->prev = NULL;
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
    list->size++;
}

void addAtNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos) {
    if (pos < 1 || pos > list->size + 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        addAtFirstNode(list, name, username, email, password);
        return;
    }
    if (pos == list->size + 1) {
        addAtLastNode(list, name, username, email, password);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    strcpy(newNode->username, username);
    strcpy(newNode->email, email);
    strcpy(newNode->password, password);
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

void addAtLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password) {
    if (list->size == 0) {
        createDoubleLinkedList(list, name, username, email, password);
        return;
    }
    Node* newNode = new(Node);
    strcpy(newNode->name, name);
    strcpy(newNode->username, username);
    strcpy(newNode->email, email);
    strcpy(newNode->password, password);
    newNode->prev = list->tail;
    newNode->next = NULL;
    list->tail->next = newNode;
    list->tail = newNode;
    list->size++;
}


void updateFirstNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->head->name, name);
    strcpy(list->head->username, username);
    strcpy(list->head->email, email);
    strcpy(list->head->password, password);
}

void updateNthNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    strcpy(cur->name, name);
    strcpy(cur->username, username);
    strcpy(cur->email, email);
    strcpy(cur->password, password);
}

void updateLastNode(LinkedList* list, const char* name, const char* username, const char* email, const char* password) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    strcpy(list->tail->name, name);
    strcpy(list->tail->username, username);
    strcpy(list->tail->email, email);
    strcpy(list->tail->password, password);
}

void removeAtFirst(LinkedList* list) {
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
        list->head->prev = NULL;
    }
    delete(del);
    list->size--;
}

void removeAtNthNode(LinkedList* list, int pos) {
    if (pos < 1 || pos > list->size) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        removeAtFirst(list);
        return;
    }
    if (pos == list->size) {
        removeAtLast(list);
        return;
    }
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    Node* del = cur;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete(del);
    list->size--;
}

void removeAtLast(LinkedList* list) {
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
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    delete(del);
    list->size--;
}

void printDoubleLinkedList(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }
    printf("Number of Nodes: %d\n", countNodes(list)); 
    Node* cur = list->head;
    int i = 1;
    while (cur != NULL) {
        printf("Node %d\n", i);
        printf("name\t\t: %s\n", cur->name);
        printf("userame\t\t: %s\n", cur->username);
        printf("email\t\t: %s\n", cur->email);
        printf("password\t: %s\n\n\n", cur->password);
        cur = cur->next;
        i++;
    }
}

int countNodes(LinkedList* list) {
    Node* cur = list->head;
    int count = 0;
    while (cur != NULL) {
        count++;                 cur = cur->next;     }
    return count; }