#include <iostream>
#include <string>
#include "SeqList.h"
#include "DualStack.h"

using namespace std;

void testSeqList() {
	cout << "---------SeqList------------" << endl;
	SeqList list;
	int r[] = { 0, 2, 4, 53, 3424 };
	SeqList list2(r, 5);
	list.Insert(0, 5);
	list.Insert(0, 2);
	list.Insert(0, 3);
	list.Insert(2, 6);
	list.PrintList();
	list.Delete(2);
	list.PrintList();
	list.Delete(20);
	list.PrintList();
	list2.PrintList();
	list2.Delete(4);
	list2.PrintList();
	cout << "where is 53: " << list2.Locate(53) << endl;
}

void testDualStack() {
	cout << "---------DualStack------------" << endl;
	DualStack<string> stack;
	stack.push("hello", StackNumber::ONE);

	stack.pop(StackNumber::ONE);
}

int main() {
	//testSeqList();

	testDualStack();
}

