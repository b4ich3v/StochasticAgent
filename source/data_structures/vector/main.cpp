#include <iostream>
#include <sstream>
#include <string>
#include "Vector.hpp"

int main() {
    Vector<int> v;
    v.push(10);
    v.push(20);
    v.push(30);
    std::cout << "v = " << v << "\n";

    std::cout << "v[0] = " << v[0] << "\n";
    std::cout << "v[2] = " << v[2] << "\n";

    v.pop();
    std::cout << "after pop, v = " << v << "\n";

    Vector<int> big;
    for (int i = 0; i < 100; i++) big.push(i);
    std::cout << "big size = " << big.getSize() << ", capacity = " << big.getCapacity() << "\n";
    std::cout << "big[0]=" << big[0] << ", big[99]=" << big[99] << "\n";

    Vector<int> copy = big;
    std::cout << "copy size = " << copy.getSize() << ", capacity = " << copy.getCapacity() << "\n";
    std::cout << "copy[50] = " << copy[50] << "\n";

    Vector<int> moved = std::move(copy);
    std::cout << "moved size = " << moved.getSize() << ", capacity = " << moved.getCapacity() << "\n";
    std::cout << "moved[50] = " << moved[50] << "\n";

    Vector<int> a;
    a = moved;
    std::cout << "a(after copy=) size = " << a.getSize() << ", capacity = " << a.getCapacity() << "\n";
    std::cout << "a[10] = " << a[10] << "\n";

    Vector<int> b;
    b = std::move(a);
    std::cout << "b(after move=) size = " << b.getSize() << ", capacity = " << b.getCapacity() << "\n";
    std::cout << "b[10] = " << b[10] << "\n";

    std::stringstream ss;
    ss << "5 7 8 9 10 11";
    Vector<int> fromStream;
    ss >> fromStream;
    std::cout << "fromStream = " << fromStream << "\n";
    std::cout << "fromStream size = " << fromStream.getSize() << ", capacity = " << fromStream.getCapacity() << "\n";

    Vector<int> empty;
    try {
        empty.pop();
        std::cout << "ERROR: empty.pop() should throw\n";
    } catch (const std::exception& e) {
        std::cout << "OK: empty.pop() threw: " << e.what() << "\n";
    }

    try {
        std::cout << empty[0] << "\n";
        std::cout << "ERROR: empty[0] should throw\n";
    } catch (const std::exception& e) {
        std::cout << "OK: empty[0] threw: " << e.what() << "\n";
    }

    try {
        std::cout << v[999] << "\n";
        std::cout << "ERROR: v[999] should throw\n";
    } catch (const std::exception& e) {
        std::cout << "OK: v[999] threw: " << e.what() << "\n";
    }

    return 0;
}
