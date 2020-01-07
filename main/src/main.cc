#include <iostream>
#include "util/time.h"
#include "exam/chronoexam.h"

int main() {

	std::cout << util::time::GetTickCount() << std::endl;
	chrono_exam();

    return 0;
}