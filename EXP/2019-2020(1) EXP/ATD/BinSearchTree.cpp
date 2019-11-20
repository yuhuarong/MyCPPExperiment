#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


class Node {
public:
    char data;
    Node* left;
    Node* right;

    explicit Node(char data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    static void inOrderPrint(Node* node) {
        if(node == nullptr) {return;}
        char data = node->data;
        if(node->left != nullptr) {inOrderPrint(node->left);}
        cout << data;
        if(node->right != nullptr) {inOrderPrint(node->right);}
    }
};

class BinTree {
public:
    Node* root;

    static int depth(Node* root) {
        return root == nullptr ? 0: (1 + max(depth(root->left), depth(root->right)));
    }

    void inOrderPrint() {
        Node::inOrderPrint(root);
        cout << endl;
    }

    static void insert(Node* &parent, char val) {
        if(parent == nullptr) {
            Node* _node = new Node(val);
            parent = _node;
            return;
        }

        if(parent->data > val) {
            insert(parent->left, val);
        } else if(parent->data < val) {
            insert(parent->right, val);
        }
    }

    void insert(char val) {
        insert(this->root, val);
    }

    explicit BinTree(const char* exp) {
        root = nullptr;
        for(int i = 0; i < (int)strlen(exp); i++) {
            insert(root, exp[i]);
        }
    }
};

int main() {
    BinTree t("AHBKDJlkZdnelknljLKNLKlkNDK");
    t.inOrderPrint();
    t.insert('G');
    t.inOrderPrint();
}
