#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Pair {
    int a_;
    string str_;
public:
    Pair(): a_(-1), str_("empty") {
       cout << "Default Pair(-1, 'empty') addr=" << this << endl;
    } 

    Pair(int a, string str): a_(a), str_(str) {
        cout << "Pair("<< a << ", " << str << ") addr=" << this << endl;
    }

    Pair(Pair& that): a_(that.a_), str_(that.str_ + " copy") {
        cout << "copy Pair from=" << &that << " to=" << this << endl;
    }
    // Pair(Pair&) = delete;

    // Pair& operator=(Pair& that) = delete;
    Pair& operator=(const Pair& that) {
        if(this == &that) {
            return *this;
        }
        cout << "Copy Assignment Pair from=" << &that << " to=" << this << endl;
        a_ = that.a_;
        str_ = that.str_ + " assigned";
        return *this;
    }

    Pair& operator=(Pair&& that) {
        if(this == &that) {
            return *this;
        }
        cout << "Move Assignment Pair from=" << &that << " to=" << this << endl;
        
        // a_ = std::move(that.a_);
        // that.a_ = -1;
        a_ = std::exchange(that.a_, -1);

        // str_ = std::move(that.str_);
        str_ = std::exchange(that.str_, "__moved__");
        return *this;
    }

    const int& a() const {
        return a_;
    }
    const string& str() const {
        return str_;
    }

    ~Pair() {
        cout << "~Pair("<< a_ << ", " << str_ << ") addr=" << this << endl;
    }
};

void copy_call(Pair p) {
    cout << p.a() << " " << p.str() << endl;
}

void ref_call(const Pair& p) {
    cout << p.a() << " " << p.str() << endl;
}

int main() {
    {
        Pair p(42, "Hello");
        copy_call(p);
    }
    cout << "======" << endl;
    {
        Pair p(42, "Hello");
        ref_call(p);
    }
    cout << "======" << endl;
    {
        Pair p(17, "World");
        Pair p2 = p;
        ref_call(p);
        ref_call(p2);
    }
    cout << "======" << endl;
    {
        const Pair p(99, "Buum");
        Pair p2;
        p2 = p;
        ref_call(p);
        ref_call(p2);
    }
    cout << "======" << endl;
    {
        Pair p(77, "I like to move it");
        Pair p2;
        p2 = std::move(p);
        ref_call(p);
        ref_call(p2);
    }
    cout << "======" << endl;
    Pair p2;
    return 0;
}