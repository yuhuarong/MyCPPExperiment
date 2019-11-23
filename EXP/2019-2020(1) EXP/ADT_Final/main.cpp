#include <iostream>
#include "LinkedList.cpp"

int main() {
    BigInteger integer("-1324353671892387162546712893412876341728");
    integer.print();
    cout << integer.getHigh(38) << endl;
    return 0;
}