#include "BigInteger.h"

BigInteger::BigInteger(const string &num) : number(trim(num)), isPositive(positive(num)) {}

string BigInteger::trim(const string &num) {
    if (!check(num)) {
        cout << "number format error" << endl;
        exit(-1);
    }
    if (num[0] == '-') {
        return num.substr(1);
    } else if (num[0] == '+') {
        return num.substr(1);
    } else {
        return num;
    }
}

bool BigInteger::positive(const string &num) {
    return num[0] != '-';
}

bool BigInteger::check(const string &num) {
    if (num.find_last_of("+-") != string::npos && num.find_last_of("+-") != 0) {
        return false;
    }
    return num.find_last_not_of("0123456789") == 0 || num.find_last_not_of("0123456789") == string::npos;
}

void BigInteger::print() {
    cout << (isPositive ? '+' : '-') << number << endl;
}

int BigInteger::length() {
    return number.size;
}

BigInteger &BigInteger::trim() {
    while (number.tail && number.tail->data == 0) {
        number.removeHigh();
    }
    return *this;
}

BigInteger &BigInteger::operator+(BigInteger &integer) {
    if (this->isPositive && integer.isPositive) {
        BigInteger i0 = this->clone();
        BigInteger i1 = integer.clone();
        BigInteger result("0");
        int imp = 0;
        while (i0.length() > 0 && i1.length() > 0) {
            int sum = i0.number.getLow() + i1.number.getLow();
            result.number.addHigh((sum + imp) % 10);
            if ((sum + imp) >= 10) {
                imp = 1;
            } else {
                imp = 0;
            }
            i0.number.removeLow();
            i1.number.removeLow();
        }
        if (i0.length() > 0) {
            addLast(i0, result, imp);
        } else if (i1.length() > 0) {
            addLast(i1, result, imp);
        } else {
            result.number.addHigh(imp);
        }
        result.number.removeLow();
        return result.clone();
    } else if (!this->isPositive && !integer.isPositive) {
        BigInteger i0 = -this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = -(i0 + i1);
        return result;
    } else if (this->isPositive && !integer.isPositive) {
        BigInteger i0 = this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = i0 - i1;
        return result;
    } else {
        BigInteger i0 = -this->clone();
        BigInteger i1 = integer.clone();
        BigInteger &result = i1 - i0;
        return result;
    }
}

BigInteger &BigInteger::operator-(BigInteger &integer) {
    if (this->isPositive && integer.isPositive) {
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        if (i0 > i1) {
            BigInteger result("0");
            int imp = 0;
            while (i0.length() > 0 && i1.length() > 0) {
                int sub = i0.number.getLow() - i1.number.getLow();
                if (sub >= 0) {
                    if ((sub + imp) < 0) {
                        result.number.addHigh(10 + sub + imp);
                        imp = -1;
                    } else {
                        result.number.addHigh(sub + imp);
                        imp = 0;
                    }
                } else {
                    result.number.addHigh(10 + sub + imp);
                    imp = -1;
                }
                i0.number.removeLow();
                i1.number.removeLow();
            }
            subLast(i0, result, imp);
            result.number.removeLow();
            return result.clone();
        } else if (i0 < i1) {
            return -(i1 - i0);
        } else {
            BigInteger int0("0");
            return int0.clone();
        }
    } else if (!this->isPositive && !integer.isPositive) {
        BigInteger i0 = -this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = -(i0 - i1);
        return result;
    } else if (this->isPositive && !integer.isPositive) {
        BigInteger i0 = this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = i0 + i1;
        return result;
    } else {
        BigInteger i0 = -this->clone();
        BigInteger i1 = integer.clone();
        BigInteger &result = -(i1 + i0);
        return result;
    }
}

BigInteger &BigInteger::operator*(BigInteger &integer) {
    if (this->isPositive && integer.isPositive) {
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        BigInteger result("0");
        int size = i1.length();
        for (int i = 0; i < size; i++) {
            int e = i1.number.getLow();
            BigInteger temp = singleMulti(i0, e);
            temp.add0(i);
            result = result + temp;
            i1.number.removeLow();
        }
        return result.clone();
    } else if (!this->isPositive && !integer.isPositive) {
        BigInteger i0 = -this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = i1 * i0;
        return result;
    } else if (this->isPositive && !integer.isPositive) {
        BigInteger i0 = this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = -(i0 * i1);
        return result;
    } else {
        BigInteger i0 = -this->clone();
        BigInteger i1 = integer.clone();
        BigInteger &result = -(i0 * i1);
        return result;
    }
}

