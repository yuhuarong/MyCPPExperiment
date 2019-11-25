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
            tail

            return value;
        }
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

    iostream& toString(iostream& out) {
        if (head == nullptr) {
            out << 0;
        }
        Node* node = head;
        while (node) {
            out << node->data;
            node = node->next;
        }
        return out;
    }

    ~LinkedList() {
        if (head != nullptr) {
            while (size) {
                remove(0);
            }
        }
    }
};