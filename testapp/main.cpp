#include <iostream>
#include "..\dll\rrspy.h"

int main() {
    int abc = 123;
    int def = abc * 1000;
    int ghi = abc + def;

    std::cout << ghi << std::endl;

    DoIt();

    return 0;
}
