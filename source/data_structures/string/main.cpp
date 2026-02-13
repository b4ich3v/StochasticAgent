#include <iostream>
#include <sstream>
#include "String.h"

int main() {
    String a("Hello");
    String b("World");
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    String c = a + String(" ") + b;
    std::cout << "c = " << c << "\n";

    a += String("!!!");
    std::cout << "a after += = " << a << "\n";

    String copyC(c);
    std::cout << "copyC = " << copyC << "\n";

    String assign;
    assign = b;
    std::cout << "assign = " << assign << "\n";

    String moved(std::move(copyC));
    std::cout << "moved = " << moved << "\n";

    String movedAssign;
    movedAssign = std::move(assign);
    std::cout << "movedAssign = " << movedAssign << "\n";
    std::cout << "c[0] = " << c[0] << "\n";
    std::cout << "c[last] = " << c[c.getSize() - 1] << "\n";

    try {
        std::cout << c[c.getSize()] << "\n";
        std::cout << "ERROR: out of range should throw\n";
    } catch (const std::exception& e) {
        std::cout << "OK: out of range threw: " << e.what() << "\n";
    }

    try {
        String s("abc");
        s += s;
        std::cout << "ERROR: self append should throw, got: " << s << "\n";
    } catch (const std::exception& e) {
        std::cout << "OK: self append threw: " << e.what() << "\n";
    }

    std::stringstream ss("test123");
    String in1, in2;
    ss >> in1 >> in2;
    std::cout << "in1 = " << in1 << "\n";
    std::cout << "in2 = " << in2 << "\n";


    try {
        String empty("");
        std::cout << "empty = '" << empty << "' size=" << empty.getSize() << "\n";
    } catch (const std::exception& e) {
        std::cout << "empty ctor threw: " << e.what() << "\n";
    }

    try {
        const char* p = nullptr;
        String bad(p);
        std::cout << "ERROR: nullptr ctor should throw, got: " << bad << "\n";
    } catch (const std::exception& e) {
        std::cout << "OK: nullptr ctor threw: " << e.what() << "\n";
    }

    return 0;
}
