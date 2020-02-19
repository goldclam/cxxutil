#include <iostream>
#include "pointerexam.h"

void pointerexam() {

    char* sp1;
    char** sp2;
    char* sp3[2];
    char sp4[2][2];

    int ip1;
    int* ip2;
    int ip3[2];
    int* ip4[2];

    sprint(&sp1);    // OK
    sprint(sp2);    // OK
    sprint(sp3);    // OK
//    sprint(sp4);    // Compile Error:: char (*)[2]   incompatible char**

    iprint(&ip1);    // OK
//    iprint(ip2);    // Runtime Error
    iprint(ip3);    
//    iprint(ip4);    // Compiel Error:: cannot convert ‘int**’ to ‘int*’

}

void sprint(OUT char** p) {
    *p = "thist is string pointer";
    std::clog << p << std::endl;
    std::clog << *p << std::endl << std::endl;
}

void iprint(OUT int* p) {
    *p = 7;
    std::clog << p << std::endl;
    std::clog << *p << std::endl << std::endl;
}
