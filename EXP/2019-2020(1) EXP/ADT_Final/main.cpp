#include <iostream>
#include "LinkedList.cpp"

int main() {
    LinkedList l("1324353671892387162546712893412876341728");
    cout<<l.get(5)->data<<endl;
    l.print();
    l._delete(l.get(5));
    l.print();
    return 0;
}