#include<iostream>
using namespace std;

class Joker {
public:
    Joker();
    Joker(const Joker& rhs);
    Joker& operator=(const Joker& rhs);
    bool validate1(Joker rhs);
    bool validate2(const Joker& rhs);
};

Joker::Joker() {
    cout << "call baisc constructor" << endl;
}

Joker::Joker(const Joker& rhs) {
    cout << "call copy constructor" << endl;
}

Joker& Joker::operator=(const Joker& rhs) {
    cout << "call copy operator=" << endl;
    return *this;
}

bool Joker::validate1(Joker joker) {
    cout << "validate call by value" << endl;
    return true;
}

bool Joker::validate2(const Joker& joker) {
    cout << "validate call by value reference" << endl;
    return true;
}

int copyconsexam()
{
    // basic constructor
    cout << endl << ">>>> basic constructor test <<<<" << endl;
    Joker jk;

    // copy constructor
    cout << endl << ">>>> copy constructor test 1<<<<" << endl;
    Joker jk2(jk);

    cout << endl << ">>>> copy constructor test 2 <<<<" << endl;
    Joker jk3 = jk;

    // copy operator
    cout << endl << ">>>> copy assign operator test <<<<" << endl;
    jk2 = jk;

    // call method with copy constructor
    cout << endl << ">>>> call by value test <<<<" << endl;
    jk.validate1(jk2);

    cout << endl << ">>>> call by value reference test <<<<" << endl;
    jk.validate2(jk2);

    return 0;
}