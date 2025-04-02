#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define new(var) (var *)malloc(sizeof(var)) 
#define delete(var) \
    free(var);      \
    var = NULL; 


typedef struct Node {
    char title[50];  
    char author[50]; 
    char year[5];    
    struct Node* next; 
} Node;


typedef struct LinkedList {
    Node* head; 
    Node* tail; 
    int size;   
} LinkedList;


void addNode(LinkedList* list, const char* title, const char* author, const char* year);
void addAtFirstNode(LinkedList* list, const char* title, const char* author, const char* year);
void addAtNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos);
void updateFirstNode(LinkedList* list, const char* title, const char* author, const char* year);
void updateNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos);
void updateLastNode(LinkedList* list, const char* title, const char* author, const char* year);
void removeAtFirst(LinkedList* list);
void removeAtNthNode(LinkedList* list, int pos);
void removeAtLast(LinkedList* list);
void printSingleLinkedList(LinkedList* list);
int countNodes(LinkedList* list);

int main() {
    LinkedList list = { NULL, NULL, 0 };

    
    addNode(&list, "Introduction to C", "Arief", "2022");
    printSingleLinkedList(&list);
    printf("=========\n\n");

    addAtFirstNode(&list, "Chemistry", "Wijaya", "2019");
    printSingleLinkedList(&list);
    printf("=========\n\n");

    addNode(&list, "Physics", "Nisa", "2024");
    addNode(&list, "Introduction to Python", "Arief", "2023");
    addAtNthNode(&list, "F1 For Child", "Anomali", "2000", 2);
    printSingleLinkedList(&list);
    printf("=========\n\n");

    
    removeAtFirst(&list);
    printSingleLinkedList(&list);
    updateFirstNode(&list, "Introduction to C++", "Arief", "2022");
    printf("=========\n\n");

    removeAtLast(&list);
    printSingleLinkedList(&list);
    printf("=========\n\n");

    removeAtNthNode(&list, 2);
    printSingleLinkedList(&list);
    printf("=========\n\n");

    addNode(&list, "Introduction to Kotlin", "Arief", "2023");
    updateNthNode(&list, "Math", "Nisa", "2024", 2);
    printSingleLinkedList(&list);
    printf("=========\n\n");

    return 0;
}

/*
 * Linked List Operations
 * ======================
 */

 
void addAtFirstNode(LinkedList* list, const char* title, const char* author, const char* year) {
    Node* newBook = new(Node); 

    
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->year, year);

    
    newBook->next = list->head;
    list->head = newBook;

    if (list->size == 0) {
        list->tail = newBook;
    }

    list->size++;
}


void addAtNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos) {
    if (pos < 1 || pos > list->size + 1) 
    {
        printf("position out of range\n");
        return;
    }
    if (pos == 1) 
    {
        addAtFirstNode(list, title, author, year);
        return;
    }
    if (pos == list->size + 1) 
    {
        addNode(list, title, author, year);
        return;
    }

    
    Node* newBook = new(Node); 

    
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->year, year);

    
    Node* cur = list->head;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }

    
    newBook->next = cur->next;
    cur->next = newBook;

    list->size++;
}


void addNode(LinkedList* list, const char* title, const char* author, const char* year) {
    Node* newBook = new(Node); 
    if (newBook == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    strcpy(newBook->year, year);
    newBook->next = NULL;

    
    if (list->head == NULL) 
    {
        list->head = newBook;
        list->tail = newBook;
    }
    else {
        list->tail->next = newBook;
        list->tail = newBook;
    }

    list->size++;
}


void updateFirstNode(LinkedList* list, const char* title, const char* author, const char* year) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }

    
    strcpy(list->head->title, title);
    strcpy(list->head->author, author);
    strcpy(list->head->year, year);
}


void updateNthNode(LinkedList* list, const char* title, const char* author, const char* year, int pos) {
    if (pos < 1 || pos > list->size) 
    {
        printf("position out of range\n");
        return;
    }
    if (pos == 1) 
    {
        updateFirstNode(list, title, author, year);
        return;
    }
    if (pos == list->size) 
    {
        updateLastNode(list, title, author, year);
        return;
    }

    
    Node* cur = list->head;
    for (int i = 1; i < pos; i++) 
    {
        cur = cur->next;
    }

    
    strcpy(cur->title, title);
    strcpy(cur->author, author);
    strcpy(cur->year, year);
}


void updateLastNode(LinkedList* list, const char* title, const char* author, const char* year) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }

    
    strcpy(list->tail->title, title);
    strcpy(list->tail->author, author);
    strcpy(list->tail->year, year);
}


void removeAtFirst(LinkedList* list) {
    if (list->size == 0)
        return; 

    Node* del = list->head;        
    list->head = list->head->next; 
    delete(del);                   

    if (list->size == 1) {
        list->tail = NULL;
    }

    list->size--;
}


void removeAtNthNode(LinkedList* list, int pos) {
    if (pos < 1 || pos > list->size) 
    {
        printf("position out of range\n");
        return;
    }
    if (pos == 1) 
    {
        removeAtFirst(list);
        return;
    }
    if (pos == list->size) 
    {
        removeAtLast(list);
        return;
    }

    
    Node* cur = list->head;
    Node* before = NULL;
    for (int i = 1; i < pos; ++i) {
        before = cur;    
        cur = cur->next; 
    }

    before->next = cur->next; 
    delete(cur);              

    list->size--;
}


void removeAtLast(LinkedList* list) {
    if (list->size == 0)
        return; 

    if (list->size == 1) 
    {
        delete(list->head);      
        list->head = list->tail = NULL; 
        list->size--;
        return;
    }

    
    Node* cur = list->head;
    while (cur->next != list->tail) {
        cur = cur->next;
    }

    Node* del = list->tail;        
    list->tail = cur;              
    list->tail->next = NULL;       
    delete(del);                   

    list->size--;
}


void printSingleLinkedList(LinkedList* list) {
    printf("Number of Nodes: %d\n", countNodes(list)); 
    Node* cur = list->head;
    int i = 1;
    while (cur != NULL) {
        printf("NODE %d\n", i);                
        printf("Title\t: %s\n", cur->title);   
        printf("Author\t: %s\n", cur->author); 
        printf("Year\t: %s\n\n\n", cur->year); 
        cur = cur->next;                       
        i++;
    }
}


int countNodes(LinkedList* list) {
    Node* cur = list->head;
    int count = 0;
    while (cur != NULL) {
        count++;         
        cur = cur->next; 
    }
    return count; 
}