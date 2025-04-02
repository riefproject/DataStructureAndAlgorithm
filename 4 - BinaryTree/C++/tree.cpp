#include <iostream>

using namespace std;

// Mendefinisikan struktur untuk node tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Kelas untuk mengelola binary tree
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    // Menambahkan node ke dalam binary tree
    void insert(int value) {
        root = insertIntoTree(root, value);
    }

    // Mencari node dengan nilai tertentu
    bool search(int value) {
        return searchInTree(root, value);
    }

    // Menghapus node dari binary tree
    void remove(int value) {
        root = removeFromTree(root, value);
    }

    // Traversal in-order
    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Traversal pre-order
    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

    // Traversal post-order
    void postOrderTraversal() {
        postOrder(root);
        cout << endl;
    }

private:
    TreeNode* insertIntoTree(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertIntoTree(node->left, value);
        }
        else {
            node->right = insertIntoTree(node->right, value);
        }
        return node;
    }

    bool searchInTree(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        }
        else if (value < node->value) {
            return searchInTree(node->left, value);
        }
        else {
            return searchInTree(node->right, value);
        }
    }

    TreeNode* removeFromTree(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->value) {
            node->left = removeFromTree(node->left, value);
        }
        else if (value > node->value) {
            node->right = removeFromTree(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = removeFromTree(node->right, temp->value);
        }
        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->value << " ";
            inOrder(node->right);
        }
    }

    void preOrder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(TreeNode* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->value << " ";
        }
    }
};

int main() {
    BinaryTree bt;

    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(20);
    bt.insert(40);
    bt.insert(60);
    bt.insert(80);

    cout << "In-order traversal: ";
    bt.inOrderTraversal();

    cout << "Pre-order traversal: ";
    bt.preOrderTraversal();

    cout << "Post-order traversal: ";
    bt.postOrderTraversal();

    // Mencari nilai dalam tree
    if (bt.search(30)) {
        cout << "Found 30 in the tree." << endl;
    }
    else {
        cout << "30 not found in the tree." << endl;
    }

    // Menghapus nilai dari tree
    bt.remove(70);
    cout << "In-order traversal after removing 70: ";
    bt.inOrderTraversal();

    return 0;
}
