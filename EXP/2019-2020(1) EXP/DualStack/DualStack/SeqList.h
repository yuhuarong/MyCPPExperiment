#pragma once
#include <iostream>

using namespace std;

const int maxSize = 256;

class SeqList {
public:
	SeqList() {
		length = 0;
	}

	SeqList(int a[], int n) {
		if (n > maxSize) {
			length = maxSize;
		} else {
			length = n;
		}

		for (int i = 0; i < length; i++) {
			data[i] = a[i];
		}
	}

	~SeqList() {

	}

	void Insert(int i, int x) {

		if (i > maxSize - 1) {
			i = maxSize - 1;
		}

		if (i > length) {
			data[length] = x;
		} else {
			for (int k = length; k > i; k--) {
				data[k] = data[k - 1];
			}
			data[i] = x;
		}
		length++;
	}

	void Delete(int i) {
		if (i > length - 1 || length <= 0) {
			return;
		}

		for (int k = i; k < length; k++) {
			data[i] = data[i + 1];
			length--;
		}
	}


	int Locate(int x) {
		for (int i = 0; i < length; i++) {
			if (x == data[i]) {
				return i;
			}
		}

		return -1;
	}


	void PrintList() {
		for (int i = 0; i < length; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}

private:
	int length;
	int data[maxSize+1];
};

