#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class Node {
public:
    Node *next;
    int data;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head = nullptr;
    int size = 0;

    LinkedList() {
        size = 0;
        head = nullptr;
    }

    explicit LinkedList(const string &num) {
        size = strlen(num.c_str());
        Node *_node = nullptr;

        if (size == 0) {
            _node = new Node(0);
            head = _node;
            size = 1;
            return;
        }
        for (char i : num) {
            if (head == nullptr) {
                head = new Node(i - 48);
                _node = head;
            } else {
                Node *node = new Node(i - 48);
                assert(_node != nullptr);
                _node->next = node;
                _node = node;
            }
        }
    }

    Node *get(int index) {
        if (index < 0) {
            return nullptr;
        }
        Node *node = this->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }

    int length() {
        return this->size;
    }

    int remove(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        if (index == 0) {
            Node *node = head->next;
            delete head;
            head = node;
            size--;
            return 0;
        } else if (index == size - 1) {
            delete get(size - 1);
            size--;
            get(size - 1)->next = nullptr;
            return index;
        }

        Node *node = get(index - 1);
        Node *_node = node->next->next;
        delete node->next;
        node->next = _node;
        size--;
        return index;
    }

    void print() {
        if (head == nullptr) {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << get(i)->data;
        }
        cout << endl;
    }

    ~LinkedList() {
        if (head != nullptr) {
            while (size) {
                remove(0);
            }
        }
    }
};

class BigInteger {
public:
    LinkedList number;

    bool isPositive;

    static const int m = 10;

    explicit BigInteger(const string &num) : number(trim(num)), isPositive(positive(num)) {}

