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

    int length() {
        return this->size;
    }

    int remove(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }

        if (index == 0) {
            Node* node = head->next;
            delete head;
            head = node;
            size--;
            return 0;
        } else if (index == size - 1) {
            delete get(size-1);
            size--;
            return index;
        }

        Node* node = get(index-1);
        Node* _node = node->next->next;
        delete node->next;
        node->next = _node;
        size--;
        return index;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << get(i)->data;
        }
        cout << endl;
    }

    ~LinkedList() {
        if (head != nullptr) {
            while(size) {
                remove(0);
            }
        }
    }
};

class BigInteger {
public:
    LinkedList number;
    bool isPositive = false;
    explicit BigInteger(const string& num): number(trim(num)) {}

    string trim(const string& num) {
        if (!check(num)) {
            exit(12);
        }
        if (num[0] == '-') {
            isPositive = false;
            return num.substr(1);
        } else if (num[0] == '+') {
            isPositive = true;
            return num.substr(1);
        } else {
            isPositive = true;
            return num;
        }
    }
    static bool check(const string& num) {
        if (num.find_last_of("+-") != string::npos && num.find_last_of("+-") != 0) {
            return false;
        }
        return num.find_last_not_of("0123456789") == 0 || num.find_last_not_of("0123456789") == string::npos;
    }

    void print() {
        cout << (isPositive? '+' : '-');number.print();
    }
    int length() {
        return number.length();
    }
    int getLow(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        return number.get(length()-index-1)->data;
    }

    int getHigh(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        return number.get(index)->data;
    }

    int removeLow(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        number.remove(length()-index-1);
        return index;
    }

    int removeHigh(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        number.remove(index);
        return index;
    }
};
