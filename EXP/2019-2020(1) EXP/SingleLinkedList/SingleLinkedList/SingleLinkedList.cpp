#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	int data;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class CirList {
public:
	Node* head;
	Node* tail;
	int size;
	CirList() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	CirList(int size) {
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
			return NULL;
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
			Node* _node = get(size - 2);
			delete _node->next;
			size--;
			tail = _node;
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

		return NULL;
	}

	void print() {
		for (int i = 0; i <= size; i++) {
			cout << get(i)->data << " ";
		}
		cout << endl;
	}

	Node* winner(int k) {
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
	int n = 100;
	int k = 8;
	cout << "输入N(人数), K(CODE)" << endl;
	cin >> n >> k;
	CirList list(n);

	cout << "队列:" << endl;
	list.print();

	cout<<"胜利者是: " << list.winner(k)->data << endl;
}
