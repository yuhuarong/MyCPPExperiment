#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Node {
public:
    Node* next;
    int data;
    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head = nullptr;
    int size = 0;
    LinkedList() {
        size = 0;
        head = nullptr;
    }

    explicit LinkedList(const string& num) {
        size = strlen(num.c_str());
        Node* _node = nullptr;
        for(char i : num) {
            if(head == nullptr) {
                head = new Node(i-48);
                _node = head;
            } else {
                Node* node = new Node(i-48);
                assert(_node != nullptr);
                _node->next = node;
                _node = node;
            }
        }
    }

    Node* get(int index) {
        if (index < 0) {
            return nullptr;
        }
        Node* node = this->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        return node;
    }

    int _size() {
        return this->size;
    }

    int _delete(Node* node) {
        Node* _node = head;
        if(size == 0) {
            return -1;
        }

        if (node == head) {
            Node* __node = head->next;
            delete head;
            head = __node;
            size--;
            return 0;
        } else {
            Node* __node = head;
            for (int i = 1; i < size; i++) {
                if (node == _node) {
                    __node->next = _node->next;
                    delete _node;
                    size--;
                    return i;
                } else {
                    __node = _node;
                    _node = _node->next;
                }
            }
        }

        return -1;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << get(i)->data << " ";
        }
        cout << endl;
    }

    ~LinkedList() {
        if (head != nullptr) {
            while(size) {
                _delete(get(size-1));
                print();
            }
        }
    }
};
