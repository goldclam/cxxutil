#include <iostream>
#include <cstring>

namespace swexam {
void cstring_exam () {
	std::cout << "[cstring_exam]" << std::endl;

	int len = 5;
	char d[len] = "0987654321";  // causes undefined behavior. writing past the bounds of the array. cxx11 compiler doesn't alert this as an error.
	char s[len] = "123";

	std::cout << "sizeof d: " << sizeof(d) << std::endl;
	memset(d, 0x00, sizeof(d));  //sizeof = number of byte in data type and array
	strncpy(d, s, sizeof(d));

	std::cout << "d: " << d << std::endl;
	std::cout << "s: " << s << std::endl;
}
} //namesapce swexam