void BigInteger::operator*=(int e) {
    int imp = 0;
    Node* node = number.head;
    while (node) {
        int d = node->data * e + imp;
        node->data = d % 10;
        imp = d / 10;
        node = node->next;
    }
    if (imp > 0) {
        number.addHigh(imp);
    }
}

BigInteger *BigInteger::multi(BigInteger* integer) {
    auto* result = new BigInteger("0");
    int size0 = this->length();
    int size1 = integer->length();
    result->add0(size0 + size1 - 1);

    Node* result_head = result->number.head;
    Node* int_head = integer->number.head;
    while (int_head) {
        Node* temp_result_head = result_head;
        int imp = 0;
        Node* this_head = this->number.head;
        while (this_head) {
            int d = this_head->data * int_head->data + imp + result_head->data;
            result_head->data = d % 10;
            imp = d / 10;
            this_head = this_head->next;
            result_head = result_head->next;
        }
        result_head->data += imp;
        int_head = int_head->next;
        result_head = temp_result_head->next;
    }
    result->trim();

    return result;
}

BigInteger &BigInteger::operator*(int e) {
    if (this->isPositive && e > 0) {
        BigInteger i0 = this->clone().trim();
        return singleMulti(i0, e);
    } else if (!this->isPositive && e < 0) {
        BigInteger i0 = -this->clone();
        BigInteger *result = &(i0 * e);
        return *result;
    } else if (this->isPositive && e < 0) {
        BigInteger i0 = this->clone();
        BigInteger *result = &(-(i0 * e));
        return *result;
    } else {
        BigInteger i0 = -this->clone();
        BigInteger *result = &(-(i0 * e));
        return *result;
    }
}

BigInteger &BigInteger::operator/(BigInteger &integer) {
    if (this->isPositive && integer.isPositive) {
        BigInteger int2("2");
        BigInteger int1("1");
        BigInteger int0("0");
        if (integer == int0) {
            cout << "please not divide with 0" << endl;
            return int0.clone();
        } else if (integer == int1) {
            return this->clone();
        } else if (*this < integer) {
            return int0.clone();
        }
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        BigInteger result("0");
        BigInteger ent("0");
        while (i0.length() > 0) {
            if (ent < i1) {
                ent.number.addLow(i0.number.getHigh());
                result.number.addLow(0);
            } else {
                for (int i = 1; i <= 10; i++) {
                    if (ent < i1 * i) {
                        result.number.addLow(i - 1);
                        ent = ent - i1 * (i - 1);
                        ent.number.addLow(i0.number.getHigh());
                        break;
                    }
                }
            }
            i0.number.removeHigh();
        }
        for (int i = 1; i <= 10; i++) {
            if (ent < i1 * i) {
                result.number.addLow(i - 1);
                break;
            }
        }
        return result.clone();
    } else if (!this->isPositive && !integer.isPositive) {
        BigInteger i0 = -this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = i0 / i1;
        return result;
    } else if (this->isPositive && !integer.isPositive) {
        BigInteger i0 = this->clone();
        BigInteger i1 = -integer.clone();
        BigInteger &result = -(i0 / i1);
        return result;
    } else {
        BigInteger i0 = -this->clone();
        BigInteger i1 = integer.clone();
        BigInteger &result = -(i0 / i1);
        return result;
    }
}

BigInteger &BigInteger::operator^(BigInteger &integer) {
    BigInteger int2("2");
    BigInteger int0("0");
    BigInteger i0 = this->clone().trim();
    BigInteger i1 = integer.clone().trim();
    if (i0.isPositive && i1.isPositive) {
        BigInteger result("1");
        while (i1 > int0) {
            if (i1.number.getLow() % 2 == 1) {
                result = ((result.clone() * i0) % m);
            }
            i1 = i1 / int2;
            i0 = (i0 * i0) % m;
        }
        return result.clone();
    } else {
        return int0.clone();
    }
}

BigInteger &BigInteger::operator%(int _m) {
    BigInteger &integer = this->clone();
    if (integer.length() <= _m) {
        return integer;
    } else {
        while (integer.length() > _m) {
            integer.number.removeHigh();
        }
        return integer;
    }
}

BigInteger &BigInteger::singleMulti(BigInteger &integer, int e) {
    BigInteger result("0");
    BigInteger temp = integer.clone();
    int imp = 0;
    while (temp.length() > 0) {
        int mul = e * temp.number.getLow();
        result.number.addHigh((mul + imp) % 10);
        imp = (mul + imp) / 10;
        temp.number.removeLow();
    }
    result.number.addHigh(imp);
    result.number.removeLow();
    return result.clone();
}

void BigInteger::add0(int num) {
    for (int i = 0; i < num; i++) {
        number.addLow(0);
    }
}

