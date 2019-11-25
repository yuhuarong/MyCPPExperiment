#include "LinkedList.h"

LinkedList::LinkedList() {
    size = 0;
    head = tail = nullptr;
}

LinkedList::LinkedList(const string &num) {
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
        int b = num[i] - 48;
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

int LinkedList::removeHigh() {
    if (head == nullptr || tail == nullptr || size < 1) {
        return 0;
    } else if (size == 1) {
        int value = tail->data;
        delete tail;
        head = tail = nullptr;
        size = 0;
        return value;
    } else {
        int value = tail->data;
        Node *t = tail->prev;
        delete tail;
        size--;
        tail = t;
        tail->next = nullptr;
        return value;
    }
}

int LinkedList::removeLow() {
    if (head == nullptr || tail == nullptr || size < 1) {
        return 0;
    } else if (size == 1) {
        int value = head->data;
        delete head;
        head = tail = nullptr;
        size = 0;
        return value;
    } else {
        int value = head->data;
        Node *t = head->next;
        delete head;
        size--;
        head = t;
        head->prev = nullptr;
        return value;
    }
}

int LinkedList::addHigh(int e) {
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
        tail = tail->next;
        tail->next = nullptr;
        size++;
        return e;
    }
}

int LinkedList::addLow(int e) {
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

int LinkedList::getHigh() {
    if(tail == nullptr) {
        return 0;
    }
    return tail->data;
}

int LinkedList::getLow() {
    if(head == nullptr) {
        return 0;
    }
    return head->data;
}

LinkedList::LinkedList(LinkedList &list) {
    Node *node = list.head;
    this->size = list.size;
    while (node) {
        if (head == nullptr) {
            head = tail = new Node(node->data);
            tail->next = nullptr;
        } else {
            Node *_node = new Node(node->data);
            tail->next = _node;
            _node->prev = tail;
            tail = _node;
            tail->next = nullptr;
        }
        node = node->next;
    }
}

ostream &operator<<(ostream &out, LinkedList &list) {
    Node *node = list.tail;
    if (node == nullptr) {
        out << 0;
    } else {
        while (node != nullptr) {
            out << node->data;
            node = node->prev;
        }
    }
    return out;
}

LinkedList::~LinkedList() {
    Node *node = head;
    while(node!=tail) {
        head = head->next;
        delete node;
        node = head;
    }
}
