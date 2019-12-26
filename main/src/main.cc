#include <iostream>
#include "util/time.h"
#include "test/chronotest.h"

int main() {

	std::cout << util::time::GetTickCount() << std::endl;
	chronotest();

    return 0;
}