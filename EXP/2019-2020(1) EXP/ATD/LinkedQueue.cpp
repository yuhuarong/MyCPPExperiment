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

class LinkedQueue {
public:
    Node* head;
    Node* tail;
    int _size;

    explicit LinkedQueue(int size) {
        if (size <= 1) {
            size = 2;
        }
        this->_size = size;
        Node* node = new Node(0);
        head = node;
        for (int i = 1; i < size; i++) {
            Node* _node = new Node(i);
            node->next = _node;
            node = node->next;
        }
        tail = node;
        tail->next = head;
    }

    LinkedQueue(LinkedQueue const &queue) {
        if (queue.empty()) {
            return;
        }
        head = nullptr;
        tail = nullptr;
        _size = 0;
        for (int i = 0; i < queue.size(); i++) {
            Node* __node = queue.get(i);
            Node* _node = new Node(__node->data);
            enqueue(_node);
        }
    }

    [[nodiscard]] Node* get(int index) const {
        if (index < 0) {
            return nullptr;
        }
        Node* node = this->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        return node;
    }

    [[nodiscard]] int size() const {
        return this->_size;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    [[nodiscard]] Node* front() const{
        return head;
    }

    [[nodiscard]] Node* back() const{
        return tail;
    }

    LinkedQueue& operator=(const LinkedQueue& queue) {
        if (queue.empty()) {
            return *this;
        }
        head = nullptr;
        tail = nullptr;
        _size = 0;
        for (int i = 0; i < queue.size(); i++) {
            Node* __node = queue.get(i);
            Node* _node = new Node(__node->data);
            enqueue(_node);
        }
    }

    void dequeue() {
        if (empty()) {
            return;
        } else if (_size == 1) {
            _delete(head);
            tail = nullptr;
            return;
        }
        _delete(head);
    }

    void enqueue(Node* node) {
        if (empty()) {
            head = node;
            tail = node;
            tail->next = head;
            _size++;
            return;
        }
        tail->next = node;
        tail = node;
        tail->next = head;
        _size++;
    }

    Node* _delete(Node* node) {
        Node* __node = tail;
        Node* _node = head;

        if (node == head) {
            head = head->next;
            delete tail->next;
            _size--;
            tail->next = head;

            return tail;
        }

        if (node == tail) {
            Node* ___node = get(_size - 2);
            delete ___node->next;
            _size--;
            tail = ___node;
            tail->next = head;

            return tail;
        }

        for (int i = 0; i < _size; i++) {
            if (node == _node) {
                __node->next = _node->next;
                delete _node;
                _size--;
                return __node;
            } else {
                __node = _node;
                _node = _node->next;
            }
        }

        return nullptr;
    }

    void display() const {
        if (_size == 0) {
            cout << "empty queue" << endl;
            return;
        }
        for (int i = 0; i < _size; i++) {
            cout << get(i)->data << " ";
        }
        cout << endl;
    }

    ~LinkedQueue() {
        while(_size) {
            dequeue();
        }
    }
};

int main() {
    cout << "hello" << endl;
    LinkedQueue queue(15);
    queue.display();

    queue.enqueue(new Node(16));
    queue.display();
    queue.dequeue();
    queue.display();

    LinkedQueue queue1(queue);
    cout << "copied queue1: "; queue1.display();
    queue1.dequeue();
    queue1.display();
    queue.display();

    LinkedQueue queue2 = queue1;
    cout << "copied queue2: "; queue1.display();
    queue2.dequeue();
    queue2.display();
    queue.display();

    return 0;
}