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

    void operator*=(int e);

    BigInteger* multi(BigInteger* integer);

    void add0(int num);

    static void addLast(BigInteger &last, BigInteger &result, int imp);

    static void subLast(BigInteger &last, BigInteger &result, int imp);

    bool operator>(BigInteger &integer);

    bool operator<(BigInteger &integer);

    bool operator==(BigInteger &integer);

    BigInteger &clone();

    BigInteger &operator-();

    void divide2();

    BigInteger& mod(int i);

    static BigInteger &addMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &subMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &divideMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &multiMod(const string &integer0, const string &integer1, int _m);

    static BigInteger &powMod(const string &integer0, const string &integer1, int _m);
};
