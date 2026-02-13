#include <iostream>
#include "BitSet.h"

int main() {
    BitSet set1;
    set1.addNumber(13);
    set1.addNumber(131);
    set1.addNumber(1);

    BitSet set2;
    set2.addNumber(11);
    set2.addNumber(11);
    set2.addNumber(11);

    std::cout << "set1 = " << set1 << std::endl;
    std::cout << "set2 = " << set2 << std::endl;

    std::cout << "set1 | set2 = " << (set1 | set2) << std::endl;
    std::cout << "set1 & set2 = " << (set1 & set2) << std::endl;

    BitSet diff = set1;
    diff %= set2;
    std::cout << "set1 % set2 = " << diff << std::endl;
    
    std::cout << "set1 has 131? " << (set1.hasNumber(131) ? "yes" : "no") << std::endl;
    std::cout << "set2 has 13? "  << (set2.hasNumber(13)  ? "yes" : "no") << std::endl;

    set1.removeNumber(13);
    std::cout << "set1 after remove 13 = " << set1 << std::endl;

    return 0;
}
