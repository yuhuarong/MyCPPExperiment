#include <iostream>
#include "LinkedList.cpp"

int main() {
    BigInteger integer0("-92735182368912639126391263912123456");
    BigInteger integer1("-7991232455167548748897589753419965692735182368912639126391263912123456");
    BigInteger integer2 = integer1 + integer0;//124690
    integer2.print();
    return 0;
}