    static string trim(const string &num) {
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

    static bool positive(const string &num) {
        return num[0] != '-';
    }

    static bool check(const string &num) {
        if (num.find_last_of("+-") != string::npos && num.find_last_of("+-") != 0) {
            return false;
        }
        return num.find_last_not_of("0123456789") == 0 || num.find_last_not_of("0123456789") == string::npos;
    }

    void print() {
        cout << (isPositive ? '+' : '-');
        number.print();
    }

    int length() {
        return number.length();
    }

    BigInteger &trim() {
        while (number.head && number.head->data == 0) {
            removeHigh(0);
        }
        Node *&head = number.head;
        if (head == nullptr) {
            head = new Node(0);
            number.size++;
        }
        return *this;
    }

    int getLow(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        return number.get(length() - index - 1)->data;
    }

    int getHigh(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        return number.get(index)->data;
    }

    int removeLow(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        number.remove(length() - index - 1);
        return index;
    }

    int removeHigh(int index) {
        if (index < 0 || index > length() - 1) {
            return -1;
        }
        number.remove(index);
        return index;
    }

    int addHigh(int num) {
        if (num < 0 || num > 9) {
            return -1;
        }
        Node *&head = number.head;
        Node *_node = new Node(num);
        _node->next = head;
        head = _node;
        number.size++;
        return number.length();
    }

    int addLow(int num) {
        if (num < 0 || num > 9) {
            return -1;
        }
        Node *tail = number.get(number.length() - 1);
        tail->next = new Node(num);
        number.size++;
        return number.size;
    }

    BigInteger &operator+(BigInteger &integer) {
        if (this->isPositive && integer.isPositive) {
            BigInteger i0 = this->clone().trim();
            BigInteger i1 = integer.clone().trim();
            BigInteger result("0");
            int imp = 0;
            while (i0.length() > 0 && i1.length() > 0) {
                int sum = i0.getLow(0) + i1.getLow(0);
                result.addHigh((sum + imp) % 10);
                imp = (sum + imp) / 10;
                i0.removeLow(0);
                i1.removeLow(0);
            }
            if (i0.length() > 0) {
                addLast(i0, result, imp);
            } else if (i1.length() > 0) {
                addLast(i1, result, imp);
            } else {
                result.addHigh(imp);
            }
            result.removeLow(0);
            result.trim();
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

    BigInteger &operator-(BigInteger &integer) {
        if (this->isPositive && integer.isPositive) {
            BigInteger i0 = this->clone().trim();
            BigInteger i1 = integer.clone().trim();
            if (i0 > i1) {
                BigInteger result("0");
                int imp = 0;
                while (i0.length() > 0 && i1.length() > 0) {
                    int sub = i0.getLow(0) - i1.getLow(0);
                    if (sub >= 0) {
                        if ((sub + imp) < 0) {
                            result.addHigh(10 + sub + imp);
                            imp = -1;
                        } else {
                            result.addHigh(sub + imp);
                            imp = 0;
                        }
                    } else {
                        result.addHigh(10 + sub + imp);
                        imp = -1;
                    }
                    i0.removeLow(0);
                    i1.removeLow(0);
                }
                subLast(i0, result, imp);
                result.removeLow(0);
                result.trim();
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
            BigInteger& result = -(i1 + i0);
            return result;
        }
    }

    BigInteger &operator*(BigInteger &integer) {
        if (this->isPositive && integer.isPositive) {
            BigInteger i0 = this->clone().trim();
            BigInteger i1 = integer.clone().trim();
            BigInteger result("0");
            int size = i1.length();
            for (int i = 0; i < size; i++) {
                int e = i1.getLow(0);
                BigInteger temp = singleMulti(i0, e);
                temp.add0(i);
                result = result + temp;
                i1.removeLow(0);
            }
            result.trim();
            return result.clone();
        } else if (!this->isPositive && !integer.isPositive) {
            BigInteger i0 = -this->clone();
            BigInteger i1 = -integer.clone();
            BigInteger &result = i1 * i0;
            return result;
        } else if (this->isPositive && !integer.isPositive) {
            BigInteger i0 = this->clone();
            BigInteger i1 = -integer.clone();
            BigInteger& result = -(i0 * i1);
            return result;
        } else {
            BigInteger i0 = -this->clone();
            BigInteger i1 = integer.clone();
            BigInteger &result = -(i0 * i1);
            return result;
        }
    }

    BigInteger &operator*(int e) {
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

    BigInteger &operator/(BigInteger &integer) {
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
                    ent.addLow(i0.getHigh(0));
                    result.addLow(0);
                } else {
                    for (int i = 1; i <= 10; i++) {
                        if (ent < i1 * i) {
                            result.addLow(i - 1);
                            ent = ent - i1 * (i - 1);
                            ent.addLow(i0.getHigh(0));
                            break;
                        }
                    }
                }
                i0.removeHigh(0);
            }
            for (int i = 1; i <= 10; i++) {
                if (ent < i1 * i) {
                    result.addLow(i - 1);
                    break;
                }
            }
            result.trim();
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

    BigInteger &operator^(BigInteger &integer) {
        BigInteger int2("2");
        BigInteger int0("0");
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        if (i0.isPositive && i1.isPositive) {
            BigInteger result("1");
            while (i1 > int0) {
                if (i1.getLow(0) % 2 == 1) {
                    result = ((result.clone() * i0) % m);
                }
                i1 = i1 / int2;
                i0 = (i0 * i0) % m;
            }
            result.trim();
            return result.clone();
        } else {
            return int0.clone();
        }
    }

    BigInteger& operator%(int _m) {
        BigInteger& integer = this->clone();
        if (integer.length() <= _m) {
            return integer;
        } else {
            while (integer.length() > _m) {
                integer.removeHigh(0);
            }
            return integer;
        }
    }

    static BigInteger &singleMulti(BigInteger &integer, int e) {
        BigInteger result("0");
        BigInteger temp = integer.clone();
        int imp = 0;
        while (temp.length() > 0) {
            int mul = e * temp.getLow(0);
            result.addHigh((mul + imp) % 10);
            imp = (mul + imp) / 10;
            temp.removeLow(0);
        }
        result.addHigh(imp);
        result.removeLow(0);
        return result.clone();
    }

    void add0(int num) {
        for (int i = 0; i < num; i++) {
            addLow(0);
        }
    }

    static void addLast(BigInteger &last, BigInteger &result, int imp) {
        while (last.length() > 0) {
            int s = last.getLow(0);
            result.addHigh((s + imp) % 10);
            imp = (s + imp) / 10;
            last.removeLow(0);
        }
        result.addHigh(imp);
    }

    static void subLast(BigInteger &last, BigInteger &result, int imp) {
        while (last.length() > 0) {
            int sub = last.getLow(0);
            if ((sub + imp) < 0) {
                result.addHigh(10 + sub + imp);
                imp = -1;
            } else {
                result.addHigh(sub + imp);
                imp = 0;
            }
            last.removeLow(0);
        }
    }

    bool operator>(BigInteger &integer) {
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        if (i0.length() > i1.length()) {
            return true;
        } else if (i0.length() < i1.length()) {
            return false;
        } else {
            for (int i = 0; i < i0.length(); i++) {
                if (i0.getHigh(i) > i1.getHigh(i)) {
                    return true;
                } else if (i0.getHigh(i) < i1.getHigh(i)) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator<(BigInteger &integer) {
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        if (i0.length() < i1.length()) {
            return true;
        } else if (i0.length() > i1.length()) {
            return false;
        } else {
            for (int i = 0; i < i0.length(); i++) {
                if (i0.getHigh(i) < i1.getHigh(i)) {
                    return true;
                } else if (i0.getHigh(i) > i1.getHigh(i)) {
                    return false;
                }
            }
            return false;
        }
    }

    bool operator==(BigInteger &integer) {
        BigInteger i0 = this->clone().trim();
        BigInteger i1 = integer.clone().trim();
        if (i0.length() != i1.length()) {
            return false;
        } else {
            for (int i = 0; i < i0.length(); i++) {
                if (this->getHigh(i) != integer.getHigh(i)) {
                    return false;
                }
            }
            return true;
        }
    }

    BigInteger &clone() {
        Node *node = this->number.head;
        BigInteger& c = *new BigInteger("0");
        while (node != nullptr) {
            c.addLow(node->data);
            node = node->next;
        }
        c.isPositive = this->isPositive;
        c.trim();
        return c;
    }

    BigInteger &operator-() {
        this->isPositive = !this->isPositive;
        return *this;
    };

    static BigInteger& addMod(const string& integer0, const string& integer1, int _m) {
        return (*new BigInteger(integer0) + *new BigInteger(integer1)) % _m;
    }

    static BigInteger& subMod(const string& integer0, const string& integer1, int _m) {
        return (*new BigInteger(integer0) - *new BigInteger(integer1)) % _m;
    }

    static BigInteger& divideMod(const string& integer0, const string& integer1, int _m) {
        return (*new BigInteger(integer0) / *new BigInteger(integer1)) % _m;
    }

    static BigInteger& multiMod(const string& integer0, const string& integer1, int _m) {
        return (*new BigInteger(integer0) * *new BigInteger(integer1)) % _m;
    }

    static BigInteger& powMod(const string& integer0, const string& integer1, int _m) {
        BigInteger i0(integer0);
        BigInteger i1(integer1);
        BigInteger int0("0");
        BigInteger int2("2");
        if (i0.isPositive && i1.isPositive) {
            BigInteger result("1");
            i0 = i0 % _m;
            while (i1 > int0) {
                if (i1.getLow(0) % 2 == 1) {
                    result = (result * i0) % _m;
                }
                i1 = i1 / int2;
                i0 = (i0 * i0) % _m;
            }
            result.trim();
            return result.clone();
        } else {
            return int0.clone();
        }
    }
};