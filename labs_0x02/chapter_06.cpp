#include "chapter_06.h"

using namespace std;

clock_t function_6_1() { return clock(); }

char to_Upper(char c) {
    if (c >= 'a' && c <= 'z') c += 'A' - 'a';
    return c;
}

char to_Lower(char c) {
    if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
    return c;
}

int factorial() {
    static int factor = 1;
    static int value = 1;
    return (value *= (factor++));
}

double function_6_15(double x) {
    return 1.0;
}

double r = 1.0;

double* function_6_15_1() {
    return &r;
}

bool function_6_20(const std::vector<string>& v1, const std::vector<string>& v2) {
    return lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
}

int Class_6_1::sum;

Class_6_1::Class_6_1(int init) { sum = 0; }

int Class_6_1::operator()(int n) { sum += n; return sum; }

void Class_6_2::function_1() { cout << "Class_6_2::function_1().\n"; }

void Class_6_2_1::function_1() { cout << "Class_6_2_1::function_1().\n"; }

Class_6_15::Class_6_15() {}

double Class_6_15::getRadian() {
    /*
    const double* r = new double;
    *r =
    * */

    return r = double(rand() % 314) / double(100);
}

Generator_1::Generator_1(int start, int skip) : i(start), sk(skip) {}

int Generator_1::operator()() {
    int r = i;
    i += sk;
    return r;
}

Generator_2::Generator_2(int lim) : limit(lim) {}

int Generator_2::operator()() {
    while (true) {
        int i = int(std::rand()) % limit;
        if (used.find(i) == used.end()) {
            used.insert(i);
            return i;
        }
    }
}

const char* Generator_3::source = "abcdefghijk";

const int Generator_3::len = strlen(source);

char Generator_3::operator()() {
    return source[std::rand()% len];
}

bool BRand::operator ()() { return rand() % 2 == 0; }

void multipliers(int n, std::vector<int>& m) {
    m.clear();
    for (int i = 0; i <= n; i++) m.push_back(i);
    for (int i = 2; i <= n; ) {
        for (int j = 2; j*i <= n; j++) m[j*i] = 0;
        while (++i <= n && !m[i]);
    }
    vector<int>::iterator end = remove(m.begin(), m.end(), 0);
    m.erase(end, m.end());
}

void textToWords(std::string text, std::vector<string>& words) {
    int word = 0, space = 0;
    while ((space = text.find_first_of(" .,!?\0", word)) != string::npos && word < text.size()) {
        words.push_back(string(text, word, space-word));
        word = ++space;
    }
}

Class_6_13_1::Class_6_13_1(char i, int q, int v) : item(i), quantity(q), value(v) {}

char Class_6_13_1::getItem() const { return item; }

int Class_6_13_1::getQuantity() const { return quantity; }

void Class_6_13_1::setQuantity(int q) { quantity = q; }

int Class_6_13_1::getValue() const { return value; }

void Class_6_13_1::setValue(int v) { value = v; }

std::ostream& operator<<(std::ostream& os, const Class_6_13_1& value) {
    return os <<  "Item [quantity, value]: " << value.getItem() << "[" << value.getQuantity() << "," << value.getValue() << "]" << endl;
}

Class_6_13_1 genValues() {
    static char c = 'a';
    int q = rand() % 100;
    int v = rand() % 300;
    return Class_6_13_1(c++, q, v);
}

Class_6_13_2::Class_6_13_2() : quantity(0), value(0) {}

void Class_6_13_2::operator()(const Class_6_13_1& cl) {
    quantity += cl.getQuantity();
    value += cl.getQuantity() * cl.getValue();
}

std::ostream& operator<<(std::ostream& os, const Class_6_13_2 value) {
    return os << "Total [quantity, value]: [" << value.quantity << "," << value.value << "]" << endl;
}

std::ostream& operator<<(std::ostream& os, const Matrix<int>& value) {
    for (int i = 0; i < value.data.size(); i++) {
        for (int j = 0; j < value.data[i].size(); j++)
            cout << value.data[i][j] << " ";
        cout << endl;
    }
    return os;
}
