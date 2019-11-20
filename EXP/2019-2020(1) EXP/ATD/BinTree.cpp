#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

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
        if(node == nullptr) {
            return;
        }
        char data = node->data;
        if(data == '+' || data == '-' || data == '*' || data == '/') {
            cout << "(";
        }

        if(node->left != nullptr) {
            inOrderPrint(node->left);
        }

        cout << data;

        if(node->right != nullptr) {
            inOrderPrint(node->right);
        }

        if(data == '+' || data == '-' || data == '*' || data == '/') {
            cout << ")";
        }
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
    }

    void drawTree() {
        int d = depth(root);
        int width = (int)pow(2, d-1)*3;
        while(d--) {

        };
    }

    explicit BinTree(const char* exp) {
        Node* _node;
        vector<Node*> v;

        for(int i = 0; i < (int)strlen(exp); i++) {
            _node = new Node(exp[i]);
            if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
                _node->right = v.back();
                v.pop_back();
                _node->left = v.back();
                v.pop_back();
                v.push_back(_node);
            } else {
                v.push_back(_node);
            }
        }
        root = v.back();
    }
};

int main() {
    BinTree t("abc+*def+-/ghij*//*");
    t.inOrderPrint();
    // (((a*(b+c))/(d-(e+f)))*(g/(h/(i*j))))
}