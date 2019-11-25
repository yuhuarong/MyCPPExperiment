#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

class BigInteger {
public:
    LinkedList number;

    bool isPositive;

    static const int m = 150;

    explicit BigInteger(const string &num);

    static string trim(const string &num);

    static bool positive(const string &num);

    static bool check(const string &num);

    void print();

    int length();

    BigInteger &trim();

    BigInteger &operator+(BigInteger &integer);

    BigInteger &operator-(BigInteger &integer);

    BigInteger &operator*(BigInteger &integer);

    BigInteger &operator*(int e);

    BigInteger &operator/(BigInteger &integer);

    BigInteger &operator^(BigInteger &integer);

    BigInteger &operator%(int _m);

    static BigInteger &singleMulti(BigInteger &integer, int e);

    void add0(int num);

    static void addLast(BigInteger &last, BigInteger &result, int imp);

    static void subLast(BigInteger &last, BigInteger &result, int imp);

    bool operator>(BigInteger &integer);

    bool operator<(BigInteger &integer);

    bool operator==(BigInteger &integer);

    BigInteger &clone();

    BigInteger &operator-();;

    static BigInteger &addMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &subMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &divideMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &multiMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &powMod(const string &integer0, const string &integer1, int _m) {
        BigInteger i0(integer0);
        BigInteger i1(integer1);
        BigInteger int0("0");
        BigInteger int2("2");
        if (i0.isPositive && i1.isPositive) {
            BigInteger result("1");
            i0 = i0 % _m;
            while (i1 > int0) {
                if (i1.number.getLow() % 2 == 1) {
                    result = (result * i0) % _m;
                }
                i1 = i1 / int2;
                i0 = (i0 * i0) % _m;
            }
            // result.trim();
            return result.clone();
        } else {
            return int0.clone();
        }
    }
};
