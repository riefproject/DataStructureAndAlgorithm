#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[128];       // URL of the webpage
    struct Node* next;   // Pointer to the next node
    struct Node* prev;   // Pointer to the previous node
} Node;

typedef struct {
    Node* top;           // Pointer to the top of the stack
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push a new URL onto the stack
void push(Stack* s, char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    strcpy(newNode->url, url);
    newNode->next = NULL;
    newNode->prev = s->top;

    if (s->top != NULL) {
        s->top->next = newNode;
    }
    s->top = newNode;
    printf("Visited %s\n", url);
}

// Pop the top URL from the stack
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("No more history to go back.\n");
        return NULL;
    }
    Node* temp = s->top;
    char* url = temp->url;
    s->top = temp->prev;

    if (s->top != NULL) {
        s->top->next = NULL;
    }
    free(temp);
    printf("Going back from %s\n", url);
    return url;
}

// Get the current URL without removing it
char* peek(Stack* s) {
    if (isEmpty(s)) {
        printf("No current page available.\n");
        return NULL;
    }
    return s->top->url;
}

// Display all URLs in the stack
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("No history available.\n");
        return;
    }
    printf("Browser History (top to bottom):\n");
    Node* current = s->top;
    while (current != NULL) {
        printf("%s\n", current->url);
        current = current->prev;
    }
}

// Free all nodes in the stack
void destroyStack(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    printf("All history cleared.\n");
}

int main() {
    Stack browserHistory;
    initStack(&browserHistory);

    push(&browserHistory, "http://example.com");
    push(&browserHistory, "http://example.com/about");
    push(&browserHistory, "http://example.com/contact");

    display(&browserHistory);

    pop(&browserHistory);
    display(&browserHistory);

    destroyStack(&browserHistory);

    return 0;
}
