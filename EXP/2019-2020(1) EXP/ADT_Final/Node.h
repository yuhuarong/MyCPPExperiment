#pragma once

class Node {
public:
    Node *next;
    int data;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

