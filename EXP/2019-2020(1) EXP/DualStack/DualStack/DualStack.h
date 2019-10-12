#pragma once
#include <iostream>
#include <deque>

using namespace std;

enum StackNumber {
	ONE, TWO
};

template<class T>
class DualStack {
public:
	void push(const T& item, StackNumber number) {
		switch (number) {
		case StackNumber::ONE:
			elements.push_front(item);
			count1++;
			break;
		case StackNumber::TWO:
			elements.push_back(item);
			count2++;
			break;
		}
	}
	void pop(StackNumber number) {
		switch (number) {
		case StackNumber::ONE:
			if (count1 == 0) {
				return;
			}
			elements.pop_front();
			count1--;
			break;
		case StackNumber::TWO:
			if (count2 == 0) {
				return;
			}
			elements.pop_back();
			count2--;
			break;
		}
	}
	T& top(StackNumber number) const {
		switch (number) {
		case StackNumber::ONE:
			if (count1 == 0) {
				return NULL;
			}
			return elements.front();
		case StackNumber::TWO:
			if (count2 == 0) {
				return NULL;
			}
			return elements.back();
		}
	}
	bool empty(StackNumber number) {
		switch (number) {
		case StackNumber::ONE:
			return count1 == 0;
		case StackNumber::TWO:
			return count2 == 0;
		}
	}
	int size(StackNumber number) {
		switch (number) {
		case StackNumber::ONE:
			return count1;
		case StackNumber::TWO:
			return count2;
		}
	}

	DualStack() {
		count1 = 0;
		count2 = 0;
	}

private:
	deque<T> elements;
	int count1;
	int count2;
};
