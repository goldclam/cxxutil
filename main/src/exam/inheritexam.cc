#include <iostream>

/*
class 파생클래스이름 : 접근제어지시자 기초클래스이름[, 접근제어지시자 기초클래스이름, ...] {
    // 파생 클래스 멤버 리스트
}
*/

class Base {
protected:
    std::string _name;

public:
    Base() {
        std::cout << typeid(this).name() << std::endl;
        _name = "Base()";
    }

    void print() {
        std::cout << "Base print::  class is " << _name << std::endl;
    }

    virtual void vprint() {
        std::cout << "Base vprint:: class is " << _name << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << typeid(this).name() << std::endl;
        _name = "Derived()";
    }

    void print() {
        std::cout << "Derived print::  class is " << _name << std::endl;
    }

    void vprint() {
        std::cout << "Derived vprint:: class is " << _name << std::endl;
    }
};

void inheritexam() {
    std::cout << "Base pointer initialize! " << std::endl;
    Base* b = new Base();

    std::cout << "Derived pointer initialize! " << std::endl;
    Derived* d= new Derived();

    std::cout << "Upcasting pointer initialize! " << std::endl;
    Base* upcast = new Derived();

    b->print();
    d->print();
    upcast->print();

    b->vprint();
    d->vprint();
    upcast->vprint();
}