#pragma once

#include <iostream>
#include "Node.h"
#include <cstring>
#include <cassert>
using namespace std;


class LinkedList {
public:
    Node *head = nullptr;
    int size = 0;

    LinkedList() {
        size = 0;
        head = nullptr;
    }

    explicit LinkedList(const string &num) {
        size = strlen(num.c_str());
        Node *_node = nullptr;

        if (size == 0) {
            _node = new Node(0);
            head = _node;
            size = 1;
            return;
        }
        for (char i : num) {
            if (head == nullptr) {
                head = new Node(i - 48);
                _node = head;
            } else {
                Node *node = new Node(i - 48);
                assert(_node != nullptr);
                _node->next = node;
                _node = node;
            }
        }
    }

    Node *get(int index) {
        if (index < 0) {
            return nullptr;
        }
        Node *node = this->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }

    int length() {
        return this->size;
    }

    int remove(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        if (index == 0) {
            Node *node = head->next;
            delete head;
            head = node;
            size--;
            return 0;
        } else if (index == size - 1) {
            delete get(size - 1);
            size--;
            get(size - 1)->next = nullptr;
            return index;
        }

        Node *node = get(index - 1);
        Node *_node = node->next->next;
        delete node->next;
        node->next = _node;
        size--;
        return index;
    }

    void print() {
        if (head == nullptr) {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << get(i)->data;
        }
        cout << endl;
    }

    ~LinkedList() {
        if (head != nullptr) {
            while (size) {
                remove(0);
            }
        }
    }
};