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

    LinkedList();

    //创建逆序链表
    explicit LinkedList(const string &num);

    int removeHigh();

    int removeLow();

    int addHigh(int e);

    int addLow(int e);

    int getHigh();

    int getLow();

    LinkedList(LinkedList &list);

    friend ostream &operator<<(ostream &out, LinkedList &list);

    ~LinkedList();
};