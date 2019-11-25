#pragma once

#include <iostream>
#include "Node.h"
#include <cstring>
#include <cassert>
using namespace std;

class LinkedList {
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    LinkedList() {
        size = 0;
        head = tail = nullptr;
    }

    //创建逆序链表
    explicit LinkedList(const string &num) {
        size = strlen(num.c_str());
        Node *_node = nullptr;

        if (size == 0) {
            _node = new Node(0);
            head = tail = _node;
            head->next = tail;
            tail->prev = head;
            head->prev = tail->next = nullptr;
            size = 1;
            return;
        }
        for (int i = 0; i < size; i++) {
            int b = num[size - i - 1] - 48;
            if (head == nullptr) {
                head = tail = new Node(b);
                head->prev = tail->next = nullptr;
            } else {
                Node *node = new Node(b);
                node->prev = nullptr;
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
    }

    int removeHigh() {
        if (head == nullptr || tail == nullptr || size < 1) {
            head = tail = new Node(0);
            head->next = tail;
            tail->prev = head;
            head->prev = tail->next = nullptr;
            size = 1;
            return 0;
        } else if (size == 1) {
            int value = tail->data;
            head = tail = new Node(0);
            head->prev = tail->next = nullptr;
            size = 1;
            return value;
        } else {
            int value = tail->data;
            Node* t = tail->prev;
            delete tail;
            size--;
            tail = t;
            tail->next = nullptr;
            return value;
        }
    }

    int removeLow() {
        if (head == nullptr || tail == nullptr || size < 1) {
            head = tail = new Node(0);
            head->next = tail;
            tail->prev = head;
            head->prev = tail->next = nullptr;
            size = 1;
            return 0;
        } else if (size == 1) {
            int value = head->data;
            head = tail = new Node(0);
            head->prev = tail->next = nullptr;
            size = 1;
            return value;
        } else {
            int value = head->data;
            Node* t = head->next;
            delete head;
            size--;
            head = t;
            head->prev = nullptr;
            return value;
        }
    }

    int addHigh(int e) {
        if (head == nullptr || tail == nullptr || size < 1) {
            head = tail = new Node(e);
            head->next = tail;
            tail->prev = head;
            head->prev = tail->next = nullptr;
            size = 1;
            return e;
        } else {
            head->prev = new Node(e);
            head->prev->next = head;
            head = head->prev;
            head->prev = nullptr;
            size++;
            return e;
        }
    }

    int addLow(int e) {
        if (head == nullptr || tail == nullptr || size < 1) {
            head = tail = new Node(e);
            head->next = tail;
            tail->prev = head;
            head->prev = tail->next = nullptr;
            size = 1;
            return e;
        } else {
            tail->next = new Node(e);
            tail->next->prev = tail;
            tail = tail->prev;
            tail->next = nullptr;
            size++;
            return e;
        }
    }

    int getHigh() {
        return tail->data;
    }

    int getLow() {
        return head->data;
    }

    LinkedList(LinkedList& list) {
        Node* node = list.head;
        while(node) {
            if (head == nullptr) {
                head = tail = new Node(node->data);
                tail->next = nullptr;
            } else {
                Node *_node = new Node(node->data);
                _node->next = head;
                head = _node;
            }
            node = node->next;
        }
    }

    friend ostream& operator<<(ostream& out, LinkedList& list) {
        if (list.head == nullptr) {
            out << 0;
        } else {
            Node* node = list.tail;
            while (node) {
                out << node->data;
                node = node->prev;
            }
        }
        return out;
    }

    ~LinkedList() {
        Node* node = head;
        while (node) {
            head = node->next;
            delete node;
        }
    }
};