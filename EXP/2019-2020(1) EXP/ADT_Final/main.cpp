#include "LinkedList.cpp"

int main() {
    BigInteger integer0("11287543812712431274538125487152847512895489125945129845918254912698423");
    BigInteger integer1("1287543812712431274538125487152847512895489125945129845918254912698423");
    integer0.print();
    integer1.print();
    BigInteger integer2 = integer0 / integer1;
    integer2.print();
    return 0;
}