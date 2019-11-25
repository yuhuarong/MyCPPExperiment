#pragma once

class Node {
public:
    Node *next;
    Node *prev;
    int data;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

