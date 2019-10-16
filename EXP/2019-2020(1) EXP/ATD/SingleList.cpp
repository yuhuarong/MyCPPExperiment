#include <iostream>
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

class SingleList {
public:
    Node* head;
    Node* tail;
    int size;
    SingleList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    explicit SingleList(int size) {
        if (size <= 1) {
            size = 2;
        }
        this->size = size;
        Node* node = new Node(1);
        head = node;
        for (int i = 2; i <= size; i++) {
            Node* _node = new Node(i);
            node->next = _node;
            node = node->next;
        }
        tail = node;
        tail->next = head;
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

    Node* _delete(Node* node) {
        Node* __node = tail;
        Node* _node = head;

        if (node == head) {
            head = head->next;
            delete tail->next;
            size--;
            tail->next = head;

            return tail;
        }

        if (node == tail) {
            Node* ___node = get(size - 2);
            delete ___node->next;
            size--;
            tail = ___node;
            tail->next = head;

            return tail;
        }

        for (int i = 0; i < size; i++) {
            if (node == _node) {
                __node->next = _node->next;
                delete _node;
                size--;
                return __node;
            } else {
                __node = _node;
                _node = _node->next;
            }
        }

        return nullptr;
    }

    void print() {
        for (int i = 0; i <= size; i++) {
            cout << get(i)->data << " ";
        }
        cout << endl;
    }

    Node* winner(int k) {

        if (k < 1) {
            return nullptr;
        }

        int t = 1;

        Node* node = head;
        while (size > 1) {
            if (t == k) {
                cout << "编号为 " << node->data << " 的人出局, 剩余: " << size << " 人" << endl;
                node = _delete(node)->next;
                t = 1;
            }
            else {
                node = node->next;
                t++;
            }
        }
        return head;
    }
};

int main()
{

    // n = 125, k = 131 -> winner = 104
    // n = 100, k = 8 -> winner = 97
    // n = 140, k = 1 -> winner = 140

    int n, k;
    cout << "输入N(人数), K(CODE):" << endl;
    cin >> n >> k;
    SingleList list(n);

    cout << "队列:" << endl;
    list.print();

    Node* winner = list.winner(k);
    if (winner == nullptr) {
        cout << "输入有误!"<<endl;
        return -1;
    }

    cout<<"胜利者是: " << winner->data << endl;
}
