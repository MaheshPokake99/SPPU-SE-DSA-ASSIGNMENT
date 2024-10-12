#include <iostream>
using namespace std;

class node {
public:
    node *left, *right;
    int data;
    int lth;
    int rth;
    node(int data) : data(data), left(nullptr), right(nullptr), lth(0), rth(0) {}
};

class TBT {
public:
    // Function to insert a node into the threaded binary tree
    node* insert(node* root, int val) {
        node* head = root;
        node* parent = NULL;

        // Traverse the tree to find the appropriate position for the new node
        while (head != NULL) {
            if (val == head->data) {
                cout << "Duplicate\n";
                return root;
            }
            parent = head;
            if (val < head->data) {
                if (head->lth == 0) {
                    head = head->left;
                } else {
                    break;
                }
            } else {
                if (head->rth == 0) {
                    head = head->right;
                } else {
                    break;
                }
            }
        }
        
        // Create a new node with the given value and set thread flags
        node* temp = new node(val);
        temp->lth = 1;
        temp->rth = 1;

        // Insert the new node into the tree
        if (parent == NULL) {
            // If the tree is empty, set the new node as the root
            root = temp;
            temp->left = NULL;
            temp->right = NULL;
        } else if (val < parent->data) {
            // If the value is less than the parent's data, insert on the left
            temp->left = parent->left;
            temp->right = parent;
            parent->lth = 0;
            parent->left = temp;
        } else {
            // If the value is greater than the parent's data, insert on the right
            temp->left = parent;
            temp->right = parent->right;
            parent->rth = 0;
            parent->right = temp;
        }

        return root;
    }

    // Function to perform an in-order traversal of the threaded binary tree
    void inorder(node* root) {
        node* curr = leftmost(root);

        while (curr != NULL) {
            cout << curr->data << " ";
            if (curr->rth == 1) {
                curr = curr->right;
            } else {
                curr = leftmost(curr->right);
            }
        }
    }

private:
    // Helper function to find the leftmost node in a subtree
    node* leftmost(node* node) {
        while (node != NULL && node->lth == 0) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    TBT tree;
    node* root = nullptr;

    // Insert values into the threaded binary tree
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);
    root = tree.insert(root, 30);
    root = tree.insert(root, 5);
    root = tree.insert(root, 16);
    root = tree.insert(root, 14);
    root = tree.insert(root, 17);
    root = tree.insert(root, 13);

    // Perform an in-order traversal and print the result
    cout << "Inorder: ";
    tree.inorder(root);
    
    return 0;
}
