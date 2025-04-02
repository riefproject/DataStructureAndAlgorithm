#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 100

typedef struct {
    char** data;   // Pointer to an array of char pointers (strings)
    int top;
    int capacity;
} Stack;

// Initialize the dynamic stack
void initDynStack(Stack* s, int capacity) {
    s->data = (char**)malloc(capacity * sizeof(char*));
    s->top = -1;
    s->capacity = capacity;
}

// Check if the stack is full
int isFull(const Stack* s) {
    return s->top == s->capacity - 1;
}

// Check if the stack is empty
int isEmpty(const Stack* s) {
    return s->top == -1;
}

// Resize the stack
void resize(Stack* s) {
    s->capacity *= 2;
    s->data = (char**)realloc(s->data, s->capacity * sizeof(char*));
}

// Push a string onto the stack
void push(Stack* s, const char* value) {
    if (isFull(s)) {
        resize(s);
    }
    s->top++;
    s->data[s->top] = (char*)malloc(STR_MAX * sizeof(char));  // Allocate memory for the string
    strcpy(s->data[s->top], value);
    printf("Pushed %s onto stack.\n", value);
}

// Pop a string from the stack
void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY! Cannot pop.\n");
        return;
    }
    char* poppedValue = s->data[s->top];
    s->top--;
    printf("Popped %s from stack.\n", poppedValue);
    free(poppedValue);  // Free the memory for the popped string
}

// Get the top value without removing it
const char* topValue(const Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY! No top value.\n");
        return NULL;
    }
    return s->data[s->top];
}

// Peek a string at the n-th position from the top
const char* peek(const Stack* s, int n) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY! No element to peek.\n");
        return NULL;
    }
    int index = s->top - (n - 1);
    if (index < 0 || index > s->top) {
        printf("Invalid peek(%d). Not enough elements.\n", n);
        return NULL;
    }
    return s->data[index];
}

// Display the contents of the stack
void display(const Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is EMPTY!\n");
        return;
    }
    printf("Stack contents (top -> bottom):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("[%d]: %s\n", i + 1, s->data[i]);
    }
    printf("\n");
}

// Destroy the stack and free all memory
void destroyDynStack(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        free(s->data[i]);
    }
    free(s->data);  // Free the array of pointers
    s->data = NULL;
    s->top = -1;
    s->capacity = 0;
    printf("Stack destroyed.\n");
}

int main() {
    Stack books;
    initDynStack(&books, 5);

    push(&books, "Mathematics");
    push(&books, "Calculus");
    push(&books, "Physics");
    push(&books, "Web Design");
    push(&books, "Data Structure");

    display(&books);

    printf("Top of stack: %s\n", topValue(&books));
    printf("Peek(3): %s\n", peek(&books, 2));

    pop(&books);

    destroyDynStack(&books);

    return 0;
}