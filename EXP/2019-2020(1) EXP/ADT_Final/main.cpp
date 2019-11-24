#include <iostream>
#include "LinkedList.cpp"

int main() {
    BigInteger integer0("-16273812947128946192461249128");
    BigInteger integer1("34234324923749237492374927349723984792374");
    integer0.print();
    integer1.print();
    BigInteger integer2 = integer0 - integer1;
    integer2.print();
    return 0;
}