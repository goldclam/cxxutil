#include <iostream>

class MyClass { 
    int memberv;
    const int constglobal = 0; // const 변수는 선언과 동시에 초기화(initialized) 되어야한다.

    public: MyClass() {
        memberv = 0; // normal 변수는 생성자에서 초기화 가능
    }

    //함수에 적용된 const는 멤버 변수 변경 불가를 의미
    void constf() const { 
        //memberv = 1; // normal 멤버 변수 임에도 값 변경시 컴파일 에러 발생!
        std::cout << "constf: memberv : " << memberv << std::endl;

        //constglobal = 1; // const 변수는 어디서든  수정 불가
        std::cout << "constf: constglobal : " << constglobal << std::endl;\

        int internal = 0;
        internal = 1; // 로컬 변수 변경 가능
        std::cout << "constf: internal : " << internal << std::endl;
    }

    void f(const int constparam) {
        memberv = 2; // normal 변수 변경 가능
        std::cout << "f: memberv: " << memberv << std::endl;

        //constglobal = 2; // const 변수는 어디서든 수정 불가
        std::cout << "f: constglobal : " << constglobal << std::endl;

        //constparam = 2; // const parameter 변경 불가
        std::cout << "f: constparam : " << constparam << std::endl;
    }
};

void constexam() {
    MyClass myclass;
    myclass.constf();
    myclass.f(0);
}