void BigInteger::addLast(BigInteger &last, BigInteger &result, int imp) {
    while (last.length() > 0) {
        int s = last.number.getLow();
        result.number.addHigh((s + imp) % 10);
        imp = (s + imp) / 10;
        last.number.removeLow();
    }
    result.number.addHigh(imp);
}

void BigInteger::subLast(BigInteger &last, BigInteger &result, int imp) {
    while (last.length() > 0) {
        int sub = last.number.getLow();
        if ((sub + imp) < 0) {
            result.number.addHigh(10 + sub + imp);
            imp = -1;
        } else {
            result.number.addHigh(sub + imp);
            imp = 0;
        }
        last.number.removeLow();
    }
}

bool BigInteger::operator>(BigInteger &integer) {
    BigInteger i0 = this->clone().trim();
    BigInteger i1 = integer.clone().trim();
    if (i0.length() > i1.length()) {
        return true;
    } else if (i0.length() < i1.length()) {
        return false;
    } else {
        Node *tail0 = i0.number.tail;
        Node *tail1 = i1.number.tail;
        while (tail0 && tail1) {
            if (tail0->data > tail1->data) {
                return true;
            } else if (tail0->data < tail1->data) {
                return false;
            } else {
                tail0 = tail0->prev;
                tail1 = tail1->prev;
            }
        }
        return false;
    }
}

bool BigInteger::operator<(BigInteger &integer) {
    BigInteger i0 = this->clone().trim();
    BigInteger i1 = integer.clone().trim();
    if (i0.length() < i1.length()) {
        return true;
    } else if (i0.length() > i1.length()) {
        return false;
    } else {
        Node *tail0 = i0.number.tail;
        Node *tail1 = i1.number.tail;
        while (tail0 && tail1) {
            if (tail0->data < tail1->data) {
                return true;
            } else if (tail0->data > tail1->data) {
                return false;
            } else {
                tail0 = tail0->prev;
                tail1 = tail1->prev;
            }
        }
        return false;
    }
}

bool BigInteger::operator==(BigInteger &integer) {
    BigInteger i0 = this->clone().trim();
    BigInteger i1 = integer.clone().trim();
    if (i0.length() != i1.length()) {
        return false;
    } else {
        Node *tail0 = i0.number.tail;
        Node *tail1 = i1.number.tail;
        while (tail0 && tail1) {
            if (tail0->data != tail1->data) {
                return false;
            } else {
                tail0 = tail0->prev;
                tail1 = tail1->prev;
            }
        }
        return true;
    }
}

BigInteger &BigInteger::clone() {
    BigInteger &c = *new BigInteger("0");
    c.isPositive = isPositive;
    c.number = *new LinkedList(number);
    return c;
}

BigInteger &BigInteger::operator-() {
    this->isPositive = !this->isPositive;
    return *this;
}

BigInteger &BigInteger::addMod(const string &integer0, const string &integer1, int _m) {
    return (*new BigInteger(integer0) + *new BigInteger(integer1)) % _m;
}

BigInteger &BigInteger::subMod(const string &integer0, const string &integer1, int _m) {
    return (*new BigInteger(integer0) - *new BigInteger(integer1)) % _m;
}

BigInteger &BigInteger::divideMod(const string &integer0, const string &integer1, int _m) {
    return (*new BigInteger(integer0) / *new BigInteger(integer1)) % _m;
}

BigInteger &BigInteger::multiMod(const string &integer0, const string &integer1, int _m) {
    return (*new BigInteger(integer0) * *new BigInteger(integer1)) % _m;
}

BigInteger &BigInteger::powMod(const string &integer0, const string &integer1, int _m) {
    BigInteger i0(integer0);
    BigInteger i1(integer1);
    BigInteger int0("0");
    BigInteger int2("2");
    if (i0.isPositive && i1.isPositive) {
        BigInteger result("1");
        i0.mod(_m);
        while (i1 > int0) {
            if (i1.number.getLow() & 1) {
                result = (result * i0).mod(_m);
            }
            i1 = i1 / int2;
            i0 = (i0 * i0).mod(_m);
        }
        return result.clone();
    } else {
        return int0.clone();
    }
}

void BigInteger::divide2() {
    int imp = 0;
    Node* node = number.tail;
    while (node) {
        if (imp == 0) {
            imp = node->data & 1;
            node->data >>= 1;
        } else {
            imp = node->data & 1;
            node->data = (10 + node->data) >> 1;
        }
        node = node->prev;
    }
}

BigInteger& BigInteger::mod(int i) {
    while (this->length() > i) {
        this->number.removeHigh();
    }
    return *this;
}
