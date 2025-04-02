#include <stdio.h>

#define new(var) (var *)malloc(sizeof(var)) // Allocates memory for a new variable of type 'var'
#define delete(var) \
    free(var);      \
    var = NULL; // Frees allocated memory and sets the pointer to NULL to prevent dangling references

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = new(Node);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

}
int main() {

}