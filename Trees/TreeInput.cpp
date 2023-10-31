#include<iostream>
#include<queue>
using namespace std;

// Input a tree given in form of series of numbers. If val = -1, node is NULL.

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    Node* root = new Node(rootData);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            Node* l = new Node(leftChild);
            curr->left = l;
            q.push(l);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            Node* r = new Node(rightChild);
            curr->right = r;
            q.push(r);
        }
    }
    return root;
}

int main() {
    Node* root = takeInput();
    
}